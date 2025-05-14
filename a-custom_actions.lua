ACT_CUTSCENE_CONTROLLED = allocate_mario_action(ACT_GROUP_CUTSCENE)
ACT_ENTER_HUB_PIPE = allocate_mario_action(ACT_GROUP_CUTSCENE)
ACT_CUTTER_THROW_AIR = allocate_mario_action(ACT_GROUP_AIRBORNE)
ACT_CUTTER_DASH = allocate_mario_action(ACT_GROUP_MOVING)

local function act_cutscene_controlled(m)
    vec3f_copy(m.marioObj.header.gfx.pos, m.pos)
    vec3s_set(m.marioObj.header.gfx.angle, 0, m.faceAngle.y, 0)
    return 0
end

local function act_enter_hub_pipe(m)
    local gPlayer1Controller = m.controller
    set_mario_animation(m, MARIO_ANIM_A_POSE)
    vec3f_copy(m.marioObj.header.gfx.pos, m.pos)
    vec3s_set(m.marioObj.header.gfx.angle, 0, m.faceAngle.y, 0)
    m.pos.x = approach_f32_asymptotic(m.pos.x, m.interactObj.oPosX, 0.1)
    m.pos.z = approach_f32_asymptotic(m.pos.z, m.interactObj.oPosZ, 0.1)

    if m.actionState == 0 then
        m.pos.y = approach_f32_asymptotic(m.pos.y, m.interactObj.oPosY + 300.0, 0.1)

        if (gPlayer1Controller.buttonPressed & B_BUTTON) ~= 0 then
            m.interactObj.oAction = 2
            set_mario_action(m, ACT_IDLE, 0)
        end

        if (gPlayer1Controller.buttonPressed & A_BUTTON) ~= 0 then
            if m.interactObj.oAction == 3 then
                play_sound(SOUND_MENU_ENTER_PIPE, m.marioObj.header.gfx.cameraToObject)
                m.actionState = 1
                m.interactObj.oAction = 4
            else
                play_sound(SOUND_MENU_CAMERA_BUZZ, m.marioObj.header.gfx.cameraToObject)
            end
        end

        --[[if (gPlayer1Controller.buttonPressed & Z_TRIG) ~= 0 and dream_comet_unlocked() then
            play_sound(SOUND_MENU_CLICK_CHANGE_VIEW, gGlobalSoundSource)
            dream_comet_enabled = not dream_comet_enabled
        end]]
    else
        m.pos.y = approach_f32_asymptotic(m.pos.y, m.interactObj.oPosY + 60.0, 0.1)
        m.actionTimer = m.actionTimer + 1
        if m.actionTimer > 20 then
            if m.playerIndex == 0 then
                if gNetworkPlayers[0].currLevelNum == LEVEL_CASTLE then
                    -- Enter a level
                    warp_to_warpnode(get_hub_level(m.interactObj.oBehParams2ndByte),
                        get_hub_area(m.interactObj.oBehParams2ndByte), 0, 0x0A)
                else
                    -- Exit a level
                    warp_to_warpnode(LEVEL_CASTLE, 0x01, 0, get_hub_return_id(hub_level_current_index))
                end
            end
        end
    end

    return 0
end

local function act_cutter_throw_air(m)
    if m.actionState == 0 then
        play_sound_if_no_flag(m, SOUND_MARIO_PUNCH_HOO, MARIO_ACTION_SOUND_PLAYED)
        m.marioObj.header.gfx.animInfo.animID = -1
        set_mario_animation(m, MARIO_ANIM_FIRST_PUNCH)
        m.actionState = 1
    end

    local animFrame = m.marioObj.header.gfx.animInfo.animFrame

    if animFrame == 0 then
        m.marioBodyState.punchState = ((2 << 6) | 0x6)
    end

    if animFrame >= 0 and animFrame < 8 then
        m.flags = m.flags | MARIO_KICKING
    end

    if m.actionTimer == 3 then
        spawn_object_relative(0, 0, 100, 0, m.marioObj, MODEL_CUTTER_BLADE, bhvCutterBlade)
    end

    m.actionTimer = m.actionTimer + 1
    update_air_without_turn(m)

    local stepResult = perform_air_step(m, 0)
    if stepResult == AIR_STEP_LANDED then
        if check_fall_damage_or_get_stuck(m, ACT_HARD_BACKWARD_GROUND_KB) == 0 then
            set_mario_action(m, ACT_FREEFALL_LAND, 0)
        end
    elseif stepResult == AIR_STEP_HIT_WALL then
        mario_set_forward_vel(m, 0.0)
    end

    return false
