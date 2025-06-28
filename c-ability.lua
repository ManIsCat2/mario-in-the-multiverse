local sCollectAbilityHitbox = {
    interactType = INTERACT_STAR_OR_KEY,
    downOffset = 0,
    damageOrCoinValue = 0,
    health = 0,
    numLootCoins = 0,
    radius = 80,
    height = 80,
    hurtboxRadius = 0,
    hurtboxHeight = 0,
}

UNLOCK_ABILITIES_DEBUG = true
local toZeroMeter = false
local lastAbility = false

function bhv_ability_init(o)
    o.oBehParams = (12 << 24) | (o.oBehParams2ndByte << 16)
    network_init_object(o, true, { "oAction", "oBehParams2ndByte" })
end

function bhv_ability(o)
    if o.oAction == 0 then
        if save_file_check_ability_unlocked(o.oBehParams2ndByte) then
            -- When debugging, you should always be able to test ability collection
            if UNLOCK_ABILITIES_DEBUG then
                o.oAction = 1
                obj_set_hitbox(o, sCollectAbilityHitbox)
            else
                cur_obj_hide()
                o.oAction = 2
            end
        else
            o.oAction = 1
            obj_set_hitbox(o, sCollectAbilityHitbox)
        end
    elseif o.oAction == 1 then
        if obj_check_hitbox_overlap(o, nearest_player_to_object(o)) then
            --save_file_unlock_song(SEQ_MITM_GET_ABILITY)

            cur_obj_hide()
            if nearest_mario_state_to_object(o).playerIndex == 0 then
                ability_util.display = true
                ability_util.str = ability_struct[o.oBehParams2ndByte].string
                ability_util.seq = true
            end
            for i = 0, 3 do
                if ability_slot[i] == ABILITY_NONE then
                    ability_slot[i] = o.oBehParams2ndByte

                    break
                end
            end
            --gGlobalSyncTable.ability_slot0 = o.oBehParams2ndByte
            if o.oBehParams2ndByte ~= ABILITY_MARBLE and nearest_mario_state_to_object(o).playerIndex == 0 then -- hamsterball is a weird one
                change_ability(o.oBehParams2ndByte)
                save_file_set_ability_dpad()
            end
            o.oAction = 2
        end
    end
end

local function save_abilities()
    local currSave = get_current_save_file_num() - 1
    --reduce stress
    if get_global_timer() % 37 ~= 0 then return end
    save_global_coins()
    if network_is_server() then
        --save_file_set_ability_dpad()
        mod_storage_save_number("abilities" .. (currSave), gGlobalSyncTable.abilities)
    end
end

hook_event(HOOK_UPDATE, save_abilities)

local function control_ability_dpad(m)
    if m.playerIndex ~= 0 then return end
    local force_marble = false
    if ((not force_marble) and (m.action ~= ACT_BUBBLE_HAT_JUMP) and (m.action ~= ACT_SQUID)) then
        local gPlayer1Controller = m.controller
        local picked_ability = -1

        if (gPlayer1Controller.buttonPressed & U_JPAD) ~= 0 then
            picked_ability = 0
        end
        if (gPlayer1Controller.buttonPressed & R_JPAD) ~= 0 then
            picked_ability = 1
        end
        if (gPlayer1Controller.buttonPressed & D_JPAD) ~= 0 then
            picked_ability = 2
        end
        if (gPlayer1Controller.buttonPressed & L_JPAD) ~= 0 then
            picked_ability = 3
        end
        if (m.action & ACT_GROUP_MASK) ~= ACT_GROUP_CUTSCENE then
            if picked_ability > -1 then
                if not isPaused then
                    if check_if_swap_ability_allowed(m) then
                        -- Animate image on DPad HUD
                        ability_y_offset[picked_ability] = 5
                        ability_gravity[picked_ability] = 2

                        change_ability(ability_slot[picked_ability])

                        -- Equip Sound Effect
                        if ability_slot[picked_ability] == ABILITY_AKU then
                            audio_stream_play(SOUND_ABILITY_AKU_AKU, false, 1)
                        elseif ability_slot[picked_ability] == ABILITY_KNIGHT then
                            -- play_sound(SOUND_ABILITY_KNIGHT_EQUIP, gGlobalSoundSource)
                        elseif ability_slot[picked_ability] == ABILITY_E_SHOTGUN then
                            --  play_sound(SOUND_MITM_ABILITY_E_SHOTGUN_RACK, gGlobalSoundSource)
                        elseif ability_slot[picked_ability] == ABILITY_NONE then
                            -- Do nothing
                        else
                            play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource)
                        end
                    else
                        play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource)
                    end
                end
            end
        end
    end
end
hook_event(HOOK_MARIO_UPDATE, control_ability_dpad)

local thrownCutter = false

---@param m MarioState
local function ability_functions_update(m)
    local f = gPlayerSyncTable[m.playerIndex]
    if m.playerIndex == 0 then
        if m.action == ACT_PUNCHING or m.action == ACT_MOVE_PUNCHING or m.action == ACT_JUMP_KICK then
            if f.abilityId == ABILITY_CUTTER and not thrownCutter then
                spawn_object_relative2(0, 0, 100, 0, m.marioObj, MODEL_CUTTER_BLADE, bhvCutterBlade);
                thrownCutter = true
            end
        else
            thrownCutter = false
        end
        if m.action == ACT_JUMP or
            m.action == ACT_DOUBLE_JUMP or
            m.action == ACT_TRIPLE_JUMP or
            m.action == ACT_BACKFLIP or
            m.action == ACT_FREEFALL or
            m.action == ACT_HOLD_JUMP or
            m.action == ACT_SIDE_FLIP or
            m.action == ACT_WALL_KICK_AIR or
            m.action == ACT_LONG_JUMP or
            m.action == ACT_FORWARD_ROLLOUT or
            m.action == ACT_BACKWARD_ROLLOUT or
            m.action == ACT_JUMP_KICK then
            m.actionTimer = m.actionTimer + 1

            if (using_ability(m, ABILITY_BUBBLE_HAT) and m.actionTimer > 1 and m.input & INPUT_A_PRESSED ~= 0) then
                set_mario_action(m, ACT_BUBBLE_HAT_JUMP, 0);
            end
        end

        local aku_invincibility = gPlayerSyncTable[0].aku_invincibility
        local aku_recharge = gPlayerSyncTable[0].aku_recharge

        if not using_ability(m, ABILITY_AKU) then
            if aku_invincibility ~= 0 then
                gPlayerSyncTable[0].aku_invincibility = 0
                -- stop_cap_music()
            end
        else
            if (m.controller.buttonDown & L_TRIG) ~= 0 and aku_invincibility == 0 and aku_recharge >= 300 and gGlobalSyncTable.coins >= 10 and (m.action & ACT_GROUP_MASK) ~= ACT_GROUP_CUTSCENE then
                gPlayerSyncTable[0].aku_invincibility = 300
                gPlayerSyncTable[0].aku_recharge = 0
                cool_down_ability(ABILITY_AKU)
                gGlobalSyncTable.coins = gGlobalSyncTable.coins - 10
                --djui_chat_message_create(""..ability_cooldown_flags)
            end

            -- djui_chat_message_create(""..aku_recharge)

            if aku_invincibility > 0 then
                abilityMeter = math.min(math.floor((aku_invincibility / 300.0) * 8.0 + 1), 8)
                abilityMeterStyle = METER_STYLE_AKU
                toZeroMeter = true
            else
                if aku_recharge < 300 then
                    abilityMeter = math.min(math.floor((aku_recharge / 300.0) * 8.0 + 1), 8)
                    abilityMeterStyle = METER_STYLE_AKU_RECHARGE
                    ability_ready(ABILITY_AKU)
                end
            end
        end

        if aku_invincibility > 0 then
            local sparkleObj = spawn_object(m.marioObj, E_MODEL_SPARKLES, id_bhvCoinSparkles)
            sparkleObj.oPosX = sparkleObj.oPosX + random_float() * 50.0 - 25.0
            sparkleObj.oPosY = sparkleObj.oPosY + random_float() * 100.0
            sparkleObj.oPosZ = sparkleObj.oPosZ + random_float() * 50.0 - 25.0

            gPlayerSyncTable[0].aku_invincibility = gPlayerSyncTable[0].aku_invincibility - 1
        else
            if aku_recharge < 300 then
                gPlayerSyncTable[0].aku_recharge = gPlayerSyncTable[0].aku_recharge + 1
            else
                abilityMeter = -1
            end
        end


        --DONT ADD MORE
        if (toZeroMeter) then --/ Reset ability meter if it's not set past this point
            --  abilityMeter = 0;
            toZeroMeter = false;
        else
            --== abilityMeter = -1;
        end

        if (lastAbility ~= gPlayerSyncTable[0].abilityId) then
            abilityMeter = -1;
            lastAbility = gPlayerSyncTable[0].abilityId
            for k = 0, 18 do
                if ability_is_cooling_down(k) then
                    ability_ready(k)
                end
            end
        end

        if (m.controller.buttonPressed & L_TRIG) ~= 0 then
            if ((m.action & ACT_GROUP_MASK) ~= ACT_GROUP_CUTSCENE and using_ability(m, ABILITY_SHOCK_ROCKET) and not m.marioObj.oBooParentBigBoo) then
                if (is_2d_area()) then
                    -- shock rocket cannot be used in 2d areas
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                else
                    m.marioObj.oBooParentBigBoo = spawn_object_relative(0, 0, 100, 0, m.marioObj, MODEL_SHOCK_ROCKET,
                        bhvShockRocket);
                end
            end
        end

        if (using_ability(m, ABILITY_SHOCK_ROCKET)) then
            if (m.marioObj.oBooParentBigBoo and m.marioObj.oBooParentBigBoo.behavior == get_behavior_from_id(bhvShockRocket)) then
                local rocket = m.marioObj.oBooParentBigBoo

                if (rocket.oAction == SHOCK_ROCKET_ACT_MOVE) then
                    abilityMeterStyle = METER_STYLE_ROCKET;
                    abilityMeter = math.min(math.floor(((300 - rocket.oTimer) / 300.0) * 8.0) + 1, 8);
                    -- djui_chat_message_create(""..abilityMeter)
                    -- toZeroMeter = TRUE;
                    m.freeze = 1
                end
            end
        end

        if (using_ability(m, ABILITY_GADGET_WATCH)) then
            local aim = m.marioObj.oBooParentBigBoo
            if (not aim) then
                m.marioObj.oBooParentBigBoo = spawn_object(m.marioObj, MODEL_WATCH_AIM, bhvGadgetAim);
            end
        else
            local aim = m.marioObj.oBooParentBigBoo

            if (aim and aim.behavior == get_behavior_from_id(bhvGadgetAim)) then
                obj_mark_for_deletion(aim);
                m.marioObj.oBooParentBigBoo = nil
            end
        end
    end

    if m.action ~= ACT_SQUID then
        if m.playerIndex == 0 then
            if gPlayerSyncTable[0].modelId == MODEL_SQUID then
                gPlayerSyncTable[0].modelId = nil
            end
        end

        if smlua_anim_util_get_current_animation_name(m.marioObj) == "mario_anim_squid" then
            set_mario_animation(m, MARIO_ANIM_A_POSE)
        end
    end

    if using_ability(m, ABILITY_SQUID) then
        if (m.controller.buttonPressed & L_TRIG) ~= 0 and m.action ~= ACT_BUBBLED then
            spawn_mist_particles()

            if m.action == ACT_SQUID then
                if m.playerIndex == 0 then
                    gPlayerSyncTable[0].modelId = nil
                    set_mario_action(m, ACT_IDLE, 0)
                    --[[m.marioObj.header.gfx.node.flags = m.marioObj.header.gfx.node.flags |
                    GRAPH_RENDER_INVISIBLE
                    --make_mario_visible_again_after_this_frame = true]]
                end
            else
                if m.playerIndex == 0 then
                    gPlayerSyncTable[0].modelId = MODEL_SQUID
                    set_mario_action(m, ACT_SQUID, 0)
                end
                --[[m.marioObj.header.gfx.node.flags = m.marioObj.header.gfx.node.flags |
                    GRAPH_RENDER_INVISIBLE
                    --make_mario_visible_again_after_this_frame = true]]
            end
        end
    end