end

local function act_cutter_dash(m)
    if (m.input & INPUT_A_PRESSED) ~= 0 then
        --#if ENABLE_RUMBLE
        queue_rumble_data(5, 80)
        --#endif
        m.forwardVel = (m.forwardVel >= 0) and 45.0 or -45.0
        m.flags = m.flags & (~MARIO_PUNCHING)
        return set_jumping_action(m, ACT_FORWARD_ROLLOUT, 0)
    end

    --gSPDisplayList(gfx_ability_hand[0], cutter_hand_right_hand_open_mesh_layer_1)
    -- gSPEndDisplayList(gfx_ability_hand[1])

    if m.actionTimer == 0 then
        set_custom_mario_animation_with_accel(m, 5, 0x30000, "mario_anim_cutter_dash")
    end

    if fb_bowser_phase ~= 4 then
        if m.forwardVel < 10.0 then
            return set_mario_action(m, ACT_WALKING, 0)
        end
    else
        if m.actionTimer > 15 then
            return set_mario_action(m, ACT_WALKING, 0)
        end
    end

    if m.actionTimer < 5 then
        m.forwardVel = 20 * m.actionTimer
    else
        m.forwardVel = 90.0
    end

    m.flags = m.flags | MARIO_PUNCHING

    common_slide_action(m, ACT_WALKING, ACT_FREEFALL, m.marioObj.header.gfx.animInfo.animID)
    update_sliding(m, 10.0)

    local stepResult = perform_ground_step(m)
    if stepResult == GROUND_STEP_LEFT_GROUND then
        set_mario_action(m, ACT_FREEFALL, 2)
    elseif stepResult == GROUND_STEP_HIT_WALL then
        mario_bonk_reflection(m, 1)
        m.particleFlags = m.particleFlags | PARTICLE_VERTICAL_STAR
        set_mario_action(m, ACT_BACKWARD_GROUND_KB, 0)
    end

    play_sound(SOUND_MOVING_TERRAIN_SLIDE + m.terrainSoundAddend, m.marioObj.header.gfx.cameraToObject)
    m.particleFlags = m.particleFlags | PARTICLE_DUST
    m.actionTimer = m.actionTimer + 1

    return false
end


local function cutter_ability_overrides(m, inc)
    if using_ability(m, ABILITY_CUTTER) then
        if inc == ACT_JUMP_KICK then
            m.vel.y = 20
            return ACT_CUTTER_THROW_AIR
        end

        if inc == ACT_DIVE and m.floorHeight == m.pos.y then
            m.forwardVel = 100.0
            --play_sound(SOUND_ABILITY_CUTTER_DASH, m.marioObj.header.gfx.cameraToObject)
            return ACT_CUTTER_DASH
        end
    end
end

hook_event(HOOK_BEFORE_SET_MARIO_ACTION, cutter_ability_overrides)

hook_mario_action(ACT_CUTTER_THROW_AIR, act_cutter_throw_air)
hook_mario_action(ACT_CUTSCENE_CONTROLLED, act_cutscene_controlled)
hook_mario_action(ACT_ENTER_HUB_PIPE, act_enter_hub_pipe)
hook_mario_action(ACT_CUTTER_DASH, act_cutter_dash, INT_KICK)