end

---@param m MarioState
local function disable_squid_geometry(m)
    if m.playerIndex == 0 then
        if m.floor and m.floor.type == SURFACE_TOXIC_INK then
            m.input = m.input | INPUT_IN_POISON_GAS
        end
        if using_ability(m, ABILITY_SQUID) and m.action == ACT_SQUID then
            m.floorHeight, m.floor = find_floor_height(m.pos.x, m.pos.y, m.pos.z),
                collision_find_floor(m.pos.x, m.pos.y, m.pos.z)

            -- If Mario is OOB, move his position to his graphical position (which was not updated)
            -- and check for the floor there.
            -- This can cause errant behavior when combined with astral projection,
            -- since the graphical position was not Mario's previous location.
            if m.floor == nil then
                vec3f_copy(m.pos, m.marioObj.header.gfx.pos)
                m.floorHeight, m.floor = find_floor_height(m.pos.x, m.pos.y, m.pos.z),
                    collision_find_floor(m.pos.x, m.pos.y, m.pos.z)
            end

            m.ceilHeight = find_ceil_height(m.pos.x, m.pos.y, m.pos.z)
            gasLevel = find_poison_gas_level(m.pos.x, m.pos.z)
            m.waterLevel = find_water_level(m.pos.x, m.pos.z)

            if m.floor ~= nil then
                m.floorAngle = atan2s(m.floor.normal.z, m.floor.normal.x)
                m.terrainSoundAddend = mario_get_terrain_sound_addend(m)

                if (m.pos.y > m.waterLevel - 40) and mario_floor_is_slippery(m) ~= 0 then
                    m.input = m.input | INPUT_ABOVE_SLIDE
                end

                if ((m.floor.flags & SURFACE_FLAG_DYNAMIC) ~= 0) or (m.ceil and (m.ceil.flags & SURFACE_FLAG_DYNAMIC) ~= 0) then
                    ceilToFloorDist = m.ceilHeight - m.floorHeight

                    if (0.0 <= ceilToFloorDist) and (ceilToFloorDist <= 150.0) then
                        m.input = m.input | INPUT_SQUISHED
                    end
                end

                if m.pos.y > m.floorHeight + 100.0 then
                    m.input = m.input | INPUT_OFF_FLOOR
                end

                if m.pos.y < (m.waterLevel - 10) then
                    m.input = m.input | INPUT_IN_WATER
                end
            else
                vec3f_set(m.pos, m.spawnInfo.startPos.x, m.spawnInfo.startPos.y, m.spawnInfo.startPos.z)
                m.faceAngle.y = m.spawnInfo.startAngle.y
                local floor = nil
                floor = collision_find_floor(m.pos.x, m.pos.y, m.pos.z)
                if floor == nil then
                    level_trigger_warp(m, WARP_OP_DEATH)
                end
            end

            return false
        end
    end
end

hook_event(HOOK_OBJECT_SET_MODEL, function(o)
    if obj_has_behavior_id(o, id_bhvMario) ~= 0 then
        local i = network_local_index_from_global(o.globalPlayerIndex)

        if charSelect then
            local setModel = gPlayerSyncTable[i].modelId
            local playerCh = charSelect.character_get_current_number(i)
            local chtable = charSelect.character_get_full_table()
            if not setModel then
                setModel = chtable[playerCh][chtable[playerCh].currAlt or 1].ogModel
            end
            if obj_has_model_extended(o, setModel) == 0 then
                charSelect.character_edit_costume(playerCh, chtable[playerCh] and chtable[playerCh].currAlt or 1, nil,
                    nil, nil, nil,
                    setModel, nil, nil,
                    nil)
            end
        else
            if gPlayerSyncTable[i].modelId ~= nil and obj_has_model_extended(o, gPlayerSyncTable[i].modelId) == 0 then
                obj_set_model_extended(o, gPlayerSyncTable[i].modelId)
            end
        end

        -- gPlayerSyncTable[i].modelId = nil
    end
end)

local function interact_ability_star(m, obj, t)
    if obj_has_behavior_id(obj, bhvAbilityUnlock) ~= 0 then
        -- ability

        save_file_unlock_ability(obj.oBehParams2ndByte)

        --starGrabAction = ACT_ABILITY_DANCE
        if (m.action & ACT_FLAG_AIR) ~= 0 then
            --starGrabAction = ACT_FALL_AFTER_STAR_GRAB
            -- m.actionArg = 2
        end
        --ability_get_confirm = false
    elseif obj_has_behavior_id(obj, bhvCollectablePainting) ~= 0 then
        --[[painting unlock
        local slot = gCurrSaveFileNum - 1
        local paintingByte = obj.oBehParams2ndByte
        gSaveBuffer.files[slot][1].paintings_unlocked =
            gSaveBuffer.files[slot][1].paintings_unlocked | (1 << paintingByte)
        gSaveFileModified = true]]
    else
        --[[ if not level_in_dream_comet_mode() then
            -- power star
            p_rank_stars = p_rank_stars + 1
            save_file_collect_star_or_key(m.numCoins, starIndex)
            m.numStars = save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1)
            ability_get_confirm = true
        else
            -- dream catalyst
            set_dream_star(obj.oBehParams2ndByte)
            m.numDreamCatalysts = get_dream_star_count()
        end]]
    end
end

local function celeb_star_override(o)
    local mario = nearest_mario_state_to_object(o)
    local usobj = mario.usedObj
    if usobj then
        if obj_has_behavior_id(usobj, bhvAbilityUnlock) ~= 0 then
            obj_set_model_extended(o, MODEL_ABILITY)
            o.oBehParams2ndByte = usobj.oBehParams2ndByte
        elseif obj_has_behavior_id(usobj, bhvCollectablePainting) ~= 0 then
            obj_set_model_extended(o, MODEL_PAINTING)
            o.oBehParams2ndByte = usobj.oBehParams2ndByte
        end
    end
end

local function ability_override_sound(p, s)
    if s == SEQ_EVENT_CUTSCENE_COLLECT_STAR then
        if ability_util.seq then
            ability_util.seq = false
            return 0x50
        end
    end
end

local function ability_override_int(m, o, t)
    if gPlayerSyncTable[m.playerIndex].aku_recharge == 0 and using_ability(m, ABILITY_AKU) then
        if t == INTERACT_FLAME or t == INTERACT_BULLY or t == INTERACT_HIT_FROM_BELOW or t == INTERACT_BOUNCE_TOP or t == INTERACT_DAMAGE then
            --  djui_chat_message_create("shit")
            return false
        end
    end
end

local function ability_override_hazard(m, s)
    if gPlayerSyncTable[m.playerIndex].aku_recharge == 0 and using_ability(m, ABILITY_AKU) then
        if s == HAZARD_TYPE_LAVA_FLOOR then
            return false
        end
    end
end

local function unfuck_ability_on_die()
    gPlayerSyncTable[0].aku_invincibility = 0
    gPlayerSyncTable[0].aku_recharge = 300

    for k = 0, 18 do
        if ability_is_cooling_down(k) then
            ability_ready(k)
        end
    end
end

hook_behavior(id_bhvCelebrationStar, OBJ_LIST_DEFAULT, false, nil, celeb_star_override)

hook_event(HOOK_ON_SEQ_LOAD, ability_override_sound)
hook_event(HOOK_ON_INTERACT, interact_ability_star)
hook_event(HOOK_ALLOW_INTERACT, ability_override_int)
hook_event(HOOK_ALLOW_HAZARD_SURFACE, ability_override_hazard)
hook_event(HOOK_MARIO_UPDATE, ability_functions_update)
hook_event(HOOK_MARIO_OVERRIDE_GEOMETRY_INPUTS, disable_squid_geometry)
hook_event(HOOK_ON_DEATH, unfuck_ability_on_die)
hook_event(HOOK_ON_WARP, unfuck_ability_on_die)
