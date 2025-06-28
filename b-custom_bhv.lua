-- Custom Behaviors --

-- Custom Fields

define_custom_obj_fields({
    oNPCHasTalkedToMario = "u32", --does nothing lmao
    oUpdateRopeSize = "u32",
    oNumSwitchesLeft = "s32",
    oShotByShotgun = "s32",
    oOctoballCantRespawn = "u32",
    oFloatF4 = "f32",
})

-- utils

local function evaluate_cubic_spline(u, Q, spline1, spline2, spline3, spline4)
    local B = {}
    if u > 1.0 then u = 1.0 end

    local nu = 1.0 - u
    local su = u * u
    local hcu = (su * u) / 2.0

    B[1] = (nu ^ 3) / 6.0
    B[2] = hcu - su + (2.0 / 3.0)
    B[3] = -hcu + (su / 2.0) + (u / 2.0) + (1.0 / 6.0)
    B[4] = hcu / 3.0

    Q.x = (B[1] * spline1[1]) + (B[2] * spline2[1]) + (B[3] * spline3[1]) + (B[4] * spline4[1])
    Q.y = (B[1] * spline1[2]) + (B[2] * spline2[2]) + (B[3] * spline3[2]) + (B[4] * spline4[2])
    Q.z = (B[1] * spline1[3]) + (B[2] * spline2[3]) + (B[3] * spline3[3]) + (B[4] * spline4[3])
end

local function move_point_along_spline(p, spline, splineSegment, progress)
    local finished = false
    local controlPoints = {}
    for i = 1, 4 do
        controlPoints[i] = {}
    end
    local u = progress
    local progressChange
    local firstSpeed = 0
    local secondSpeed = 0
    local segment = splineSegment

    if splineSegment < 0 then
        segment = 0
        u = 0
    end
    if spline[segment].index == -1 or spline[segment + 1].index == -1 or spline[segment + 2].index == -1 then
        return 1
    end

    for i = 0, 3 do
        controlPoints[i + 1][1] = spline[segment + i].point[1]
        controlPoints[i + 1][2] = spline[segment + i].point[2]
        controlPoints[i + 1][3] = spline[segment + i].point[3]
    end
    evaluate_cubic_spline(u, p, controlPoints[1], controlPoints[2], controlPoints[3], controlPoints[4])

    if spline[splineSegment + 1].speed ~= 0 then
        firstSpeed = 1.0 / spline[splineSegment + 1].speed
    end
    if spline[splineSegment + 2].speed ~= 0 then
        secondSpeed = 1.0 / spline[splineSegment + 2].speed
    end
    progressChange = (secondSpeed - firstSpeed) * progress + firstSpeed
    progressChange = progressChange * 0.93 -- hacky way to slow down the credits due to slightly longer scenes

    if 1 <= (progress + progressChange) then
        splineSegment = splineSegment + 1
        if spline[splineSegment + 3].index == -1 then
            splineSegment = 0
            finished = true
        end
        progress = progress - 1
    end
    return finished
end

---@param parent Object
---@param modelId ModelExtendedId
---@param behaviorId BehaviorId
---@return Object
function spawn_object(parent, modelId, behaviorId)
    local obj = spawn_non_sync_object(behaviorId, modelId, 0, 0, 0, nil)
    if not obj then return nil end

    obj_copy_pos_and_angle(obj, parent)
    return obj
end

---@param parent Object
---@param modelId ModelExtendedId
---@param behaviorId BehaviorId
---@return Object
function spawn_object2(parent, modelId, behaviorId)
    local obj = spawn_sync_object(behaviorId, modelId, 0, 0, 0, nil)
    if not obj then return nil end

    obj_copy_pos_and_angle(obj, parent)
    return obj
end

function obj_set_hitbox(obj, hitbox)
    if not obj or not hitbox then return end
    -- Sets other hitbox values once
    if (obj.oFlags & OBJ_FLAG_30) == 0 then
        obj.oFlags = obj.oFlags | OBJ_FLAG_30
        if hitbox.interactType ~= nil then
            obj.oInteractType = hitbox.interactType
        end
        obj.oDamageOrCoinValue = hitbox.damageOrCoinValue
        obj.oHealth = hitbox.health
        obj.oNumLootCoins = hitbox.numLootCoins

        cur_obj_become_tangible()
    end

    -- Set actual hitboxes
    obj.hitboxRadius = obj.header.gfx.scale.x * hitbox.radius
    obj.hitboxHeight = obj.header.gfx.scale.y * hitbox.height
    obj.hurtboxRadius = obj.header.gfx.scale.x * hitbox.hurtboxRadius
    obj.hurtboxHeight = obj.header.gfx.scale.y * hitbox.hurtboxHeight
    obj.hitboxDownOffset = obj.header.gfx.scale.y * hitbox.downOffset
end

local function obj_handle_attacks(o, hitbox, attackedMarioAction, attackHandlers)
    if not o then return 0 end
    local attackType

    obj_set_hitbox(o, hitbox)

    -- Die immediately if above lava
    if obj_die_if_above_lava_and_health_non_positive() ~= 0 then
        return 1
    elseif (o.oInteractStatus & INT_STATUS_INTERACTED) ~= 0 then
        if (o.oInteractStatus & INT_STATUS_ATTACKED_MARIO) ~= 0 then
            if o.oAction ~= attackedMarioAction then
                o.oAction = attackedMarioAction
                o.oTimer = 0
            end
        else
            attackType = (o.oInteractStatus & INT_STATUS_ATTACK_MASK)

            if attackHandlers[attackType] == ATTACK_HANDLER_NOP then
                -- Do nothing
            elseif attackHandlers[attackType] == ATTACK_HANDLER_DIE_IF_HEALTH_NON_POSITIVE then
                obj_die_if_health_non_positive()
            elseif attackHandlers[attackType] == ATTACK_HANDLER_KNOCKBACK then
                obj_set_knockback_action(attackType)
            elseif attackHandlers[attackType] == ATTACK_HANDLER_SQUISHED then
                obj_set_squished_action()
            elseif attackHandlers[attackType] == ATTACK_HANDLER_SPECIAL_KOOPA_LOSE_SHELL then
                -- shelled_koopa_attack_handler(attackType)
            elseif attackHandlers[attackType] == ATTACK_HANDLER_SET_SPEED_TO_ZERO then
                -- obj_set_speed_to_zero()
            elseif attackHandlers[attackType] == ATTACK_HANDLER_SPECIAL_WIGGLER_JUMPED_ON then
                --  wiggler_jumped_on_attack_handler()
            elseif attackHandlers[attackType] == ATTACK_HANDLER_SPECIAL_HUGE_GOOMBA_WEAKLY_ATTACKED then
                -- huge_goomba_weakly_attacked()
            elseif attackHandlers[attackType] == ATTACK_HANDLER_SQUISHED_WITH_BLUE_COIN then
                o.oNumLootCoins = -1
                obj_set_squished_action()
            end

            o.oInteractStatus = 0
            return attackType
        end
    end

    o.oInteractStatus = 0
    return 0
end

local function attack_object(obj, interaction)
    local attackType = 0

    if interaction == INT_GROUND_POUND_OR_TWIRL then
        attackType = ATTACK_GROUND_POUND_OR_TWIRL
    elseif interaction == INT_PUNCH then
        attackType = ATTACK_PUNCH
        --elseif interaction == INT_SLASH then
        --obj.oIntangibleTimer = 4
        --  -- fall through
    elseif interaction == INT_KICK or interaction == INT_TRIP then
        attackType = ATTACK_KICK_OR_TRIP
    elseif interaction == INT_SLIDE_KICK or interaction == INT_FAST_ATTACK_OR_SHELL then
        attackType = ATTACK_FAST_ATTACK
    elseif interaction == INT_HIT_FROM_ABOVE then
        attackType = ATTACK_FROM_ABOVE
    elseif interaction == INT_HIT_FROM_BELOW then
        attackType = ATTACK_FROM_BELOW
        --elseif interaction == INT_HIT_STUN then
        --attackType = ATTACK_HIT_STUN
    end

    obj.oInteractStatus = attackType + (INT_STATUS_INTERACTED + INT_STATUS_WAS_ATTACKED)

    -- if interaction == INT_SLASH then
    --obj.oInteractStatus = bit.bor(obj.oInteractStatus, INT_STATUS_CHRONOS_SLASHED)
    --end
    return attackType
end

function spawn_object_relative(behaviorParam, relativePosX, relativePosY, relativePosZ,
                               parent, model, behavior)
    local obj = spawn_object(parent, model, behavior)

    obj_copy_pos_and_angle(obj, parent)
    obj_set_parent_relative_pos(obj, relativePosX, relativePosY, relativePosZ)
    obj_build_relative_transform(obj)

    obj.parentObj = parent

    obj.oBehParams2ndByte = behaviorParam
    obj.oBehParams = (behaviorParam << 16)

    return obj
end

local function spawn_object_relative_with_scale(behaviorParam, relativePosX, relativePosY, relativePosZ, scale,
                                                parent, model, behavior)
    local obj = spawn_object_relative(behaviorParam, relativePosX, relativePosY, relativePosZ,
        parent, model, behavior)
    if obj then
        obj_scale(obj, scale)
    end

    return obj
end

local function spawn_object_relative_with_scale2(behaviorParam, relativePosX, relativePosY, relativePosZ, scale,
                                                 parent, model, behavior)
    local obj = spawn_sync_object(behavior, model,
        parent.oPosX + relativePosX,
        parent.oPosY + relativePosY,
        parent.oPosZ + relativePosZ, function(s)
            s.oBehParams2ndByte = behaviorParam
            obj_scale(s, scale)
            s.parentObj = parent
        end)


    return obj
end


function spawn_object_relative2(behaviorParam, relativePosX, relativePosY, relativePosZ,
                                parent, model, behavior)
    local obj = spawn_object2(parent, model, behavior)

    obj_copy_pos_and_angle(obj, parent)
    obj_set_parent_relative_pos(obj, relativePosX, relativePosY, relativePosZ)
    obj_build_relative_transform(obj)

    obj.oBehParams2ndByte = behaviorParam
    obj.oBehParams = (behaviorParam << 16)

    return obj
end

local function obj_return_home(obj, homeX, y, homeZ, dist)
    local homeDistX = obj.oHomeX - obj.oPosX
    local homeDistZ = obj.oHomeZ - obj.oPosZ
    local angleTowardsHome = atan2s(homeDistZ, homeDistX) -- Convert radians to degrees

    obj.oMoveAngleYaw = approach_s16_symmetric(obj.oMoveAngleYaw, angleTowardsHome, 320)

    return false
end

function approach_s32_symmetric(current, target, inc)
    return approach_s32(current, target, inc, inc)
end

function should_object_spawn()
    return (is_nearest_mario_state_to_object(gMarioStates[0], get_current_object()) ~= 0)
end

-- bhv function

---@param o Object
function level_pipe_init(o)
    queued_pipe_cutscene = false
    o.oUnk94 = random_u16() -- oUnk94 is used for the geo asm timer
    if (gNetworkPlayers[0].currLevelNum ~= LEVEL_CASTLE) then
        o.oOpacity = 250
        return
    end

    o.oOpacity = 0

    if (gGlobalSyncTable.levels_unlocked & (1 << o.oBehParams2ndByte) ~= 0) then
        o.oOpacity = 250
    end
    --o.header.gfx.skipInViewCheck = true
end

local function level_pipe_in_level_loop(o, m)
    if o.oAction == 0 then
        if (lateral_dist_between_objects(o, m.marioObj) < 120) and (m.pos.y < o.oPosY + 500) and (m.pos.y > o.oPosY) then
            m.interactObj = o

            if (m.action ~= ACT_ENTER_HUB_PIPE) then
                set_mario_action(m, ACT_ENTER_HUB_PIPE, 0)
                o.oAction = 3
            end
        end

        load_object_collision_model()
    elseif o.oAction == 3 or o.oAction == 2 then
        if (lateral_dist_between_objects(o, m.marioObj) > 120) then
            o.oAction = 0
        end
        load_object_collision_model()
    else
        return
    end
end

---@param o Object
function level_pipe_loop(o)
    o.oUnk94 = o.oUnk94 + 1
    --djui_chat_message_create(""..levels_unlocked)
    local gMarioState = gMarioStates[0]
    local gMarioObject = gMarioState.marioObj
    local gCurrSaveFileNum = get_current_save_file_num()
    local gCurrSaveFileNumCorrect = get_current_save_file_num() - 1
    local gCurrLevelNum = gNetworkPlayers[0].currLevelNum

    local oPosVec = { x = o.oPosX, y = o.oPosY, z = o.oPosZ }
    if gCurrLevelNum ~= LEVEL_CASTLE then
        level_pipe_in_level_loop(o, gMarioState)
        return
    end

    if gMarioState.numStars >= mitm_levels[o.oBehParams2ndByte].star_requirement and not queued_pipe_cutscene and (gGlobalSyncTable.levels_unlocked & (1 << o.oBehParams2ndByte) == 0) then
        if o.oTimer > 30 then
            queued_pipe_cutscene = true
            o.oAction = 5
            o.oOpacity = 0
            gGlobalSyncTable.levels_unlocked = gGlobalSyncTable.levels_unlocked | (1 << o.oBehParams2ndByte)
            if network_is_server() then
                save_unlocked_levels()
                -- gSaveFileModified = true
            end
        end
        return
    end

    if o.oAction == 0 then
        if lateral_dist_between_objects(o, gMarioObject) < 120.0 and gMarioState.pos.y < o.oPosY + 500.0 and gMarioState.pos.y > o.oPosY then
            hub_level_index = o.oBehParams2ndByte
            gMarioState.interactObj = o

            if gMarioState.action ~= ACT_ENTER_HUB_PIPE then
                set_mario_action(gMarioState, ACT_ENTER_HUB_PIPE, 0)
                o.oAction = 1
                -- Uncomment for debug
                -- mitm_levels[o.oBehParams2ndByte].star_requirement = 0
                if gMarioState.numStars >= mitm_levels[o.oBehParams2ndByte].star_requirement then
                    o.oAction = 3
                end
            end
        end

        load_object_collision_model()
    elseif o.oAction == 1 or o.oAction == 3 then
        hub_level_index = o.oBehParams2ndByte
    elseif o.oAction == 2 then
        if lateral_dist_between_objects(o, gMarioObject) > 120.0 then
            o.oAction = 0
        end
        load_object_collision_model()
    elseif o.oAction == 4 then
        hub_level_index = -1
        hub_level_current_index = o.oBehParams2ndByte
    elseif o.oAction == 5 then
        -- djui_chat_message_create("" .. o.oTimer)
        if o.oTimer == 0 then
            gMarioState.area.camera.cutscene = 1
            o.oHomeX = 0.0
            o.oHomeZ = 0.0
            o.oMoveAngleYaw = cur_obj_angle_to_home()
            set_mario_action(gMarioState, ACT_CUTSCENE_CONTROLLED, 0)
            vec3f_copy(gLakituState.goalFocus, oPosVec)
            vec3f_copy(gLakituState.goalPos, oPosVec)
            gLakituState.goalPos.x = gLakituState.goalPos.x + sins(o.oMoveAngleYaw) * 2000.0
            gLakituState.goalPos.z = gLakituState.goalPos.z + coss(o.oMoveAngleYaw) * 2000.0

            gLakituState.goalFocus.y = gLakituState.goalFocus.y + 200.0
            gLakituState.goalPos.y = gLakituState.goalPos.y + 2000.0
        elseif o.oTimer == 15 then
            spawn_object(o, E_MODEL_STAR, id_bhvUnlockDoorStar)
        elseif o.oTimer == 140 then
            queued_pipe_cutscene = false
        end
        if o.oTimer > 30 and o.oOpacity < 240 then
            o.oOpacity = o.oOpacity + 3
        end
    end

    if not queued_pipe_cutscene and o.oAction == 5 then
        o.oAction = 0
        if gMarioState.area.camera.cutscene == 1 then
            gMarioState.area.camera.cutscene = 0
            set_mario_action(gMarioState, ACT_IDLE, 0)
            save_file_do_save(gCurrSaveFileNum - 1, 1)
            if network_is_server() then
                save_unlocked_levels()
            end
        end
        return
    end
end

-- banana dee
NPC_IDLE = 0x0
NPC_ACT_TURN_TO_TALK = 0x2
NPC_TALK = 0x3
NPC_HAS_NOT_TALKED = 0x0
NPC_HAS_TALKED = 0x2

sElderHitbox1 = {
    interactType = INTERACT_TEXT,
    downOffset = 0,
    damageOrCoinValue = 0,
    health = 0,
    numLootCoins = 0,
    radius = 200,
    height = 200,
    hurtboxRadius = 200,
    hurtboxHeight = 200,
}

sElderHitbox2 = {
    interactType = INTERACT_TEXT,
    downOffset = 0,
    damageOrCoinValue = 0,
    health = 0,
    numLootCoins = 0,
    radius = 100,
    height = 100,
    hurtboxRadius = 100,
    hurtboxHeight = 100,
}

function bhv_npc_init(o)
    o.oGravity = 2.5
    o.oFriction = 0.8
    o.oBuoyancy = 1.3
    o.oInteractionSubtype = INT_SUBTYPE_NPC
    o.header.gfx.scale.x = 1.0
    o.header.gfx.scale.y = 1.0
    o.header.gfx.scale.z = 1.0
    o.oGraphYOffset = 0.0
end

function bhv_youngster_init(o)
    o.oGravity = 2.5
    o.oFriction = 0.8
    o.oBuoyancy = 1.3
    o.oInteractionSubtype = INT_SUBTYPE_NPC
    o.header.gfx.scale.x = 1.0
    o.header.gfx.scale.y = 1.0
    o.header.gfx.scale.z = 1.0
    o.oGraphYOffset = 0.0
end

function bhv_elder_init(o)
    local starFlags = save_file_get_course_star_count(get_current_save_file_num() - 1, gNetworkPlayers[0].currCourseNum)
    o.oGravity = 2.5
    o.oFriction = 0.8
    o.oBuoyancy = 1.3
    o.oInteractionSubtype = INT_SUBTYPE_NPC
    o.header.gfx.scale.x = 1.0
    o.header.gfx.scale.y = 1.0
    o.header.gfx.scale.z = 1.0
    o.oGraphYOffset = 0.0
    obj_set_hitbox(o, sElderHitbox1)
    if starFlags >= 7 then
        o.oPosX = 3365.0
        o.oPosY = 0.0
        o.oPosZ = -5175.0
        obj_set_hitbox(o, sElderHitbox2)
    end
end

function bhv_npc_loop(o)
    local starFlags = save_file_get_course_star_count(get_current_save_file_num() - 1, gNetworkPlayers[0].currCourseNum)
    --[[if obj_has_behavior(o, bhvElder) ~= 0 then
        obj_set_hitbox(o, sElderHitbox1)
        if starFlags >= 7 then
            o.oPosX = 3365.0
            o.oPosY = 0.0
            o.oPosZ = -5175.0
            obj_set_hitbox(o, sElderHitbox2)
        end
    end]] --UNIMPLEMENTED

    npc_actions(o)

    o.oInteractStatus = 0
end

function npc_actions(o)
    smlua_anim_util_set_animation(o, "g_banana_dee_anim_idle")
    if o.oAction == NPC_IDLE then
        npc_idle(o)
    elseif o.oAction == NPC_ACT_TURN_TO_TALK then
        npc_act_turn_to_talk(o)
    elseif o.oAction == NPC_TALK then
        npc_talk(o)
    end

    set_object_visibility(o, 3000)
end

function npc_act_turn_to_talk(o)
    o.oMoveAngleYaw = approach_s16_symmetric(o.oMoveAngleYaw, o.oAngleToMario, 0x1000)
    if o.oMoveAngleYaw == o.oAngleToMario then
        o.oAction = NPC_TALK
    end

    -- cur_obj_play_sound_2(SOUND_PEACH_DEAR_MARIO)
end

function npc_talk(o)
    local starFlags = save_file_get_course_star_count(get_current_save_file_num() - 1, gNetworkPlayers[0].currCourseNum)
    --[[if set_mario_npc_dialog(MARIO_DIALOG_LOOK_FRONT) == MARIO_DIALOG_STATUS_SPEAK then
        o.activeFlags = (o.activeFlags|ACTIVE_FLAG_INITIATED_TIME_STOP)
        if obj_has_behavior(o, bhvElder) ~= 0 and starFlags >= 7 then
            if cutscene_object_with_dialog(CUTSCENE_DIALOG, o, DIALOG_ELDER_BELL_TOWER_2) then
                set_mario_npc_dialog(MARIO_DIALOG_STOP)

                o.activeFlags = (o.activeFlags & ~(ACTIVE_FLAG_INITIATED_TIME_STOP))
                o.oNPCHasTalkedToMario = NPC_HAS_TALKED
                o.oInteractStatus = 0
                o.oAction = NPC_IDLE
            end
        else <-----NOT IMPLEMENTED]]

    gMarioStates[0].action = ACT_READING_NPC_DIALOG
    if cutscene_object_with_dialog(CUTSCENE_DIALOG, o, o.oBehParams2ndByte) ~= 0 then
        o.activeFlags = (o.activeFlags & ~(ACTIVE_FLAG_INITIATED_TIME_STOP))
        o.oNPCHasTalkedToMario = NPC_HAS_TALKED
        o.oInteractStatus = 0
        o.oAction = NPC_IDLE
        --end
        --end
    end
end

function npc_idle(o)
    local animFrame = o.header.gfx.animInfo.animFrame

    if o.oDistanceToMario < 1000.0 then
        o.oMoveAngleYaw = approach_s16_symmetric(o.oMoveAngleYaw, o.oAngleToMario, 0x140)
    end

    if o.oInteractStatus == INT_STATUS_INTERACTED then
        o.oAction = NPC_ACT_TURN_TO_TALK
    end
end

-- sprong

function CLAMP(x, low, high)
    if x > high then
        return high
    elseif x < low then
        return low
    else
        return x
    end
end

G_SPRING_ACTION_WAITING = 0
G_SPRING_ACTION_SPRING = 1
G_SPRING_ACTION_COOLDOWN = 2
G_SPRING_ACTION_TIED = 3

function bhv_g_spring_init(o)
    o.oFlags = o.oFlags|OBJ_FLAG_ATTACHABLE_BY_ROPE
    if (o.oBehParams >> 8) & 0xff == 240 then
        o.oAction = G_SPRING_ACTION_TIED
    end
    o.hookRender = 1
    network_init_object(o, true, { "oAction", "oTimer", "oGravity" })
end

function bhv_g_spring_loop(o)
    local gMarioState = nearest_mario_state_to_object(o)
    local gMarioObject = gMarioState.marioObj
    if o.oAction == G_SPRING_ACTION_WAITING then
        obj_scale_xyz(o, 1, 1, 1)
        if gMarioObject.platform == o then
            o.oAction = G_SPRING_ACTION_SPRING
        end
    elseif o.oAction == G_SPRING_ACTION_SPRING then
        obj_scale_xyz(o, 1, 1.0 - CLAMP(sins(o.oTimer * 2348), -1.0, 0.9), 1)
        if o.oTimer == 15 then
            o.oAction = G_SPRING_ACTION_COOLDOWN
        end
        if o.oTimer == 2 and gMarioObject.platform == o then
            gMarioState.action = ACT_TRIPLE_JUMP
            gMarioState.vel.y = 5 * o.oBehParams2ndByte
            cur_obj_play_sound_2(SOUND_GENERAL_BOING1)
        end
    elseif o.oAction == G_SPRING_ACTION_COOLDOWN then
        obj_scale_xyz(o, 1, 1.0 - (CLAMP(sins(o.oTimer * 2348), 0.1, 2) / (o.oTimer + 1.0)), 1)
        if o.oTimer == 30 then
            o.oAction = G_SPRING_ACTION_WAITING
        end
    end

    if o.oAction == G_SPRING_ACTION_TIED then
        o.oGravity = 3.0

        if object_step() & OBJ_COL_FLAG_GROUNDED ~= 0 then
            o.oAction = G_SPRING_ACTION_WAITING
        end
    end
end

-- waddling dee
local sWaddleDeeHitbox = {
    interactType = INTERACT_BOUNCE_TOP,
    downOffset = 0,
    damageOrCoinValue = 1,
    health = 0,
    numLootCoins = 3,
    radius = 80,
    height = 100,
    hurtboxRadius = 70,
    hurtboxHeight = 30,
}

local sWaddleDeeAttackHandlers = {
    [ATTACK_PUNCH] = ATTACK_HANDLER_KNOCKBACK,
    [ATTACK_KICK_OR_TRIP] = ATTACK_HANDLER_KNOCKBACK,
    [ATTACK_FROM_ABOVE] = ATTACK_HANDLER_SQUISHED,
    [ATTACK_GROUND_POUND_OR_TWIRL] = ATTACK_HANDLER_KNOCKBACK,
    [ATTACK_FAST_ATTACK] = ATTACK_HANDLER_KNOCKBACK,
    [ATTACK_FROM_BELOW] = ATTACK_HANDLER_KNOCKBACK,
}

function bhv_g_waddle_dee_init(o)
    o.oFlags = o.oFlags|OBJ_FLAG_E__SG_ENEMY
    o.oGravity = 2.5
    o.oFriction = 0.8
    o.oBuoyancy = 1.3
    o.oHomeX = o.oPosX
    o.oHomeZ = o.oPosZ
    smlua_anim_util_set_animation(o, "g_waddle_dee_anim_ArmatureAction_001")
    network_init_object(o, true, { "oAction", "oGravity", "oForwardVel", "oPosX", "oPosY", "oPosZ" })
end

function bhv_g_waddle_dee_loop(o)
    if obj_update_standard_actions(1.0) ~= 0 then
        o.oForwardVel = 5.0

        object_step()
        cur_obj_update_floor_and_walls()
        obj_return_home(o, o.oHomeX, o.oHomeY, o.oHomeZ, 400)

        obj_handle_attacks(o, sWaddleDeeHitbox, o.oAction, sWaddleDeeAttackHandlers)
    else
        o.oGravity = -2.5
    end
end

--rope
ATTACHABLE_ROPE_DONT_CHECK_CEIL = 1

local sAttachedRopeHitbox = {
    interactType = 0,
    downOffset = 0,
    damageOrCoinValue = 0,
    health = 0,
    numLootCoins = 0,
    radius = 80,
    height = 100,
    hurtboxRadius = 70,
    hurtboxHeight = 100,
}

function bhv_g_attached_rope_init(o)
    o.oGravity = 2.0
    o.oVelY = 0
    o.header.gfx.skipInViewCheck = true

    local surf
    local originPos = { o.oPosX, o.oPosY, o.oPosZ }
    local raydir = { 0.0, 10000.0, 0.0 }
    local rayResult = 0

    surf = collision_find_surface_on_ray(
        originPos[1], originPos[2], originPos[3],
        raydir[1], raydir[2], raydir[3], 2
    )

    if surf.surface ~= nil then
        rayResult = 3
    end

    if rayResult == 3 then
        o.oBehParams = (o.oBehParams & 0xFFFF0000) | math.floor(surf.hitPos.y - o.oPosY)
    else
        obj_mark_for_deletion(o)
    end

    obj_set_hitbox(o, sAttachedRopeHitbox)
    o.oUpdateRopeSize = 1
    --todo sync?
    --network_init_object(o, true, { "oUpdateRopeSize", "oBehParams", "oAction", "oTimer" })
end

local function mario_can_cut_rope(gMarioState)
    if using_ability(gMarioState, ABILITY_CUTTER) then
        --if gMarioState.action == ACT_FINAL_CUTTER_SEQUENCE or gMarioState.action == ACT_CUTTER_DASH or
        if gMarioState.action == ACT_DIVE or gMarioState.action == ACT_DIVE_SLIDE then
            return true
        end
    end
    if using_ability(gMarioState, ABILITY_CHRONOS) then
        if gMarioState.action == ACT_MOVE_PUNCHING or gMarioState.action == ACT_PUNCHING then
            return true
        end
    end
    if using_ability(gMarioState, ABILITY_ESTEEMED_MORTAL) then
        if gMarioState.action == ACT_ABILITY_AXE_JUMP then
            return true
        end
    end
    return false
end

function bhv_g_attached_rope_loop(o)
    local gMarioState = nearest_mario_state_to_object(o)

    for i = 1, o.numCollidedObjs do
        local other = o.collidedObjs[i]
        local marioHigherPos = gMarioState.pos.y + 100
        if (obj_has_behavior_id(other, bhvCutterBlade) ~= 0 and other.oPosY - 30 > o.oPosY) or
            (other == gMarioState.marioObj and marioHigherPos - 30 > o.oPosY and mario_can_cut_rope(gMarioState)) then
            local otherObjY = (other == gMarioState.marioObj) and math.floor(marioHigherPos) or math.floor(other.oPosY)
            audio_stream_play(SOUND_ABILITY_CUTTER_CATCH, false, 1)
            local cutRope = spawn_object_relative(0, 0, otherObjY - o.oPosY, 0, o, MODEL_ATTACHED_ROPE, bhvGAttachedRope)
            o.oBehParams = (o.oBehParams & 0xFFFF0000) |  math.floor(otherObjY - o.oPosY)
            o.parentObj.oBehParams = (o.parentObj.oBehParams & ~(BP3_ATTACH_ROPE << 8))
            cur_obj_become_intangible()
            o.oUpdateRopeSize = 1
            o.oAction = 1
            o.oTimer = 0
        end
    end

    if o.oUpdateRopeSize == 1 then
        local ropeHeight = GET_BPARAM34(o.oBehParams)
        o.hitboxHeight = ropeHeight + 10
        o.hurtboxHeight = ropeHeight
        o.oUpdateRopeSize = 0
    end

    -- this is just billboard lmao
    o.oFaceAngleYaw = atan2s(gMarioStates[0].area.camera.pos.z - o.oPosZ, gMarioStates[0].area.camera.pos.x - o.oPosX)

    if o.oAction == 1 then
        o.oVelY = o.oVelY - o.oGravity
        o.oPosY = o.oPosY + o.oVelY

        if o.oTimer >= 60 then
            obj_mark_for_deletion(o)
        end
    end
end

--hub
function bhv_hub_platform_loop(o)
    local gMarioObject = gMarioStates[0].marioObj
    if o.oTimer == 0 then
        o.oFaceAngleYaw = random_u16()
    end
    if gMarioObject.platform == o then
        o.oFaceAngleYaw = o.oFaceAngleYaw + 80
        o.oPosY = approach_f32_asymptotic(o.oPosY, o.oHomeY - 50.0, 0.2)
    else
        o.oPosY = approach_f32_asymptotic(o.oPosY, o.oHomeY, 0.2)
        o.oFaceAngleYaw = o.oFaceAngleYaw + 40
    end
end

--- bronto
local sBrontoBurtHitbox = {
    interactType = INTERACT_BOUNCE_TOP,
    downOffset = 0,
    damageOrCoinValue = 1,
    health = 0,
    numLootCoins = 3,
    radius = 80,
    height = 100,
    hurtboxRadius = 70,
    hurtboxHeight = 30,
}

local sBrontoBurtAttackHandlers = {
    [ATTACK_PUNCH] = ATTACK_HANDLER_KNOCKBACK,
    [ATTACK_KICK_OR_TRIP] = ATTACK_HANDLER_KNOCKBACK,
    [ATTACK_FROM_ABOVE] = ATTACK_HANDLER_KNOCKBACK,
    [ATTACK_GROUND_POUND_OR_TWIRL] = ATTACK_HANDLER_KNOCKBACK,
    [ATTACK_FAST_ATTACK] = ATTACK_HANDLER_KNOCKBACK,
    [ATTACK_FROM_BELOW] = ATTACK_HANDLER_KNOCKBACK,
}

function bhv_g_bronto_burt_init(o)
    o.oFlags = o.oFlags|OBJ_FLAG_E__SG_ENEMY
    smlua_anim_util_set_animation(o, "g_bronto_burt_anim_ArmatureAction")
    if o.oBehParams2ndByte % 2 == 0 then
        o.oMoveAngleYaw = o.oFaceAngleYaw + 0x4000 + (0x4000 * o.oBehParams2ndByte)
    end
    network_init_object(o, true, { "oAction", "oGravity", "oForwardVel", "oPosX", "oPosY", "oPosZ" })
end

function bhv_g_bronto_burt_loop(o)
    if obj_update_standard_actions(1.0) ~= 0 then
        if o.oBehParams2ndByte % 2 == 0 then
            o.oForwardVel = 20.0 * coss(o.oTimer * 0x222)
            cur_obj_move_xz_using_fvel_and_yaw()
            cur_obj_update_floor_and_walls()
        else
            o.oPosY = o.oHomeY + 50.0 * coss(o.oTimer * 0x222)
        end

        obj_handle_attacks(o, sBrontoBurtHitbox, o.oAction, sBrontoBurtAttackHandlers)
    else
        o.oGravity = -2.5
    end
end

-- cannon g
function bhv_g_cannon_init(o)
    o.oNumSwitchesLeft = 3
    o.oFaceAnglePitch = 0x8000
    o.oMoveAnglePitch = 0x8000
    network_init_object(o, true, { "oAction", "oNumSwitchesLeft", "oCollisionDistance", "oTimer" })
end

function bhv_g_cannon_loop(o)
    local gMarioState = nearest_mario_state_to_object(o)
    if o.oAction == 0 then
        if o.oNumSwitchesLeft <= 0 then
            o.oAction = 1
            cur_obj_play_sound_2(SOUND_OBJ_CANNON1)
        end
    elseif o.oAction == 1 then
        o.oFaceAnglePitch = approach_s32_symmetric(o.oFaceAnglePitch, 0, 0x200)
        o.oMoveAnglePitch = approach_s32_symmetric(o.oMoveAnglePitch, 0, 0x200)

        if o.oFaceAnglePitch == 0 or o.oTimer >= 120 then
            o.oAction = 2
        end
    elseif o.oAction == 2 then
        if dist_between_objects(o, gMarioState.marioObj) < 100 and gMarioState.pos.y - o.oPosY < 50 then
            o.oAction = 3
            gMarioState.area.camera.cutscene = 1
            gMarioState.pos.x = o.oPosX
            gMarioState.pos.y = o.oPosY
            gMarioState.pos.z = o.oPosZ
            set_mario_action(gMarioState, ACT_CUTSCENE_CONTROLLED, 0)
            gMarioState.marioObj.header.gfx.node.flags = (gMarioState.marioObj.header.gfx.node.flags & ~(GRAPH_RENDER_ACTIVE))
            play_sound(SOUND_GENERAL_METAL_POUND, gMarioState.marioObj.header.gfx.cameraToObject)
            cur_obj_play_sound_2(SOUND_OBJ_CANNON2)
        end
    elseif o.oAction == 3 then
        o.oFaceAnglePitch = o.oFaceAnglePitch + 0x800
        o.oMoveAnglePitch = o.oMoveAnglePitch + 0x800
        if o.oTimer == 35 then
            o.oAction = 4
        end
    elseif o.oAction == 4 then
        obj_scale_xyz(o, 1.0 + (0.5 * sins(o.oTimer * 0x444)),
            1.0 - (0.5 * sins(o.oTimer * 0x444)),
            1.0 + (0.5 * sins(o.oTimer * 0x444)))
        o.oCollisionDistance = 0
        if o.oTimer == 30 then
            gMarioState.faceAngle.y = o.oFaceAngleYaw
            gMarioState.pos.y = gMarioState.pos.y + 110.0
            gMarioState.vel.y = 80.0
            gMarioState.forwardVel = 70.0
            gMarioState.area.camera.cutscene = 0
            gMarioState.marioObj.header.gfx.node.flags = (gMarioState.marioObj.header.gfx.node.flags | GRAPH_RENDER_ACTIVE)
            play_sound(SOUND_ACTION_FLYING_FAST, gMarioState.marioObj.header.gfx.cameraToObject)
            play_sound(SOUND_OBJ_POUNDING_CANNON, gMarioState.marioObj.header.gfx.cameraToObject)
            set_mario_action(gMarioState, ACT_SHOT_FROM_CANNON, 0)
        end

        if o.oTimer == 40 then
            o.oAction = 5
        end
    elseif o.oAction == 5 then
        o.oCollisionDistance = 3000
        o.oFaceAnglePitch = approach_s32_symmetric(o.oFaceAnglePitch, 0, 0x400)
        o.oMoveAnglePitch = approach_s32_symmetric(o.oMoveAnglePitch, 0, 0x400)
        cur_obj_scale(1.0)

        if o.oFaceAnglePitch == 0 or o.oTimer >= 120 then
            o.oAction = 1
        end
    end
end

-- attahced block
function bhv_g_attached_block_init(o)
    -- o.parentObj = spawn_object_relative(0, 0, 200, 0, o, MODEL_ATTACHED_ROPE, bhvGAttachedRope)
    o.oFlags = o.oFlags|OBJ_FLAG_ATTACHABLE_BY_ROPE
    o.oGravity = 2.0
    o.oBounciness = 2.0

    o.oHomeY = find_floor_height(o.oPosX, o.oPosY, o.oPosZ)

    o.hookRender = 1
    network_init_object(o, true, { "oPosY", "oHomeY", "oAction", "oVelY" })
end

function bhv_g_attached_block_loop(o)
    --[[
    if o.parentObj.oAction == 1 then
        o.oAction = 1
    end

    if o.oAction == 1 then
        object_step()

        if o.oTimer == 120 then
            o.oAction = 2
        end
    end
    --]]

    -- object_step()

    o.oPosY = o.oPosY + o.oVelY

    if o.oPosY < o.oHomeY then
        if o.oVelY < -0.5 then
            -- bounce if y velocity is faster than -0.5
            o.oVelY = -o.oVelY * 0.4
        else
            o.oVelY = 0.0
        end
        o.oPosY = o.oHomeY
        if o.oAction == 0 then
            cur_obj_play_sound_2(SOUND_GENERAL_METAL_POUND)
            o.oAction = o.oAction + 1
        end
    else
        o.oVelY = o.oVelY - 2.0
    end
end

--that fucking bird that i hate
local SIR_KIBBLE_ACT_CUTSCENE = 0
local SIR_KIBBLE_ACT_IDLE = 1
local SIR_KIBBLE_ACT_THROWING = 2
local SIR_KIBBLE_ACT_HURT = 3

local sSirKibbleHitbox = {
    interactType = INTERACT_BOUNCE_TOP,
    downOffset = 0,
    damageOrCoinValue = 1,
    health = 0,
    numLootCoins = 3,
    radius = 80,
    height = 100,
    hurtboxRadius = 70,
    hurtboxHeight = 30,
}

local sBossSirKibbleHitbox = {
    interactType = INTERACT_DAMAGE,
    downOffset = 0,
    damageOrCoinValue = 1,
    health = 0,
    numLootCoins = 0,
    radius = 80,
    height = 100,
    hurtboxRadius = 70,
    hurtboxHeight = 30,
}

local sSirKibbleAttackHandlers = {
    [ATTACK_PUNCH] = ATTACK_HANDLER_KNOCKBACK,
    [ATTACK_KICK_OR_TRIP] = ATTACK_HANDLER_KNOCKBACK,
    [ATTACK_FROM_ABOVE] = ATTACK_HANDLER_SET_SPEED_TO_ZERO,
    [ATTACK_GROUND_POUND_OR_TWIRL] = ATTACK_HANDLER_SET_SPEED_TO_ZERO,
    [ATTACK_FAST_ATTACK] = ATTACK_HANDLER_KNOCKBACK,
    [ATTACK_FROM_BELOW] = ATTACK_HANDLER_KNOCKBACK,
}

function bhv_sir_kibble_init(o)
    o.oFlags = (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW|OBJ_FLAG_E__SG_CUSTOM)
    o.oAction = SIR_KIBBLE_ACT_CUTSCENE
    if o.oBehParams2ndByte == 1 then
        obj_set_hitbox(o, sBossSirKibbleHitbox)
        play_secondary_music(SEQ_CUSTOM_KIRBY_BOSS, 0, 127, 5)
    else
        o.oAction = SIR_KIBBLE_ACT_IDLE
    end
    smlua_anim_util_set_animation(o, "sir_kibble_anim_idle")
    o.oGravity = -4.0
    network_init_object(o, true,
        { "oAction", "oTimer", "oShotByShotgun", "oHealth", "oForwardVel", "oVelY", "oInteractStatus" })
end

-- sir_kibble_anim_throw and sir_kibble_anim_idle

function bhv_sir_kibble_loop(o)
    local gMarioObject = nearest_player_to_object(o)
    if obj_update_standard_actions(1.0) ~= 0 then
        obj_turn_toward_object(o, gMarioObject, 0x10, 0x400)
        if o.oBehParams2ndByte == 1 then o.oInteractStatus = 0 end
        if o.oAction == SIR_KIBBLE_ACT_CUTSCENE then
            if o.oTimer > 10 then
                smlua_anim_util_set_animation(o, "sir_kibble_anim_throw")
                o.oAction = SIR_KIBBLE_ACT_THROWING
            end
        elseif o.oAction == SIR_KIBBLE_ACT_IDLE then
            if o.oTimer >= 90 then
                o.oAction = SIR_KIBBLE_ACT_THROWING
                smlua_anim_util_set_animation(o, "sir_kibble_anim_throw")
            end
        elseif o.oAction == SIR_KIBBLE_ACT_THROWING then
            if o.oTimer == 17 then
                -- spawn_object_relative2(2, 0, 100, 0, o, MODEL_CUTTER_BLADE, bhvCutterBlade) --todo sync?

                spawn_sync_object(bhvCutterBlade, MODEL_CUTTER_BLADE, o.oPosX, o.oPosY, o.oPosZ,
                    function(obj)
                        obj.parentObj = o
                        obj_copy_angle(obj, o)
                        obj_set_parent_relative_pos(obj, 0, 100, 0)
                        obj_build_relative_transform(obj)

                        obj.oBehParams2ndByte = 2
                        obj.oBehParams = (2 << 16)
                    end)

                --cutterblade.activeFlags = (cutterblade.activeFlags | ACTIVE_FLAG_INITIATED_TIME_STOP)
            end

            if o.oTimer == 32 then
                o.oAction = SIR_KIBBLE_ACT_IDLE
                smlua_anim_util_set_animation(o, "sir_kibble_anim_idle")
            end
        end

        if o.oBehParams2ndByte == 1 then
            local star = obj_get_nearest_object_with_behavior_id(o, bhvStarProjectile)
            if star and dist_between_objects(star, o) < 200 and o.oAction < 5 then
                o.oAction = OBJ_ACT_HORIZONTAL_KNOCKBACK
                o.oForwardVel = -50.0
                o.oVelY = 30.0
                o.oHealth = 0
            end
        else
            obj_handle_attacks(o, sSirKibbleHitbox, o.oAction, sSirKibbleAttackHandlers)
        end
    end
    if o.oShotByShotgun > 0 then
        --cur_obj_play_sound_2(SOUND_ACTION_SNUFFIT_BULLET_HIT_METAL)
        o.oShotByShotgun = 0
    end
end

bhvSirKibble = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_sir_kibble_init, bhv_sir_kibble_loop, "bhvSirKibble")

-- cutter for ability and that guy above
local sCutterBladeHitbox = {
    interactType = 0,
    downOffset = 50,
    damageOrCoinValue = 1,
    health = 0,
    numLootCoins = 0,
    radius = 80,
    height = 100,
    hurtboxRadius = 20,
    hurtboxHeight = 20,
}

local sEnemyCutterBladeHitbox = {
    interactType = INTERACT_DAMAGE,
    downOffset = 50,
    damageOrCoinValue = 2,
    health = 0,
    numLootCoins = 0,
    radius = 80,
    height = 100,
    hurtboxRadius = 70,
    hurtboxHeight = 30,
}

function bhv_cutter_blade_init(o)
    o.oForwardVel = 70.0
    o.oGravity = 0.0

    audio_sample_play(SOUND_ABILITY_CUTTER_THROW, { x = o.oPosX, y = o.oPosY, z = o.oPosZ }, 1)

    network_init_object(o, true, { "oAction", "oTimer", "oForwardVel", "oFaceAngleYaw" })
end

---@param o Object
function bhv_cutter_blade_loop(o)
    local gMarioObject = nearest_player_to_object(o)
    --djui_chat_message_create("" .. o.oBehParams2ndByte)
    if o.oBehParams2ndByte == 0 then
        obj_set_hitbox(o, sCutterBladeHitbox)
    else
        obj_set_hitbox(o, sEnemyCutterBladeHitbox)
    end
    if o.oAction == 0 then
        o.oFaceAngleYaw = o.oFaceAngleYaw + 0x2000
        o.oForwardVel = o.oForwardVel - 3.0
        if o.oForwardVel <= 0 then
            o.oForwardVel = 0.0
            o.oAction = o.oAction + 1
        end
    elseif o.oAction == 1 then
        o.oFaceAngleYaw = o.oFaceAngleYaw + 0x2000
        if o.oTimer >= 15 then
            o.oAction = o.oAction + 1
        end
    elseif o.oAction == 2 then
        o.oFaceAngleYaw = o.oFaceAngleYaw + 0x2000
        o.oForwardVel = o.oForwardVel - 2.0
        if o.oTimer >= 50 or dist_between_objects(o, gMarioObject) > 2000 then
            o.oAngleVelYaw = 0x800
            o.oAngleVelPitch = random_u16() / 64
            o.oAngleVelRoll = random_u16() / 64
            o.oAction = o.oAction + 1
        end
    elseif o.oAction == 3 then
        o.oGravity = 1.0
        o.oForwardVel = o.oForwardVel * 0.8

        o.oFaceAngleYaw = o.oFaceAngleYaw + o.oAngleVelYaw
        o.oFaceAngleRoll = o.oFaceAngleRoll + o.oAngleVelRoll
        o.oFaceAnglePitch = o.oFaceAnglePitch + o.oAngleVelPitch

        o.oAngleVelYaw = o.oAngleVelYaw * 0.9
        o.oAngleVelRoll = o.oAngleVelRoll * 0.9
        o.oAngleVelPitch = o.oAngleVelPitch * 0.9

        if o.oTimer == 30 then
            spawn_mist_particles_variable(8, 10, 5.0)
            obj_mark_for_deletion(o)
        end
    end

    --[[local surf
    local originPos = { o.oPosX, o.oPosY, o.oPosZ }
    local hitpos = { 0.0, 0.0, 0.0 }
    local raydir = { math.sin(o.oMoveAngleYaw) * o.oForwardVel, 0.0, math.cos(o.oMoveAngleYaw) * o.oForwardVel }
    local rayResult = 0

     wall check
    find_surface_on_ray(originPos, raydir, surf, hitpos, 2)
    if surf ~= nil then
        rayResult = 1
    end
    -- ceil check
    raydir[2] = raydir[2] + 40.0
    find_surface_on_ray(originPos, raydir, surf, hitpos, 4)
    if surf ~= nil then
        rayResult = 3
    end]]

    -- floor check
    --[[ raydir[2] = raydir[2] - 20.0
    surf = collision_find_surface_on_ray(
        originPos[1], originPos[2], originPos[3],
        raydir[1], raydir[2], raydir[3]
    ).surface
    if surf ~= nil then
        rayResult = 2
    end

    if rayResult > 0 then
        if o.oAction == 0 then
            o.oForwardVel = 0.0
            o.oAction = 1
        elseif o.oAction == 2 then
            o.oAction = 3
            if rayResult == 2 then
                o.oVelY = 10.0
            elseif rayResult == 3 then
                o.oVelY = -10.0
            end
            o.oAngleVelYaw = 0x800
            o.oAngleVelPitch = random_u16() / 64
            o.oAngleVelRoll = random_u16() / 64
            o.oForwardVel = o.oForwardVel * -0.05
        end
    end
]]
    if object_step() & OBJ_COL_FLAG_HIT_WALL ~= 0 then
        o.oForwardVel = o.oForwardVel * -0.05
        o.oAngleVelYaw = 0x800
        o.oAngleVelPitch = random_u16() / 64
        o.oAngleVelRoll = random_u16() / 64
        o.oAction = 3
    end

    o.oInteractStatus = 0
    for i = 1, o.numCollidedObjs do
        local other = o.collidedObjs[i]
        if other ~= o.parentObj then
            if other ~= gMarioObject then
                local sirkibb = get_behavior_from_id(bhvSirKibble)
                if not (other.parentObj.behavior == sirkibb and other.behavior == sirkibb) then
                    attack_object(other, 2)
                end
            end
        end
    end

    if o.oAction >= 2 and obj_check_hitbox_overlap(gMarioObject, o) and o.oInteractType ~= INTERACT_DAMAGE then
        audio_stream_play(SOUND_ABILITY_CUTTER_CATCH, false, 1)
        spawn_object_relative2(0, 0, 100, 0, gMarioObject, E_MODEL_NONE, id_bhvSparkleSpawn)
        obj_mark_for_deletion(o)
    end
end

--star proj

function bhv_respawner_loop2(o)
    local spawnedObject
    if (is_point_within_radius_of_mario(o.oPosX, o.oPosY, o.oPosZ, o.oRespawnerMinSpawnDist) == 0) then
        if spawnedObject then
            spawnedObject = spawn_object2(o, o.oRespawnerModelToRespawn, o.oHealth)
            spawnedObject.oBehParams = o.oBehParams
            o.activeFlags = ACTIVE_FLAG_DEACTIVATED
        end
    end
end

function create_respawner(o, model, behToSpawn, minSpawnDist)
    local respawner = spawn_sync_object(bhvRespawner2, E_MODEL_NONE, o.oHomeX, o.oHomeY, o.oHomeZ, nil)
    respawner.oBehParams = o.oBehParams
    respawner.oRespawnerModelToRespawn = model
    respawner.oRespawnerMinSpawnDist = minSpawnDist
    respawner.oHealth = behToSpawn
end

bhvRespawner2 = hook_behavior(nil, OBJ_LIST_SPAWNER, true, function(s)
    network_init_object(s, true, { "oHealth", "oRespawnerMinSpawnDist", "oRespawnerModelToRespawn", "oBehParams" })
end, bhv_respawner_loop2)

local sStarProjectileHitbox = {
    interactType = INTERACT_GRABBABLE,
    downOffset = 0,
    damageOrCoinValue = 0,
    health = 1,
    numLootCoins = 0,
    radius = 100,
    height = 190,
    hurtboxRadius = 100,
    hurtboxHeight = 190,
}

function bhv_star_projectile_init(o)
    o.oFlags = o.oFlags|OBJ_FLAG_E__SG_BREAKABLE
    o.oGravity = 0.0
    o.oFriction = 0.99
    o.oBuoyancy = 1.4
    obj_set_hitbox(o, sStarProjectileHitbox)
    cur_obj_scale(0.8)
    --o.oAnimState = BREAKABLE_BOX_ANIM_STATE_CORK_BOX
    o.activeFlags = (o.activeFlags | ACTIVE_FLAG_UNK9)
    network_init_object(o, true, nil)
end

---@param o Object
function star_projectile_act_move(o)
    local collisionFlags = object_step()

    obj_attack_collided_from_other_object(o)

    if (collisionFlags & OBJ_COL_FLAG_HIT_WALL) ~= 0 then
        spawn_mist_particles()
        spawn_triangle_break_particles(20, 0x8B, 0.2, 3)
        create_sound_spawner(SOUND_GENERAL_EXPLOSION6)
        create_respawner(o, MODEL_G_STAR_BLOCK, bhvStarProjectile, 1000)
        o.activeFlags = ACTIVE_FLAG_DEACTIVATED
    end
    if o.oFloor then
        obj_check_floor_death(collisionFlags, o.oFloor)
    end
end

function star_projectile_released_loop(o)
    o.oBreakableBoxSmallFramesSinceReleased = o.oBreakableBoxSmallFramesSinceReleased + 1

    -- Begin flashing
    if (o.oBreakableBoxSmallFramesSinceReleased > 810) then
        if (o.oBreakableBoxSmallFramesSinceReleased & 1) ~= 0 then
            o.header.gfx.node.flags = o.header.gfx.node.flag | GRAPH_RENDER_INVISIBLE
        else
            o.header.gfx.node.flags = o.header.gfx.node.flags & ~GRAPH_RENDER_INVISIBLE
        end
    end
    -- Despawn, and create a corkbox respawner
    if o.oBreakableBoxSmallFramesSinceReleased > 900 then
        create_respawner(o, MODEL_G_STAR_BLOCK, bhvStarProjectile, 1000)
        o.activeFlags = ACTIVE_FLAG_DEACTIVATED
    end
end

function star_projectile_idle_loop(o)
    if o.oAction == 0 then
        star_projectile_act_move(o)
    elseif o.oAction == OBJ_ACT_LAVA_DEATH then
        obj_lava_death()
    elseif o.oAction == OBJ_ACT_DEATH_PLANE_DEATH then
        o.activeFlags = ACTIVE_FLAG_DEACTIVATED
        create_respawner(o, MODEL_G_STAR_BLOCK, bhvStarProjectile, 1000)
    end

    if o.oBreakableBoxSmallReleased == 1 then
        star_projectile_released_loop(o)
    end
end

function star_projectile_get_dropped(o)
    cur_obj_become_tangible()
    cur_obj_enable_rendering()
    cur_obj_get_dropped()
    o.header.gfx.node.flags = (o.header.gfx.node.flags & ~(GRAPH_RENDER_INVISIBLE))
    o.oHeldState = HELD_FREE
    o.oBreakableBoxSmallReleased = true
    o.oBreakableBoxSmallFramesSinceReleased = 0
end

function star_projectile_get_thrown(o)
    cur_obj_become_tangible()
    cur_obj_enable_rendering()
    obj_set_model_extended(o, MODEL_G_STAR_PROJECTILE)
    o.header.gfx.node.flags = (o.header.gfx.node.flags & ~(GRAPH_RENDER_INVISIBLE))
    o.oHeldState = HELD_FREE
    o.oFlags = (o.oFlags & ~(OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW))
    o.oForwardVel = 40.0
    o.oBreakableBoxSmallReleased = true
    o.oBreakableBoxSmallFramesSinceReleased = 0
    o.activeFlags = (o.activeFlags & ~(ACTIVE_FLAG_UNK9))
end

function bhv_star_projectile_loop(o)
    if o.oHeldState == HELD_FREE then
        star_projectile_idle_loop(o)
    elseif o.oHeldState == HELD_HELD then
        cur_obj_disable_rendering()
        cur_obj_become_intangible()
    elseif o.oHeldState == HELD_THROWN then
        star_projectile_get_thrown(o)
    elseif o.oHeldState == HELD_DROPPED then
        star_projectile_get_thrown(o)
    end

    o.oInteractStatus = 0
end

-- level g cutscenes
g_area_2_spline_KibbleFocus = {
    { index = 0,  speed = 1,  point = { 64, 606, 1474 } },
    { index = 1,  speed = 20, point = { -36, 606, 1424 } },
    { index = 2,  speed = 10, point = { -238, 631, 775 } },
    { index = 3,  speed = 5,  point = { -250, 633, 314 } },
    { index = 4,  speed = 10, point = { -203, 565, -414 } },
    { index = 5,  speed = 60, point = { 17, 541, -760 } },
    { index = 6,  speed = 10, point = { 112, 503, -845 } },
    { index = -1, speed = 1,  point = { 220, 485, -901 } },
}
function bhv_level_g_cutscenes_init(o)
    network_init_object(o, true, nil)
end

function bhv_level_g_cutscenes_loop(o)
    if o.oBehParams2ndByte == 0 then
        --set_time_stop_flags(TIME_STOP_ENABLED | TIME_STOP_MARIO_AND_DOORS)
        --o.activeFlags = (o.activeFlags | ACTIVE_FLAG_INITIATED_TIME_STOP)
        --local sirKibble = obj_get_nearest_object_with_behavior_id(bhvSirKibble)
        --sirKibble.activeFlags = (sirKibble.activeFlags | ACTIVE_FLAG_INITIATED_TIME_STOP)
        --[[for mi = 0, MAX_PLAYERS - 1 do
            local m = gMarioStates[mi]

            m.area.camera.cutscene = 1
            gLakituState.goalPos.x = 749
            gLakituState.goalPos.y = 800
            gLakituState.goalPos.z = 446
            --if move_point_along_spline(gLakituState.goalFocus, (g_area_2_spline_KibbleFocus), sCutsceneSplineSegment, sCutsceneSplineSegmentProgress) then
            m.area.camera.cutscene = 0
            --clear_time_stop_flags(TIME_STOP_ENABLED | TIME_STOP_MARIO_AND_DOORS)

        end]]
        -- end
        obj_mark_for_deletion(o)
    elseif o.oBehParams2ndByte == 1 then
        if o.oAction == 0 then
            local sirKibble = obj_get_nearest_object_with_behavior_id(o, bhvSirKibble)

            if not sirKibble or (sirKibble and (sirKibble.activeFlags & ACTIVE_FLAG_DEACTIVATED) ~= 0) then
                if should_object_spawn() then
                    spawn_sync_object(bhvStarDrop, MODEL_G_STAR_PROJECTILE, o.oHealth, o.oAnimState + 100, o.oDoorUnk100,
                        nil)
                end
                o.oAction = 1
            else
                o.oHealth = sirKibble.oPosX
                o.oAnimState = sirKibble.oPosY
                o.oDoorUnk100 = sirKibble.oPosZ
            end
        end
    end
end

--star drop
function bhv_star_drop_init(o)
    -- gMarioStates[0].area.camera.cutscene = 1
    stop_secondary_music(180)
    network_init_object(o, true, { "oTimer", "oFaceAnglePitch", "oPosY" })
end

function bhv_star_drop_loop(o)
    o.oFaceAngleYaw = o.oFaceAngleYaw + 0x400

    o.oFaceAnglePitch = o.oFaceAnglePitch + 0x800

    if o.oTimer >= 30 and o.oTimer < 90 then
        --[[gLakituState.goalFocus.x = o.oPosX
        gLakituState.goalFocus.y = o.oPosY
        gLakituState.goalFocus.z = o.oPosZ]]
        o.oPosY = o.oPosY + 20 * coss(0x222 * (o.oTimer - 30))
        o.oPosX = approach_f32_asymptotic(o.oPosX, 0, 0.8)
        o.oPosZ = approach_f32_asymptotic(o.oPosZ, 0, 0.8)
    elseif o.oTimer >= 90 then
        o.oPosY = o.oPosY + 4 * coss(0x222 * (o.oTimer - 90))

        if o.oTimer == 110 then
            --spawn_object_relative2(ABILITY_CUTTER, 0, 0, 0, o, MODEL_ABILITY, bhvAbilityUnlock)
            if should_object_spawn() then
                spawn_sync_object(bhvAbilityUnlock, MODEL_ABILITY, o.oPosX, o.oPosY, o.oPosZ,
                    function(j) j.oBehParams2ndByte = ABILITY_CUTTER end)
            end
            cur_obj_hide()
            spawn_mist_particles()
            spawn_triangle_break_particles(20, 0x8B, 0.2, 3)
            create_sound_spawner(SOUND_GENERAL_SHORT_STAR)
        end
        if o.oTimer == 140 then
            --gMarioStates[0].area.camera.cutscene = 0
            obj_mark_for_deletion(o)
            obj_mark_for_deletion(o.parentObj)
        end
    end
end

function bhv_g_cut_rock_init(o)
    o.oFlags = o.oFlags|OBJ_FLAG_ATTACHABLE_BY_ROPE
    o.oGravity = 2.0
    o.oBounciness = 2.0
    o.hookRender = 1
    network_init_object(o, true, { "oAction", "oTimer" })
end

function bhv_g_cut_rock_loop(o)
    o.oAction = 1

    if o.oAction == 1 then
        object_step()

        if o.oTimer == 120 then
            o.oAction = 2
        end
    end
end

function bhv_g_cannon_switch_init(o)
    network_init_object(o, true, { "oAction", "oTimer", "oShotByShotgun" })
end

function bhv_g_cannon_switch_loop(o)
    local dist
    local rock, cannon
    local gMarioObject = nearest_player_to_object(o)

    if o.oAction == 0 then
        obj_set_model_extended(o, E_MODEL_PURPLE_SWITCH)
        cur_obj_scale(1.5)

        --rock, dist = cur_obj_find_nearest_object_with_behavior(get_behavior_from_id(bhvGCutRock))
        rock = obj_get_nearest_object_with_behavior_id(o, bhvGCutRock)
        if (rock and (rock.oPosY - o.oPosY) < 100 and lateral_dist_between_objects(o, rock) < 127.5)
            or (o.oShotByShotgun == 2) then
            o.oAction = 1
            cannon = obj_get_nearest_object_with_behavior_id(o, (bhvGCannon))
            if cannon then
                cannon.oNumSwitchesLeft = cannon.oNumSwitchesLeft - 1
            end
        end
    elseif o.oAction == 1 then
        cur_obj_scale_over_time(2, 3, 1.5, 0.2)
        if o.oTimer == 3 then
            cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH)
            o.oAction = 2
            cur_obj_shake_screen(SHAKE_POS_SMALL)
            -- #ifdef ENABLE_RUMBLE
            queue_rumble_data(5, 80)
            -- #endif
        end
    elseif o.oAction == 2 then
        if o.oBehParams2ndByte ~= 0 then
            if o.oBehParams2ndByte == 1 and gMarioObject.platform ~= o then
                o.oAction = o.oAction + 1
            else
                if o.oTimer < 360 then
                    play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource)
                else
                    play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource)
                end
                if o.oTimer > 400 then
                    o.oAction = 4
                end
            end
        end
    elseif o.oAction == 3 then
        cur_obj_scale_over_time(2, 3, 0.2, 1.5)
        if o.oTimer == 3 then
            o.oAction = 0
        end
    elseif o.oAction == 4 then
        if cur_obj_is_any_player_on_platform() ~= 0 then
            o.oAction = 3
        end
    end

    o.oShotByShotgun = 0
end

local sCollectablePaintingHitbox = {
    interactType = INTERACT_STAR_OR_KEY,
    downOffset = 0,
    damageOrCoinValue = 0,
    health = 0,
    numLootCoins = 0,
    radius = 80,
    height = 50,
    hurtboxRadius = 0,
    hurtboxHeight = 0,
}

function bhv_collectable_painting(obj)
    local paintingIndex = obj.oBehParams2ndByte

    if obj.oAction == 0 then
        -- active at all times in port
        -- Decide if the painting should be active
        --if gSaveBuffer.files[gCurrSaveFileNum - 1][1].paintings_unlocked & (1 << paintingIndex) ~= 0 then
        -- mark_obj_for_deletion(obj)
        -- else
        obj.oAction = 1
        --end
    elseif obj.oAction == 1 then
        -- Initialization
        --[[local texture = (collectable_painting_painting_rgba16)
        local rom_location = painting_data + paintingIndex * 2048
        dma_read(texture, rom_location, rom_location + 2048)

        obj.header.gfx.sharedChild = gLoadedGraphNodes[MODEL_PAINTING]]
        obj_set_model_extended(obj, MODEL_PAINTING)
        obj_set_hitbox(obj, sCollectablePaintingHitbox)
        obj.oAction = 2
    elseif obj.oAction == 2 then
        -- Behavior loop
        obj.oFaceAngleYaw = obj.oFaceAngleYaw + 0x800

        if (obj.oInteractStatus & INT_STATUS_INTERACTED) ~= 0 then
            cur_obj_become_intangible()
            cur_obj_hide()
            obj.oInteractStatus = 0
            obj.oAction = 3
        end
    end
end

---@param o Object
function bhv_g_moving_platform_init(o)
    o.oMoveAngleYaw = o.oFaceAngleYaw;
end

---@param o Object
function bhv_checkpoint_flag(o)
    local m = gMarioStates[0]
    local syncData = gPlayerSyncTable[0]
    if (o.oBehParams2ndByte == syncData.numCheckpointFlag and gNetworkPlayers[0].currAreaIndex == syncData.areaCheckpointFlag) then
        -- Am the current checkpoint flag
        if o.oAnimState ~= 1 then
            o.oAnimState = 1

            -- Move the death warp to me
            local dw = cur_obj_nearest_object_with_behavior(get_behavior_from_id(id_bhvDeathWarp))
            if dw then
                dw.oPosX = o.oPosX + sins(o.oFaceAngleYaw) * 101.0
                dw.oPosY = o.oPosY + 150.0
                dw.oPosZ = o.oPosZ + coss(o.oFaceAngleYaw) * 101.0
                syncData.vecCheckpointFlagv1 = dw.oPosX
                syncData.vecCheckpointFlagv2 = dw.oPosY
                syncData.vecCheckpointFlagv3 = dw.oPosZ
            end
        end
    else
        -- Not the current checkpoint flag
        o.oAnimState = 0
        if o.oDistanceToMario < 100.0 then
            syncData.numCheckpointFlag = o.oBehParams2ndByte
            syncData.areaCheckpointFlag = gNetworkPlayers[0].currAreaIndex
            o.oAnimState = 1
            o.oVelY = 4000.0
            o.oTimer = 0

            play_sound(SOUND_GENERAL2_RIGHT_ANSWER, m.marioObj.header.gfx.cameraToObject)

            -- Move the death warp to me
            local dw = cur_obj_nearest_object_with_behavior(get_behavior_from_id(id_bhvDeathWarp))
            if dw then
                dw.oPosX = o.oPosX + sins(o.oFaceAngleYaw) * 101.0
                dw.oPosY = o.oPosY + 150.0
                dw.oPosZ = o.oPosZ + coss(o.oFaceAngleYaw) * 101.0
                syncData.vecCheckpointFlagv1 = dw.oPosX
                syncData.vecCheckpointFlagv2 = dw.oPosY
                syncData.vecCheckpointFlagv3 = dw.oPosZ
            end
        end
    end

    if o.oVelY > 2000.0 then
        local sparkleObj = spawn_object(o, E_MODEL_SPARKLES, id_bhvCoinSparkles)
        sparkleObj.oPosX = sparkleObj.oPosX + random_float() * 50.0 - 25.0
        sparkleObj.oPosY = sparkleObj.oPosY + random_float() * 100.0
        sparkleObj.oPosZ = sparkleObj.oPosZ + random_float() * 50.0 - 25.0
    end

    o.oFaceAngleRoll = sins(o.oTimer * 0x900) * o.oVelY
    o.oVelY = o.oVelY * 0.97
end

function bhv_g_moving_platform_loop(o)
    o.oForwardVel = o.oBehParams2ndByte * sins(o.oTimer * 0x88 * ((o.oBehParams >> 24) & 0xff));
    cur_obj_move_xz_using_fvel_and_yaw();
end

local function is_punching(m)
    local action = m.action
    return action == ACT_MOVE_PUNCHING or action == ACT_PUNCHING
end

local function using_bubble_hat(m)
    return using_ability(m, ABILITY_BUBBLE_HAT)
end

function jelly_check_dmg(m, o)
    local punchstate = is_punching(m)
    o.oInteractType = INTERACT_SHOCK

    --[[if m.action == ACT_KNIGHT_SLIDE or aku_invincibility > 0 then
        o.oInteractType = INTERACT_BOUNCE_TOP
    end]] --todo maniscat2

    o.oNumLootCoins = 1
    o.hitboxRadius = 80

    if m.vel.y >= 0.0 and punchstate and using_bubble_hat(m) then
        o.oInteractType = INTERACT_BOUNCE_TOP
        o.oNumLootCoins = 3
        o.hitboxRadius = 150
    end

    local cutter = obj_get_nearest_object_with_behavior_id(o, (bhvCutterBlade))
    if cutter and dist_between_objects(o, cutter) < 150.0 then
        o.oInteractType = INTERACT_BOUNCE_TOP
        o.oNumLootCoins = 1
    end

    if (o.oInteractStatus & INT_STATUS_WAS_ATTACKED) ~= 0 then
        return true
    end

    return false
end

-- Initialize jelly object
function jelly_init(o)
    o.oFlags = o.oFlags|OBJ_FLAG_E__SG_ENEMY
    o.oGravity = 0.0
    o.oFriction = 0.999
    o.header.gfx.pos.y = 5 -- Y position in Lua (1-based)
    obj_set_hitbox(o, {
        interactType      = INTERACT_SHOCK,
        downOffset        = 50,
        damageOrCoinValue = 1,
        health            = 1,
        numLootCoins      = 1,
        radius            = 80,
        height            = 90,
        hurtboxRadius     = 70,
        hurtboxHeight     = 80
    })
    smlua_anim_util_set_animation(o, "jelly_anim_jelly_geoAction")
    network_init_object(o, true,
        { "oAction", "oTimer", "oGravity", "oForwardVel", "oInteractStatus", "oBehParams2ndByte", "oFaceAngleYaw" })
end

-- Main jelly loop
function jelly_loop(o)
    object_step()
    local nm = nearest_mario_state_to_object(o)

    if o.oAction == 0 then
        o.oForwardVel = 0
        if dist_between_objects(o, nm.marioObj) < 1000.0 then
            o.oAction = 1
        end
    elseif o.oAction == 1 then
        o.oGravity = 0

        cur_obj_rotate_yaw_toward(obj_angle_to_object(o, nm.marioObj), 0x250)

        if cur_obj_check_anim_frame(1) ~= 0 then o.oForwardVel = 5.2 end
        if cur_obj_check_anim_frame(30) ~= 0 then o.oForwardVel = 0 end
        if cur_obj_check_anim_frame(32) ~= 0 then o.oForwardVel = 4.8 end
        if cur_obj_check_anim_frame(35) ~= 0 then o.oForwardVel = 3.9 end

        if dist_between_objects(o, nm.marioObj) > 1000.0 then
            o.oAction = 0
        end

        if jelly_check_dmg(nm, o) then
            o.oAction = 2
        end

        if o.oTimer >= 2 then
            o.oInteractStatus = 0
        end
    elseif o.oAction == 2 then
        if o.oTimer >= 1 then
            obj_mark_for_deletion(o)
            if o.oNumLootCoins == 3 then
                cur_obj_play_sound_2(SOUND_ACTION_SPIN)
            else
                cur_obj_play_sound_2(SOUND_OBJ_ENEMY_DEATH_HIGH)
            end
            spawn_mist_particles()
            if o.oBehParams2ndByte ~= 5 then
                obj_spawn_loot_yellow_coins(o, o.oNumLootCoins, 10)
            end
        end
    elseif o.oAction == 3 then
        if o.oTimer > 15 then
            o.oBehParams2ndByte = 5
            o.oAction = 1
        end
    end

    -- Squish/stretch animation
    if o.oTimer >= 0 then
        obj_scale_xyz(
            o,
            1.0 + ((0.25 - (0.25 * o.oTimer / 20.0)) * sins(o.oTimer * 0x1000)),
            1.0 + ((0.4 - (0.4 * o.oTimer / 20.0)) * coss(o.oTimer * 0x1000 + 0x4000)),
            1.0 + ((0.25 - (0.25 * o.oTimer / 20.0)) * sins(o.oTimer * 0x1000))
        )
    end

    if o.oTimer >= 22.5 then
        obj_scale_xyz(
            o,
            1.0 + ((0.2 - (0.2 * o.oTimer / 30.0)) * sins(o.oTimer * 0x1000)),
            1.0 + ((0.3 - (0.3 * o.oTimer / 30.0)) * coss(o.oTimer * 0x1000 + 0x4000)),
            1.0 + ((0.25 - (0.25 * o.oTimer / 30.0)) * sins(o.oTimer * 0x1000))
        )
    end

    if o.oTimer >= 45 then
        o.oTimer = 0
    end

    -- Set model if in specific level
    if gNetworkPlayers[0].currLevelNum == LEVEL_A then
        obj_set_model_extended(o, MODEL_JELLY)
    end
end

local sTikiHitbox = {
    interactType = INTERACT_BREAKABLE,
    downOffset = 20,
    damageOrCoinValue = 0,
    health = 1,
    numLootCoins = 2,
    radius = 150,
    height = 200,
    hurtboxRadius = 150,
    hurtboxHeight = 200,
}

function tiki_box_init(o)
    o.oGravity = 1
    o.oOpacity = 150
    obj_set_hitbox(o, sTikiHitbox)
    network_init_object(o, true, { "oTimer", "oInteractStatus" })
end

function tiki_box_loop(o)
    local nm = nearest_mario_state_to_object(o)
    if using_ability(nm, ABILITY_BUBBLE_HAT) then
        if cur_obj_was_attacked_or_ground_pounded() ~= 0 then
            obj_mark_for_deletion(o)
            obj_explode_and_spawn_coins(8, 1)
            obj_spawn_loot_yellow_coins(o, 4, 10)
        end
    end

    if o.oTimer >= 2 then
        o.oInteractStatus = 0
    end

    if o.oBehParams2ndByte == 0 then
        obj_set_model_extended(o, MODEL_TIKI_WOOD)
    elseif o.oBehParams2ndByte == 1 then
        obj_set_model_extended(o, MODEL_TIKI_STONE)
    elseif o.oBehParams2ndByte == 2 then
        obj_set_model_extended(o, MODEL_TIKI_FLOAT)
    end
end

-- Trampoline hitbox definition
local sTrampHitbox = {
    interactType = 0,
    downOffset = 20,
    damageOrCoinValue = 0,
    health = 1,
    numLootCoins = 0,
    radius = 250,
    height = 300,
    hurtboxRadius = 250,
    hurtboxHeight = 300,
}

function trampoline_loop(o)
    local gMarioState = gMarioStates[0]
    local yVel = 90.0
    local fVel = 50.0

    if o.oAction == 0 then
        cur_obj_scale(1.0)
    elseif o.oAction == 1 then
        if o.oTimer >= 0 then
            obj_scale_xyz(o,
                1.0 + ((0.25 - (0.25 * o.oTimer / 20.0)) * sins(o.oTimer * 0x1000)),
                1.0 + ((0.4 - (0.4 * o.oTimer / 20.0)) * coss(o.oTimer * 0x1000 + 0x4000)),
                1.0 + ((0.25 - (0.25 * o.oTimer / 20.0)) * sins(o.oTimer * 0x1000))
            )
        end
        if o.oTimer >= 22.5 then
            obj_scale_xyz(o,
                1.0 + ((0.2 - (0.2 * o.oTimer / 30.0)) * sins(o.oTimer * 0x1000)),
                1.0 + ((0.3 - (0.3 * o.oTimer / 30.0)) * coss(o.oTimer * 0x1000 + 0x4000)),
                1.0 + ((0.25 - (0.25 * o.oTimer / 30.0)) * sins(o.oTimer * 0x1000))
            )
        end
        if o.oTimer >= 45 then

        end
    end

    if gMarioState.marioObj.platform == o then
        cur_obj_play_sound_2(SOUND_OBJ_WATER_BOMB_BOUNCING)
        o.oAction = 1
        gMarioState.vel.y = yVel
        gMarioState.faceAngle.y = gMarioState.intendedYaw
        gMarioState.forwardVel = fVel
        return set_mario_action(gMarioState, ACT_TWIRLING, 0)
    elseif o.oTimer >= 45 then
        o.oAction = 0
    end
end

function a_cage_init(o)
    o.oFlags = o.oFlags|OBJ_FLAG_ATTACHABLE_BY_ROPE
    o.hookRender = 1
    network_init_object(o, true, { "oAction", "oHomeY", "oPosY", "oVelY" })
end

function a_cage_loop(o)
    local ability_object = cur_obj_nearest_object_with_behavior(get_behavior_from_id(bhvAbilityUnlock))

    if o.oAction == 0 then
        -- Set home Y to floor height
        o.oHomeY = find_floor_height(o.oPosX, o.oPosY, o.oPosZ)
        o.oAction = 1
    elseif o.oAction == 1 then
        if ability_object then
            --vec3f_copy(ability_object.oPosVec, o.oPosVec)
            ability_object.oPosX = o.oPosX
            ability_object.oPosY = o.oPosY
            ability_object.oPosY = ability_object.oPosY - 300.0
            ability_object.oPosZ = o.oPosZ
        end

        o.oPosY = o.oPosY + o.oVelY
        o.oVelY = o.oVelY - 2.0

        if o.oPosY < o.oHomeY + 400.0 then
            o.oPosY = o.oHomeY
            obj_mark_for_deletion(o)
            spawn_mist_particles()
            spawn_triangle_break_particles(20, 0x8a, 0.7, 3)
            cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX)
        end
    end
end

---@param o Object
function fcp_loop(o)
    o.header.gfx.shadowInvisible = true
    --cur_obj_init_animation(ANIM_C_MAIN)
    smlua_anim_util_set_animation(o, "floating_checker_platform_anim_ArmatureAction")
    o.oPosY = o.oPosY + o.oVelY

    if o.oBehParams2ndByte == 0 then
        o.oVelY = 5 * sins(o.oTimer * 0x122)
    elseif o.oBehParams2ndByte == 1 then
        o.oVelY = 5 * sins(o.oTimer * 0x222)
    elseif o.oBehParams2ndByte == 2 then
        o.oVelY = 9 * sins(o.oTimer * 0x300)
    end
end

function taxistop_loop(o)
    local transitionTimer = 52
    local behparams = (o.oBehParams >> 24) & 0xff
    local behparams2 = o.oBehParams2ndByte
    ---@type MarioState
    local gMarioState = gMarioStates[0]
    o.header.gfx.skipInViewCheck = true
    --[[
    if gMarioObject.platform == o then
        taxi_stop_text()
    end
    ]] --

    if o.oAction == 0 then
        if gMarioState.marioObj.platform ~= o then
            o.oTimer = 0
        end
        if o.oTimer > 10 then
            o.oAction = 1
            set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0)
            audio_sample_play(SOUND_MITM_LEVEL_TLIM_TAXI, { x = o.oPosX, y = o.oPosY, z = o.oPosZ }, 1)
        end
    elseif o.oAction == 1 then
        if o.oTimer == 1 then
            local boat = spawn_object(o, MODEL_TSBOAT, bhvtsBoat)
            if behparams == 4 then
                boat.oPosZ = boat.oPosZ - 500
            elseif behparams == 3 then
                boat.oPosX = boat.oPosX - 500
            elseif behparams == 1 then
                boat.oPosX = boat.oPosX + 500
            end
        end
        if o.oTimer == 14 then
            set_mario_action(gMarioState, ACT_DISAPPEARED, 1)
        end
        if o.oTimer == 30 then
            play_transition(WARP_TRANSITION_FADE_INTO_STAR, transitionTimer - 29, 0, 0, 0)
        end
        if o.oTimer == 52 then
            warp_to_warpnode(LEVEL_WF, behparams, 0, behparams2)
        end

        if behparams == 1 then
            gMarioState.area.camera.cutscene = 1
            gLakituState.goalPos.x = o.oPosX + 1000
            gLakituState.goalPos.y = o.oPosY + 200
            gLakituState.goalPos.z = o.oPosZ

            gLakituState.goalFocus.x = o.oPosX
            gLakituState.goalFocus.y = o.oPosY + 100
            gLakituState.goalFocus.z = o.oPosZ
        elseif behparams == 3 then
            gMarioState.area.camera.cutscene = 1
            gLakituState.goalPos.x = o.oPosX - 1000
            gLakituState.goalPos.y = o.oPosY + 200
            gLakituState.goalPos.z = o.oPosZ

            gLakituState.goalFocus.x = o.oPosX
            gLakituState.goalFocus.y = o.oPosY + 100
            gLakituState.goalFocus.z = o.oPosZ
        elseif behparams == 4 then
            gMarioState.area.camera.cutscene = 1
            gLakituState.goalPos.x = o.oPosX
            gLakituState.goalPos.y = o.oPosY + 200
            gLakituState.goalPos.z = o.oPosZ - 1000

            gLakituState.goalFocus.x = o.oPosX
            gLakituState.goalFocus.y = o.oPosY + 100
            gLakituState.goalFocus.z = o.oPosZ
        end
    end
end

function tsboat_loop(o)
    smlua_anim_util_set_animation(o, "boat_anim_ArmatureAction")
    if o.oAction == 0 then
        local scale = 1.9 * sins(o.oTimer * 0x300)
        obj_scale_xyz(o, scale, scale, 1.2)
    end
end

function random_signed_value(max)
    return random_float() * random_sign() * max
end

function spawn_multiple_enemies(o, behavior, modelId, amount)
    local obj
    if not should_object_spawn() then return end
    for i = 1, amount do
        obj = spawn_sync_object(behavior, modelId, o.oPosX + random_signed_value(1500.0), o.oPosY + 0,
            o.oPosZ + random_signed_value(1500.0),
            function(obj2)
                obj2.oFaceAngleYaw = 0
                obj2.oFaceAnglePitch = 0
                obj2.oFaceAngleRoll = 0; obj2.oGraphYOffset = 15
                if behavior == bhvOctoballWaves then
                    obj2.oOctoballCantRespawn = 1
                end
                obj_scale(obj2, 2.0)
            end)
        --obj_scale(obj, 2.0)
        --obj.oGraphYOffset = 15
        --obj.oBehParams = 3 << 24
    end
    return obj
end

function bhv_fight_waves_manager_init(o)
    o.oFlags = o.oFlags|OBJ_FLAG_NO_DREAM_COMET
    network_init_object(o, true, { "oAction", "oTimer" })
    --obj_scale(o, 5)
    --obj_set_model_extended(o, E_MODEL_MARIO)
end

function bhv_fight_waves_manager_loop(o)
    local squidLoot
    if o.oAction == 0 then
        -- wait for Mario
        if dist_between_objects(o, nearest_player_to_object(o)) < 2000 then
            spawn_multiple_enemies(o, id_bhvGoomba, MODEL_OCTOBA, 5)
            --play_sound(SOUND_MITM_LEVEL_C_BELL, gGlobalSoundSource)
            o.oAction = 1
        end
    elseif o.oAction == 1 then
        -- wait for wave 1 to end
        if obj_count_objects_with_behavior_id(id_bhvGoomba) == 0 then
            spawn_multiple_enemies(o, bhvOctoballWaves, MODEL_OCTOBALL, 5)
            o.oAction = 2
        end
    elseif o.oAction == 2 then
        if count_objects_with_behavior(get_behavior_from_id(bhvOctoballWaves)) == 0 then
            spawn_multiple_enemies(o, id_bhvChuckya, E_MODEL_CHUCKYA, 5)
            o.oAction = 3
        end
    elseif o.oAction == 3 then
        -- wait for wave 3 to end
        if count_objects_with_behavior(get_behavior_from_id(id_bhvChuckya)) == 0 then
            --djui_chat_message_create("gay")
            create_sound_spawner(SOUND_GENERAL2_RIGHT_ANSWER)
            if should_object_spawn() then
                spawn_sync_object(bhvAbilityUnlock, MODEL_ABILITY, o.oPosX, o.oPosY, o.oPosZ,
                    function(j) j.oBehParams2ndByte = ABILITY_SQUID end)
            end
            o.oAction = 4
        end
    elseif o.oAction == 4 then
        -- end fight
        if o.oTimer > 20 then
            cur_obj_spawn_star_at_y_offset(6656.0, 4172.0, -3519.0, 0.0)
            o.oAction = o.oAction + 1
        end
    end
end

local sOctoballHitbox = {
    interactType = INTERACT_DAMAGE,
    downOffset = 0,
    damageOrCoinValue = 3,
    health = 0,
    numLootCoins = 0,
    radius = 65,
    height = 113,
    hurtboxRadius = 0,
    hurtboxHeight = 0,
}

function bhv_octoball_init(o)
    o.oFlags = o.oFlags|OBJ_FLAG_E__SG_CUSTOM
    o.oGravity = 2.5
    o.oFriction = 0.8
    o.oBuoyancy = 1.3
    o.oFloatF4 = 0.0
    network_init_object(o, true, { "oAction", "oTimer", "oFloatF4", "oBehParams", "oShotByShotgun" })
end

local function octoball_spawn_coin(o)
    if ((o.oBehParams >> 8) & 0x01) == 0 then
        obj_spawn_yellow_coins(o, 3)
        o.oBehParams = 0x100
        --set_object_respawn_info_bits(o, 1)
    end
end

local function try_create_octoball_respawner(o)
    if o.oOctoballCantRespawn == 0 then
        -- create_respawner(MODEL_OCTOBALL, bhvOctoball, 3000)
    end
end

local function octoball_act_explode(o)
    if o.oTimer < 5 then
        cur_obj_scale(1.0 + o.oTimer / 5.0)
    else
        local explosion = spawn_object2(o, E_MODEL_EXPLOSION, id_bhvExplosion)
        explosion.oGraphYOffset = explosion.oGraphYOffset + 100.0

        octoball_spawn_coin(o)
        try_create_octoball_respawner(o)

        o.activeFlags = ACTIVE_FLAG_DEACTIVATED
    end
end

local function octoball_attack_collided_from_other_object(o)
    if o.numCollidedObjs ~= 0 then
        local other = o.collidedObjs[1]
        if other == nearest_player_to_object(o) then
            o.oInteractStatus = o.oInteractStatus | INT_STATUS_HOOT_GRABBED_BY_MARIO
        elseif obj_has_behavior_id(other, bhvOctoball) ~= 0 then
            return false
        end
        return true
    end
    return false
end

local function octoball_check_interactions(o)
    obj_set_hitbox(o, sOctoballHitbox)

    if octoball_attack_collided_from_other_object(o) then
        if (o.oInteractStatus & INT_STATUS_HOOT_GRABBED_BY_MARIO) ~= 0 or
            (o.oInteractStatus & INT_STATUS_WAS_ATTACKED) ~= 0 then
            o.oAction = BOBOMB_ACT_EXPLODE
        end
    end
end

local function octoball_act_patrol(o)
    o.oForwardVel = 8.0
    o.oFloatF4 = 0.4
    local collisionFlags = object_step_without_floor_orient()

    if obj_return_home_if_safe(o, o.oHomeX, o.oHomeY, o.oHomeZ, 600) ~= 0 and
        (abs_angle_diff(o.oMoveAngleYaw, o.oAngleToMario) < 0x4000) then
        o.oBobombFuseLit = 1
        o.oAction = BOBOMB_ACT_CHASE_MARIO
    end

    obj_check_floor_death(collisionFlags, o.oFloor)

    if o.oTimer % 50 == 0 then
        spawn_object2(o, MODEL_PAINT_STAIN, bhvPaintStain)
    end
end

local function octoball_act_chase_mario(o)
    o.header.gfx.animInfo.animFrame = o.header.gfx.animInfo.animFrame + 1
    local animFrame = o.header.gfx.animInfo.animFrame
    local collisionFlags

    o.oForwardVel = 30.0
    o.oFloatF4 = 1.2
    collisionFlags = object_step_without_floor_orient()

    if animFrame == 5 or animFrame == 16 then
        cur_obj_play_sound_2(SOUND_OBJ_BOBOMB_WALK)
    end

    if o.oTimer % 10 == 0 then
        spawn_object2(o, MODEL_PAINT_STAIN, bhvPaintStain)
    end

    obj_turn_toward_object(o, nearest_player_to_object(o), 16, 0x800)
    obj_check_floor_death(collisionFlags, o.oFloor)
end

local function octoball_free_loop(o)
    o.header.gfx.scale.x = 1.0 + (coss((3000 * o.oFloatF4) * o.oTimer) * (0.12 * o.oFloatF4))
    o.header.gfx.scale.y = 1.0 + (coss((2500 * o.oFloatF4) * o.oTimer) * (0.23 * o.oFloatF4))
    o.header.gfx.scale.z = 1.0 + (coss((1000 * o.oFloatF4) * o.oTimer) * (0.08 * o.oFloatF4))

    if o.oAction == BOBOMB_ACT_PATROL then
        octoball_act_patrol(o)
    elseif o.oAction == BOBOMB_ACT_CHASE_MARIO then
        octoball_act_chase_mario(o)
    elseif o.oAction == BOBOMB_ACT_EXPLODE then
        octoball_act_explode(o)
    elseif o.oAction == OBJ_ACT_LAVA_DEATH then
        if obj_lava_death() ~= 0 then
            try_create_octoball_respawner(o)
        end
    elseif o.oAction == OBJ_ACT_DEATH_PLANE_DEATH then
        o.activeFlags = ACTIVE_FLAG_DEACTIVATED
        try_create_octoball_respawner(o)
    end

    octoball_check_interactions(o)

    if o.oShotByShotgun > 1 then
        octoball_act_explode(o)
        o.oShotByShotgun = 0
    end

    if o.oBobombFuseTimer > 200 then
        o.oAction = BOBOMB_ACT_EXPLODE
    end
end

function bhv_octoball_loop(o)
    o.oFaceAnglePitch = o.oFaceAnglePitch + (o.oForwardVel * 100.0)

    if dist_between_objects(o, nearest_player_to_object(o)) < 4000 then
        octoball_free_loop(o)

        if o.oBobombFuseLit == 1 then
            cur_obj_play_sound_1(SOUND_AIR_BOBOMB_LIT_FUSE)
            o.oBobombFuseTimer = o.oBobombFuseTimer + 1
        end
    end
end

---@param o Object
function bhv_paint_stain_init(o)
    if random_sign() == -1 then
        o.oAnimState = 0
    else
        o.oAnimState = 1
    end

    o.oFaceAngleYaw = random_u16()

    o.oFloatF4 = 1.0 -- scale
    cur_obj_scale(o.oFloatF4)
    network_init_object(o, true, { "oAction", "oTimer", "oFloatF4", "oBehParams" })
end

---@param o Object
function bhv_paint_stain_loop(o)
    local sObjFloor = collision_find_floor(o.oPosX, o.oPosY, o.oPosZ)

    local snormals;
    if sObjFloor then
        snormals = { x = sObjFloor.normal.x, y = sObjFloor.normal.y, z = sObjFloor.normal.z }
    end

    mtxf_align_terrain_normal(o.transform, snormals, { x = o.oPosX, y = o.oPosY, z = o.oPosZ }, o.oFaceAngleYaw)
    o.header.gfx.throwMatrix = o.transform
    --[[local z, normal = { x = 0, y = 0, z = 0 }, cur_obj_update_floor_height_and_get_floor().normal
    o.oFaceAnglePitch = 16384 - calculate_pitch(z, normal)
    o.oFaceAngleRoll = 0]]

    if o.oTimer > 120 then
        o.oFloatF4 = o.oFloatF4 - 0.02
        cur_obj_scale(o.oFloatF4)
        if o.oFloatF4 <= 0 then
            obj_mark_for_deletion(o)
        end
    end
    local gMarioState = nearest_mario_state_to_object(o)
    local marioNearestPaintStain = obj_get_nearest_object_with_behavior_id(nearest_player_to_object(o), bhvPaintStain)
    if marioNearestPaintStain == o and dist_between_objects(o, gMarioState.marioObj) < 300.0 then
        gMarioState.health = gMarioState.health - 5
        -- render_textured_splatoon()
    end
end

local MOVING_TIME = 203

---@param o Object
function bhv_ink_moving_platform_init(o)
    o.oCapUnkF4 = 1
    network_init_object(o, true, { "oCapUnkF4", "oVelY", "oTimer", "oPosX", "oPosY", "oPosZ" })
end

function bhv_ink_moving_platform_loop(o)
    if o.oTimer <= MOVING_TIME then
        o.oVelY = 10.0 * o.oCapUnkF4
        cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1)
    elseif o.oTimer <= MOVING_TIME + 60 then
        o.oVelY = 0.0
    else
        o.oTimer = 0
        o.oCapUnkF4 = o.oCapUnkF4 * -1
    end

    cur_obj_move_using_vel()
end

local sPaintGunHitbox = {
    interactType      = INTERACT_GRABBABLE,
    downOffset        = 50,
    damageOrCoinValue = 0,
    health            = 1,
    numLootCoins      = 0,
    radius            = 120,
    height            = 200,
    hurtboxRadius     = 130,
    hurtboxHeight     = 210,
}

local sPaintBulletHitbox = {
    interactType      = INTERACT_DAMAGE,
    downOffset        = 50,
    damageOrCoinValue = 1,
    health            = 1,
    numLootCoins      = 0,
    radius            = 45,
    height            = 80,
    hurtboxRadius     = 45,
    hurtboxHeight     = 80,
}

local function shoot()
    local o = get_current_object()
    local m = nearest_mario_state_to_object(o)
    if should_object_spawn() then
        spawn_sync_object(bhvPaintBullet, MODEL_PAINT_BULLET, 0, 0, o.oPosZ + 180,
            function(s)
                s.oAnimState = o.oAnimState
                s.parentObj = o
                obj_copy_angle(s, o)
                obj_copy_pos_and_angle(s, o)
                obj_set_parent_relative_pos(s, 0, 0, 180)
                obj_build_relative_transform(s)
            end)
    end
    cur_obj_play_sound_1(SOUND_OBJ_SNUFIT_SHOOT)
end

local function remove_mario_from_paint_gun()
    local m = nearest_mario_state_to_object(get_current_object())
    set_mario_action(m, ACT_IDLE, 0)
    m.usedObj = nil
    if m.playerIndex == 0 then
        camera_unfreeze()
    end
    --gLakituState.mode = CAMERA_MODE_8_DIRECTIONS
    --gMarioObject.header.gfx.sharedChild = gLoadedGraphNodes[ability_struct[m.abilityId].model_id]
end

function bhv_paint_gun_init(o)
    o.oFlags = o.oFlags|OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_NO_DREAM_COMET
    network_init_object(o, true,
        { "oInteractStatus", "oSubAction", "oAction", "oAngleVelYaw", "oShotByShotgun", "oAnimState", "oFaceAnglePitch",
            "oMoveAngleYaw" })
end

function bhv_paint_gun_loop(o)
    local m = nearest_mario_state_to_object(o)
    local dist = dist_between_objects(o, m.marioObj)
    obj_set_hitbox(o, sPaintGunHitbox)
    o.oInteractionSubtype = INT_SUBTYPE_NOT_GRABBABLE

    if o.oAction == 0 then -- orange
        o.oMoveAngleYaw = obj_angle_to_object(o, m.marioObj)
        obj_turn_toward_object(o, m.marioObj, 0x0f, 0x1000)
        o.oFaceAnglePitch = o.oMoveAnglePitch

        if dist < 2500 and o.oTimer % 15 == 0 then
            shoot()
        end

        if (o.oInteractStatus & INT_STATUS_INTERACTED ~= 0 and o.oInteractStatus & INT_STATUS_WAS_ATTACKED ~= 0)
            or o.oShotByShotgun == 2
            or o.oInteractStatus & INT_STATUS_MARIO_UNK1 ~= 0 then
            o.oAction = o.oAction + 1
            o.oAnimState = 0
        end
    elseif o.oAction == 1 then -- blue
        if o.oSubAction == 0 then
            o.oAngleVelYaw = 0x2000
            o.oSubAction = o.oSubAction + 1
        elseif o.oSubAction == 1 then -- pivot and slow down
            o.oMoveAngleYaw = o.oMoveAngleYaw + o.oAngleVelYaw
            o.oAngleVelYaw = approach_s32(o.oAngleVelYaw, 0, 0x50, 0x50)
            if o.oAngleVelYaw <= 0 then o.oSubAction = o.oSubAction + 1 end
        elseif o.oSubAction == 2 then -- wait to be controlled
            if dist < 400 then
                --hud_information_string = "Press B to use"
                if m.controller.buttonPressed & B_BUTTON ~= 0 then
                    o.oSubAction = o.oSubAction + 1
                    m.usedObj = o
                    --gPlayerSyncTable[m.playerIndex].modelId = E_MODEL_NONE
                    o.oTimer = 0
                end
            end
        elseif o.oSubAction == 3 then -- Mario controls it
            --shock_rocket_stick_control() --todo add
            set_mario_action(m, ACT_CUTSCENE_CONTROLLED, 0)
            m.usedObj = o
            if m.playerIndex == 0 then
                camera_freeze()
                --  vec3f_copy(gLakituState.pos, oPosVec)
                -- gLakituState.pos.y=o.oPosY+100
                --gLakituState.yaw = o.oMoveAngleYaw
                -- gLakituState.oldPitch = o.oMoveAnglePitch

                local c = gLakituState
                local paintGun = m.usedObj

                local yaw = paintGun.oMoveAngleYaw
                local pitch = paintGun.oMoveAnglePitch
                local cossPitch = coss(pitch)

                local camDecrement
                if paintGun.oAction ~= 1 then
                    camDecrement = 500
                else
                    camDecrement = 500
                end

                local velocityFactor = paintGun.oForwardVel --* ability_chronos_current_slow_factor()

                local camOffset = {
                    x = (sins(yaw) * cossPitch) * (velocityFactor - camDecrement),
                    y = (sins(pitch)) * (velocityFactor + camDecrement),
                    z = (coss(yaw) * cossPitch) * (velocityFactor - camDecrement)
                }

                local newPos = { x = 0, y = 0, z = 0 }

                vec3f_copy(c.focus, { x = paintGun.oPosX, y = paintGun.oPosY, z = paintGun.oPosZ })
                vec3f_copy(newPos, c.focus)
                vec3f_add(newPos, camOffset)
                vec3f_copy(c.pos, newPos)
            end

            local controller = m.controller
            if controller.rawStickY > 60 then
                --up
                o.oMoveAnglePitch = o.oMoveAnglePitch + 500
            elseif controller.rawStickY < -60 then
                --down
                o.oMoveAnglePitch = o.oMoveAnglePitch - 500
            elseif controller.rawStickX > 60 then
                --right
                o.oMoveAngleYaw = o.oMoveAngleYaw - 500
            elseif controller.rawStickX < -60 then
                --left
                o.oMoveAngleYaw = o.oMoveAngleYaw + 500
            end

            if m.controller.buttonPressed & A_BUTTON ~= 0 then
                shoot()
            elseif m.controller.buttonPressed & B_BUTTON ~= 0 then
                remove_mario_from_paint_gun()
                o.oSubAction = o.oSubAction - 1
            end
        end
    end

    -- cap pitch to avoid camera flipping
    if o.oMoveAnglePitch > 0x1600 then o.oMoveAnglePitch = 0x1600 end
    if o.oMoveAnglePitch < -0x1800 then o.oMoveAnglePitch = -0x1800 end

    o.oInteractStatus = 0
    o.oShotByShotgun = 0
end

function bhv_paint_bullet_loop(o)
    obj_set_hitbox(o, sPaintBulletHitbox)

    local ceilHeight = find_ceil_height(o.oPosX, o.oPosY, o.oPosZ)
    cur_obj_update_floor_and_walls()
    obj_attack_collided_from_other_object(o)

    if o.oTimer == 0 then
        local smoke = spawn_object(o, E_MODEL_SMOKE, id_bhvSmoke)
        obj_scale(smoke, 3.0)
    end

    if obj_check_if_collided_with_object(o, nearest_player_to_object(o)) ~= 0
        or o.oTimer > 70
        or (o.oMoveFlags & OBJ_MOVE_HIT_WALL) ~= 0
        or (o.oPosY - o.oFloorHeight < 15)
        or (ceilHeight - o.oPosY < 20) then
        obj_mark_for_deletion(o)
    end

    cur_obj_move_xz_using_fvel_and_yaw()
    o.oPosY = o.oPosY - (sins(o.oMoveAnglePitch)) * o.oForwardVel
end

function bhv_rotating_funky_platform(o)
    if o.oAction == 0 then
        -- store default Yaw
        o.oCapUnkF4 = o.oFaceAngleYaw
        if o.oDistanceToMario < 1900 then
            o.oAngleVelYaw = 0x800
            o.oAction = o.oAction + 1
        end
    end

    if o.oAction == 1 and (o.oFaceAngleYaw - o.oCapUnkF4 >= 0x4000) then
        o.oAngleVelYaw = 0
        o.oFaceAngleYaw = 0x4000
        o.oAction = o.oAction + 1
    end

    cur_obj_rotate_face_angle_using_vel()
end

function bhv_nitro_box_init(o)
    o.oFlags = o.oFlags|OBJ_FLAG_E__SG_CUSTOM
    network_init_object(o, true, { "oPosY", "oTimer", "oInteractStatus", "oShotByShotgun" })
end

function bhv_nitro_box_loop(o)
    o.oPosY = o.oPosY + o.oVelY
    o.oVelY = o.oVelY - 2.0

    if o.oPosY < o.oHomeY then
        o.oPosY = o.oHomeY
        o.oVelY = 0
    end

    if o.oTimer % 20 == 0 then
        o.oVelY = 10.0
    end

    local gMarioState = nearest_mario_state_to_object(o)

    if obj_check_if_collided_with_object(o, gMarioState.marioObj) ~= 0 then
        o.oInteractStatus = o.oInteractStatus & ~INT_STATUS_INTERACTED
        o.activeFlags = ACTIVE_FLAG_DEACTIVATED

        if gPlayerSyncTable[0].aku_recharge ~= 0 then
            --  djui_chat_message_create("dont")
            spawn_object(o, MODEL_NITRO_BOOM, bhvNitroBoom)
            set_mario_action(gMarioState, ACT_HARD_BACKWARD_GROUND_KB, 0)
            gMarioState.faceAngle.y = obj_angle_to_object(o, gMarioState.marioObj) + 0x8000
            gMarioState.health = 0xFF -- die
        else
            --  djui_chat_message_create("have")
            if should_object_spawn() then
                spawn_object2(o, E_MODEL_EXPLOSION, id_bhvExplosion)
            end
        end
    end

    set_object_visibility(o, 7000)

    if o.oShotByShotgun > 0 then
        spawn_object(o, MODEL_NITRO_BOOM, bhvNitroBoom)
        set_mario_action(gMarioState, ACT_HARD_BACKWARD_GROUND_KB, 0)
        gMarioState.faceAngle.y = obj_angle_to_object(o, gMarioState.marioObj) + 0x8000
        gMarioState.health = 0xFF
        o.activeFlags = ACTIVE_FLAG_DEACTIVATED
    end
end

function bhv_nitro_boom_loop(o)
    cur_obj_scale(1.0 + (o.oTimer * 2.0))

    if o.oTimer == 0 then
        o.oOpacity = 150
    end

    if o.oOpacity > 0 then
        o.oOpacity = o.oOpacity - 2
    else
        obj_mark_for_deletion(o)
    end
end

function bhv_moving_funky_platform(o)
    local reverse = 1;
    if (((o.oBehParams >> 24) & 0xff) ~= 0) then reverse = -1; end
    o.oPosX = o.oPosX + (10.0 * coss(1000 * o.oTimer)) * reverse;
end

-- Globals

sBHButtonHitbox = {
    interactType      = INTERACT_BREAKABLE,
    downOffset        = 20,
    damageOrCoinValue = 0,
    health            = 1,
    numLootCoins      = 0,
    radius            = 150,
    height            = 200,
    hurtboxRadius     = 150,
    hurtboxHeight     = 200
}

function bridgesbutton_init(o)
    o.oCollisionDistance = 9000
    o.oBobombExpBubGfxExpRateX = 0
    o.header.gfx.skipInViewCheck = true
    network_init_object(o, true, { "oAction", "oInteractStatus", "oVelY", "oTimer", "oPosY", "oBobombExpBubGfxExpRateX" })
end

function button_for_bridge_loop(o)
    local yVel = 30.0
    local yaw = 0x1000

    if o.oAction == 0 then
        if (o.oInteractStatus & INT_STATUS_INTERACTED) ~= 0 and (o.oInteractStatus & INT_STATUS_WAS_ATTACKED) ~= 0 then
            o.oBobombExpBubGfxExpRateX = 1
            o.oAction = 1
        end
    elseif o.oAction == 1 then
        obj_scale_xyz(o, 1.4 * sins(o.oTimer * 0x555), 1.9 * sins(o.oTimer * 555), 1.0)
        if o.oTimer >= 10 then
            o.oAction = 2
        end
    elseif o.oAction == 2 then
        o.oVelY = yVel
        o.oAngleVelYaw = yaw
        if should_object_spawn() then
            gLakituState.focus.x = 1134
            gLakituState.focus.y = 28
            gLakituState.focus.z = 1775
        end
        if o.oTimer >= 20 then
            o.oAction = 3
        end
    elseif o.oAction == 3 then
        o.oVelY = 0
        obj_mark_for_deletion(o)
        cur_obj_disable_rendering()
        cur_obj_become_intangible()
    end

    o.oPosY = o.oPosY + o.oVelY
    obj_set_hitbox(o, sBHButtonHitbox)
    o.oInteractStatus = 0
    o.oFaceAnglePitch = o.oFaceAnglePitch + o.oAngleVelPitch
    o.oFaceAngleYaw = o.oFaceAngleYaw + o.oAngleVelYaw
    o.oFaceAngleRoll = o.oFaceAngleRoll + o.oAngleVelRoll
end

function button_for_bridge_loop_2(o)
    local yVel = 30.0
    local yaw = 0x1000

    if o.oAction == 0 then
        if (o.oInteractStatus & INT_STATUS_INTERACTED) ~= 0 and (o.oInteractStatus & INT_STATUS_WAS_ATTACKED) ~= 0 then
            o.oBobombExpBubGfxExpRateX = 1
            o.oAction                  = 1
        end
    elseif o.oAction == 1 then
        obj_scale_xyz(o, 1.4 * sins(o.oTimer * 0x555), 1.9 * sins(o.oTimer * 555), 1.0)
        if o.oTimer >= 10 then
            o.oAction = 2
        end
    elseif o.oAction == 2 then
        o.oVelY = yVel
        o.oAngleVelYaw = yaw
        if o.oTimer >= 20 then
            o.oAction = 3
        end
    elseif o.oAction == 3 then
        o.oVelY = 0
        obj_mark_for_deletion(o)
        cur_obj_disable_rendering()
        cur_obj_become_intangible()
    end

    o.oPosY = o.oPosY + o.oVelY
    obj_set_hitbox(o, sBHButtonHitbox)
    -- vec3i_add(o.oFaceAngleVec, o.oAngleVelVec)
    o.oFaceAnglePitch = o.oFaceAnglePitch + o.oAngleVelPitch
    o.oFaceAngleYaw = o.oFaceAngleYaw + o.oAngleVelYaw
    o.oFaceAngleRoll = o.oFaceAngleRoll + o.oAngleVelRoll
end

function bridge_loop(o)
    if o.oAction == 0 then
        smlua_anim_util_set_animation(o, "bhbridge_anim_ArmatureAction")
        cur_obj_become_intangible()
        local bhbrige = obj_get_nearest_object_with_behavior_id(o, bhvBhButton)
        if bhbrige and bhbrige.oBobombExpBubGfxExpRateX == 1 then
            o.oAction = 1
        end
    elseif o.oAction == 1 then
        smlua_anim_util_set_animation(o, "anim_bflip_ArmatureAction")
        cur_obj_become_tangible()
        if o.oTimer >= 21 then
            o.oAction = 2
        end
    elseif o.oAction == 2 then
        smlua_anim_util_set_animation(o, "bhbridge_idle_anim_ArmatureAction")
        load_object_collision_model()
    end
end

function bridge2_loop(o)
    if o.oAction == 0 then
        smlua_anim_util_set_animation(o, "bhbridge_anim_ArmatureAction")
        cur_obj_become_intangible()
        local bhbrige = obj_get_nearest_object_with_behavior_id(o, bhvBhButton2)
        if bhbrige and bhbrige.oBobombExpBubGfxExpRateX == 1 then
            o.oAction = 1
        end
    elseif o.oAction == 1 then
        smlua_anim_util_set_animation(o, "anim_bflip_ArmatureAction")
        cur_obj_become_tangible()
        if o.oTimer >= 21 then
            o.oAction = 2
        end
    elseif o.oAction == 2 then
        smlua_anim_util_set_animation(o, "bhbridge_idle_anim_ArmatureAction")
        load_object_collision_model()
    end
end

function bhv_star_piece_switch_init(o)
    o.oFlags = o.oFlags|OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW | OBJ_FLAG_NO_DREAM_COMET
    o.oBobombBuddyPosXCopy = 0
    network_init_object(o, true,
        { "oAction", "oGravity", "oVelY", "oShotByShotgun", "oTimer", "oPosY", "oBobombBuddyPosXCopy" })
end

BLUE_COIN_SWITCH_ACT_IDLE      = 0
BLUE_COIN_SWITCH_ACT_RECEDING  = 1
BLUE_COIN_SWITCH_ACT_TICKING   = 2
BLUE_COIN_SWITCH_ACT_EXTENDING = 3

function bhv_star_piece_switch_loop(o)
    cur_obj_scale(3.0)
    local m = nearest_mario_state_to_object(o)
    local gMarioObject = m.marioObj
    --djui_chat_message_create(""..o.oBobombBuddyPosXCopy)

    if o.oAction == BLUE_COIN_SWITCH_ACT_IDLE then
        if (gMarioObject.platform == o and m.action == ACT_GROUND_POUND_LAND) or o.oShotByShotgun == 2 then
            o.oBobombBuddyPosXCopy = 0
            o.oAction = BLUE_COIN_SWITCH_ACT_RECEDING
            o.oVelY = -16.0
            o.oGravity = 0.0
            cur_obj_play_sound_2(SOUND_GENERAL_SWITCH_DOOR_OPEN)
        end
        o.oShotByShotgun = 0
        load_object_collision_model()
    elseif o.oAction == BLUE_COIN_SWITCH_ACT_RECEDING then
        if o.oTimer > 3 then
            o.oAction = BLUE_COIN_SWITCH_ACT_TICKING
            o.oVelY = 0.0
            o.oGravity = 0.0
            spawn_mist_particles_variable(0, 0, 46.0)
        else
            load_object_collision_model()
            cur_obj_move_using_fvel_and_gravity()
        end
    elseif o.oAction == BLUE_COIN_SWITCH_ACT_TICKING then
        local fast_tick_limit = (o.oBehParams2ndByte == 0) and 200 or (o.oBehParams2ndByte * 10) - 40

        if o.oTimer < fast_tick_limit then
            play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource)
        else
            play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource)
        end

        if o.oBobombBuddyPosXCopy > 4 then
            spawn_default_star(o.oPosX, o.oPosY + 400.0, o.oPosZ)
            spawn_mist_particles_variable(0, 0, 46.0)
            obj_mark_for_deletion(o)
        elseif o.oTimer > ((o.oBehParams2ndByte == 0) and 240 or (o.oBehParams2ndByte * 10)) then
            o.oAction = BLUE_COIN_SWITCH_ACT_EXTENDING
            o.oVelY = 16.0
            o.oGravity = 0.0
        end

        load_object_collision_model()
    elseif o.oAction == BLUE_COIN_SWITCH_ACT_EXTENDING then
        if o.oTimer > 3 then
            o.oAction = 0
            o.oPosY = o.oHomeY
        else
            load_object_collision_model()
            cur_obj_move_using_fvel_and_gravity()
        end
    end
end

function bhv_star_piece_init(o)
    network_init_object(o, true,
        { "oAction", "oGravity", "oVelY", "oShotByShotgun", "oTimer", "oPosY", "oFaceAngleYaw", "oHealth" })
end

function bhv_star_piece_loop(o)
    local sps = cur_obj_nearest_object_with_behavior(get_behavior_from_id(bhvStarPieceSwitch))

    o.oFaceAngleYaw = o.oFaceAngleYaw + 0x400
    o.oPosY = o.oHomeY + 20.0 + sins(o.oTimer * 0x500) * 20.0

    if o.oAction == 0 then
        cur_obj_hide()
        o.oAction = 1
    elseif o.oAction == 1 then
        if sps and sps.oAction == BLUE_COIN_SWITCH_ACT_TICKING then
            o.oAction = 2
            cur_obj_unhide()
        end
    elseif o.oAction == 2 then
        if sps and sps.oTimer > ((sps.oBehParams2ndByte == 0) and 200 or (sps.oBehParams2ndByte * 10) - 40) then
            if get_global_timer() % 2 == 0 then
                cur_obj_unhide()
            else
                cur_obj_hide()
            end
        end

        if dist_between_objects(o, nearest_player_to_object(o)) < 160.0 then
            cur_obj_hide()
            cur_obj_play_sound_2(SOUND_MENU_COLLECT_SECRET + sps.oBobombBuddyPosXCopy)
            spawn_object(o, E_MODEL_SPARKLES, id_bhvCoinSparkles)
            sps.oBobombBuddyPosXCopy = sps.oBobombBuddyPosXCopy + 1
            spawn_orange_number(sps.oBobombBuddyPosXCopy, 0, 0, 0)
            o.oAction = 3
        end
    elseif o.oAction == 3 then
        if sps and (sps.oAction == 3 or sps.oAction == 0) then
            cur_obj_hide()
            o.oAction = 1
        end
    end

    if sps.oAction == BLUE_COIN_SWITCH_ACT_IDLE then
        o.oAction = 0
    end
end

--crane
local PURPLE_SWITCH_ACT_IDLE                      = 0x0
local PURPLE_SWITCH_ACT_PRESSED                   = 0x1
local PURPLE_SWITCH_ACT_TICKING                   = 0x2
local PURPLE_SWITCH_ACT_UNPRESSED                 = 0x3
local PURPLE_SWITCH_ACT_WAIT_FOR_MARIO_TO_GET_OFF = 0x4

local OFFSET                                      = 180

---@param o Object
function bhv_crane_arrow_controller_init(o)
end

function bhv_crane_arrow_controller_loop(o)
    -- Empty function body
    o.oFlameBowser = obj_get_nearest_object_with_behavior_id(o, (bhvCrane))

    if should_object_spawn() and count_objects_with_behavior(get_behavior_from_id(bhvCraneArrow)) < 2 then
        if not o.oHiddenObjectUnkF4 then
            -- o.oHiddenObjectUnkF4 = spawn_object_relative_with_scale2(0, OFFSET, 0, 0, 2.0, o, MODEL_CRANE_ARROW,
            --bhvCraneArrow)

            -- o.oHiddenObjectUnkF4.oFaceAngleYaw = o.oHiddenObjectUnkF4.oFaceAngleYaw + 0x8000

            o.oHiddenObjectUnkF4 = spawn_sync_object(bhvCraneArrow, MODEL_CRANE_ARROW, o.oPosX + 180, o.oPosY, o.oPosZ,
                function(j)
                    j.oFaceAngleYaw = o.oFaceAngleYaw
                    j.oFaceAngleYaw = j.oFaceAngleYaw + 0x8000
                    --  j.oBehParams2ndByte = behaviorParam
                    obj_scale(j, 2)
                    j.parentObj = o
                end)
        end
        if not o.oHiddenBlueCoinSwitch then
            o.oHiddenBlueCoinSwitch = spawn_sync_object(bhvCraneArrow, MODEL_CRANE_ARROW, o.oPosX + -180, o.oPosY, o
                .oPosZ,
                function(j)
                    j.oFaceAngleYaw = o.oFaceAngleYaw
                    --j.oFaceAngleYaw = j.oFaceAngleYaw + 0x8000
                    j.oBehParams2ndByte = 1
                    j.oBehParams = (1 << 16)
                    obj_scale(j, 2)
                    j.parentObj = o
                end)
        end
    end
end

function bhv_crane_arrow_init(o)
    o.oFlags = o.oFlags|OBJ_FLAG_NO_DREAM_COMET
end

---@param o Object
function bhv_crane_arrow_loop(o)
    o.header.gfx.skipInViewCheck = true
    local m = nearest_mario_state_to_object(o)
    local gMarioObject = m.marioObj
    if o.oAction == PURPLE_SWITCH_ACT_IDLE then
        if (
                gMarioObject.platform == o and
                (m.action & 0x00002000) == 0 and
                lateral_dist_between_objects(o, gMarioObject) < 150.5
            ) or (o.oShotByShotgun == 2) then -- --E
            o.oAction = PURPLE_SWITCH_ACT_PRESSED
        end
    elseif o.oAction == PURPLE_SWITCH_ACT_PRESSED then
        cur_obj_scale_over_time(2, 3, 2.0, 0.2)
        if o.oTimer == 3 then
            cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH)
            o.oAction = PURPLE_SWITCH_ACT_TICKING
            cur_obj_shake_screen(SHAKE_POS_SMALL)
            if m.playerIndex == 0 then
                local crane = cur_obj_nearest_object_with_behavior(get_behavior_from_id(bhvCrane));
                --m.area.camera.cutscene = 1
                --vec3f_copy(m.area.camera.focus, { x = crane.oPosX, y = crane.oPosY, z = crane.oPosZ });
                --vec3f_copy(m.area.camera.pos, { x = crane.oPosX, y = crane.oPosY, z = crane.oPosZ });

                -- struct Object *camera = cur_obj_nearest_object_with_behavior(bhvCamera);
                --vec3f_copy(c->pos, &camera->oPosVec);
                --gLakituState.mode = CAMERA_MODE_CRANE
                -- if ENABLE_RUMBLE then
            end
            queue_rumble_data(5, 80)
            -- end
        end
    elseif o.oAction == PURPLE_SWITCH_ACT_TICKING then
        if gMarioObject.platform ~= o then
            o.oAction = o.oAction + 1
        end

        local crane = o.parentObj.oFlameBowser
        if crane ~= nil then
            crane.oMoveAngleYaw = crane.oMoveAngleYaw + 110 * (1 - ((o.oBehParams >> 16) & 0xff) * 2)
            cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1)
        end
    elseif o.oAction == PURPLE_SWITCH_ACT_UNPRESSED then
        cur_obj_scale_over_time(2, 3, 0.2, 2.0)
        if o.oTimer == 3 then
            o.oAction = PURPLE_SWITCH_ACT_IDLE
            if m.playerIndex == 0 then
                m.area.camera.cutscene = 0
            end
            --gLakituState.mode = CAMERA_MODE_8_DIRECTIONS
        end
    end

    o.oShotByShotgun = 0 -- --E
end

function bhv_crane_init(o)
    o.header.gfx.skipInViewCheck = true
    -- o.oHiddenObjectUnkF4 = spawn_object_relative_with_scale(0, 0, 800, 4000, 1.0, o, MODEL_CRANE_HEAD, bhvCraneHead)
end

function bhv_crane_loop(o)
    o.header.gfx.skipInViewCheck = true
    if should_object_spawn() and count_objects_with_behavior(get_behavior_from_id(bhvCraneHead)) == 0 then
        o.oHiddenObjectUnkF4 = spawn_object_relative_with_scale2(0, 0, 800, 4000, 1.0, o, MODEL_CRANE_HEAD, bhvCraneHead)
    end
    -- djui_chat_message_create(tostring(o.oHiddenObjectUnkF4~=nil))
end

function bhv_crane_head_loop(o)
    o.header.gfx.skipInViewCheck = true
    cur_obj_set_pos_relative(o.parentObj, 0, 900, 4200)
    o.oMoveAngleYaw = o.parentObj.oMoveAngleYaw
    o.oFaceAnglePitch = o.oFaceAnglePitch + 300
end

function bhv_crane_rock_init(o)
    o.header.gfx.skipInViewCheck = true
    o.oHomeY = o.oPosY
    o.oHiddenBlueCoinSwitch = cur_obj_nearest_object_with_behavior(get_behavior_from_id(bhvCraneHead))
    o.oCapUnkF4 = 0
end

function bhv_crane_rock_loop(o)
    o.header.gfx.skipInViewCheck = true
    if o.oAction == 0 then
        o.oHiddenBlueCoinSwitch = obj_get_nearest_object_with_behavior_id(o, (bhvCraneHead))
        if o.oHiddenBlueCoinSwitch ~= nil then
            if dist_between_objects(o.oHiddenBlueCoinSwitch, o) < 1700 then
                o.oAction = o.oAction + 1
            end
        end
    elseif o.oAction == 1 then
        o.oCapUnkF4 = o.oCapUnkF4 + 1
        cur_obj_play_sound_1(SOUND_ENV_METAL_BOX_PUSH)
        o.oPosY = (o.oTimer % 2 == 1) and (o.oHomeY + 20.0) or (o.oHomeY - 20.0)

        if o.oCapUnkF4 > 150 then
            o.oAction = o.oAction + 1
        end

        if dist_between_objects(o.oHiddenBlueCoinSwitch, o) > 2000 then
            o.oCapUnkF4 = 0
            o.oAction = 0
        end
    elseif o.oAction == 2 then
        create_sound_spawner(SOUND_GENERAL2_PYRAMID_TOP_EXPLOSION)
        spawn_mist_particles_variable(0, 0, 500.0)
        spawn_triangle_break_particles(30, 0x8a, 3.0, 4)

        if count_objects_with_behavior(get_behavior_from_id(bhvCraneRock)) == 1 then
            -- play_puzzle_jingle()
            spawn_default_star(8535, 4140 + 30, 8022)
        end

        obj_mark_for_deletion(o)
    end
end

local WATCH_DISTANCE = 1300.0

local trinkets_shot_f = 0;

local bruh_scale = 1.0
function find_nearest_watch_target(o)
    local targetable_behavior_list = {
        id_bhvFloorSwitchAnimatesObject,
        id_bhvFloorSwitchGrills,
        id_bhvFloorSwitchHardcodedModel,
        id_bhvFloorSwitchHiddenObjects,
        id_bhvBlueCoinSwitch,
        id_bhvExclamationBox,
        id_bhvBreakableBox,
        id_bhvBreakableBoxSmall,
        id_bhvMessagePanel,
        bhvStarPieceSwitch,
        --bhvKeypad,
        --bhvGMarxDoor,
        --bhvWoodenLever,
        --bhvFTrinket,
        --bhvFblastwall,
        id_bhvSignOnWall,
        bhvPaintGun,
    }
    local result
    local closest = nil
    local closest_dist = WATCH_DISTANCE

    for i = 1, #targetable_behavior_list do
        result = obj_get_nearest_object_with_behavior_id(gMarioStates[0].marioObj, targetable_behavior_list[i])

        if result then
            local this_dist = dist_between_objects(gMarioStates[0].marioObj, result)
            if this_dist < closest_dist then
                closest_dist = this_dist
                closest = result
            end
        end
    end

    return closest
end

function bhv_gadget_aim(o)
    local target = find_nearest_watch_target(o)
    local m = gMarioStates[0]

    if o.oHiddenBlueCoinSwitch ~= target then
        o.oHiddenBlueCoinSwitch = target
        bruh_scale = 1.0
        play_sound(SOUND_GENERAL_UNKNOWN3_2, gGlobalSoundSource)
    end

    if target then
        -- vec3f_copy(o.oPosVec, target.oPosVec)
        o.oPosX = target.oPosX
        o.oPosY = target.oPosY
        o.oPosZ = target.oPosZ
        cur_obj_unhide()
        cur_obj_scale(bruh_scale + 1.0)
        bruh_scale = bruh_scale * 0.9
        if (m.controller.buttonPressed & L_TRIG) ~= 0 then
            local laser
            if should_object_spawn() then
                laser = spawn_sync_object(bhvFLaser, MODEL_F_LASER, m.pos.x, m.pos.y, m.pos.z,
                    function(l)
                        l.oPosX, l.oPosY, l.oPosZ = get_hand_foot_pos_x(m, 0), get_hand_foot_pos_y(m, 0),
                            get_hand_foot_pos_z(m, 0)
                        l.oHomeX = target.oPosX
                        l.oHomeY = target.oPosY
                        l.oHomeZ = target.oPosZ
                    end)
            end


            local behavior = get_id_from_behavior(target.behavior)

            if behavior == (id_bhvBreakableBox) then
                spawn_object(target, E_MODEL_EXPLOSION, id_bhvExplosion)
                target.oAction = 2
                spawn_mist_particles()
                spawn_triangle_break_particles(30, 0x8a, 3.0, 4)
                obj_mark_for_deletion(target)
            elseif behavior == (id_bhvBreakableBoxSmall) then
                spawn_object(target, E_MODEL_EXPLOSION, id_bhvExplosion)
                target.oForwardVel = 30.0
                target.oMoveAngleYaw = m.faceAngle.y
            elseif behavior == (id_bhvFloorSwitchGrills)
                or behavior == (id_bhvFloorSwitchAnimatesObject)
                or behavior == (id_bhvFloorSwitchHardcodedModel)
                or behavior == (id_bhvFloorSwitchHiddenObjects) then
                target.oAction = PURPLE_SWITCH_ACT_PRESSED
            elseif behavior == (id_bhvExclamationBox) then
                if target.oAction == 2 then
                    target.oAction = 4
                end
            elseif behavior == (id_bhvBlueCoinSwitch) then
                if target.oAction == BLUE_COIN_SWITCH_ACT_IDLE then
                    target.oAction = BLUE_COIN_SWITCH_ACT_RECEDING
                    target.oVelY = -20.0
                    target.oGravity = 0.0
                    cur_obj_play_sound_2(SOUND_GENERAL_SWITCH_DOOR_OPEN)
                end
            elseif behavior == (id_bhvMessagePanel)
                or behavior == (id_bhvSignOnWall) then
                m.usedObj = target
                set_mario_action(m, ACT_READING_SIGN, 0)
            elseif behavior == (bhvStarPieceSwitch) then
                if target.oAction == BLUE_COIN_SWITCH_ACT_IDLE then
                    target.oAction = BLUE_COIN_SWITCH_ACT_RECEDING
                    target.oVelY = -20.0
                    target.oGravity = 0.0
                    star_pieces_got = 0
                    cur_obj_play_sound_2(SOUND_GENERAL_SWITCH_DOOR_OPEN)
                end
                --[[elseif behavior == (bhvKeypad) then
                gMarioState.keypad_id = target.oBehParams2ndByte
                spawn_object(target, MODEL_EXPLOSION, bhvExplosion)
                mark_obj_for_deletion(target)
            elseif behavior == (bhvGMarxDoor) then
                spawn_object(target, MODEL_EXPLOSION, bhvExplosionVisual)
                mark_obj_for_deletion(target)
            elseif behavior == (bhvWoodenLever) then
                if target.oAction == 0 then
                    target.oAction = 1
                end]] --TODO
            elseif behavior == (bhvPaintGun) then
                if target.oAction == 0 then
                    target.oAction = target.oAction + 1
                    target.oAnimState = 0
                end
                --[[ elseif behavior == (bhvFTrinket) then
                trinkets_shot_f = trinkets_shot_f + 1
                cur_obj_play_sound_2(SOUND_GENERAL_BOWSER_KEY_LAND)
                spawn_object(target, MODEL_EXPLOSION, bhvExplosionVisual)
                mark_obj_for_deletion(target)

                if trinkets_shot_f == 3 then
                    spawn_default_star(-1832, 484, 2022)
                end
            elseif behavior == (bhvFblastwall) then
                if target.oAction == 0 then
                    target.header.gfx.sharedChild = gLoadedGraphNodes[MODEL_BLASTWALL_2]
                    target.collisionData = (blastwall2_collision)
                    target.oAction = 1
                end]] --TODO
            end
        end
    else
        cur_obj_hide()
        bruh_scale = 1.0
    end
end

function bhv_f_laser(o)
    local m = nearest_mario_state_to_object(o)
    local origin = { get_hand_foot_pos_x(m, 0), get_hand_foot_pos_y(m, 0),
        get_hand_foot_pos_z(m, 0) }
    local hitpos = { o.oHomeX, o.oHomeY, o.oHomeZ }

    local dir = {
        hitpos[1] - origin[1],
        hitpos[2] - origin[2],
        hitpos[3] - origin[3]
    }

    local length = math.sqrt(dir[1] ^ 2 + dir[2] ^ 2 + dir[3] ^ 2)
    o.header.gfx.scale.z = length / 100.0

    local a = hitpos[1] - o.oPosX
    local b = hitpos[3] - o.oPosZ

    o.oFaceAngleYaw = atan2s(b, a)
    o.oFaceAnglePitch = atan2s(math.sqrt(a * a + b * b), origin[2] - hitpos[2])

    if o.oTimer > 1 then
        obj_mark_for_deletion(o)
    end
end

SHOCK_ROCKET_ACT_ARMED               = 0x0
SHOCK_ROCKET_ACT_MOVE                = 0x1
SHOCK_ROCKET_ACT_WAIT_BEFORE_QUITING = 0x2

local DELAY                          = 30

-- Define shock rocket hitbox
sShockRocketHitbox                   = {
    interactType = 0,
    downOffset = 50,
    damageOrCoinValue = 0,
    health = 1,
    numLootCoins = 0,
    radius = 100,
    height = 100,
    hurtboxRadius = 100,
    hurtboxHeight = 100,
}

function shock_rocket_stick_control(obj)
    local m = gMarioStates[network_local_index_from_global(obj.parentObj.globalPlayerIndex)]
    local stickX = m.controller.rawStickX
    local stickY = -m.controller.rawStickY

    --[[local config = gSaveBuffer.menuData.config[SETTINGS_ROCKET_CONTROLS]
    if config == 1 then
        stickX = -stickX
    elseif config == 2 then
        stickY = -stickY
    end
]] --TODO
    if math.abs(stickX) < 10 then stickX = 0 end
    if math.abs(stickY) < 10 then stickY = 0 end

    local slow = 1 --ability_chronos_current_slow_factor() todo

    if find_water_level(obj.oPosX, obj.oPosZ) > obj.oPosY then
        obj.oMoveAngleYaw = obj.oMoveAngleYaw - 5 * stickX * slow
        obj.oMoveAnglePitch = obj.oMoveAnglePitch - 5 * stickY * slow
        obj.oForwardVel = 20
    else
        obj.oMoveAngleYaw = obj.oMoveAngleYaw - 10 * stickX * slow
        obj.oMoveAnglePitch = obj.oMoveAnglePitch - 10 * stickY * slow
        obj.oForwardVel = 30
    end

    if obj.oMoveAnglePitch > 0x3FF0 then obj.oMoveAnglePitch = 0x3FF0 end
    if obj.oMoveAnglePitch < -0x3FF0 then obj.oMoveAnglePitch = -0x3FF0 end
end

function shock_rocket_quit(obj)
    local m = gMarioStates[network_local_index_from_global(obj.parentObj.globalPlayerIndex)]
    obj_mark_for_deletion(obj)

    if (m.action & ACT_FLAG_INVULNERABLE) == 0 then
        m.actionState = 2
    end

    if m == gMarioStates[0] then
        camera_unfreeze()
        m.marioObj.oBooParentBigBoo = nil
    end

    -- gLakituState.mode = obj.oPreviousLakituCamMode
end

---@param obj Object
function shock_rocket_armed(obj)
    local m = gMarioStates[network_local_index_from_global(obj.parentObj.globalPlayerIndex)]
    shock_rocket_stick_control(obj)
    --obj_set_model(gMarioStates[0].marioObj, MODEL_NONE)

    obj.oPosX = m.pos.x
    obj.oPosY = m.pos.y + 100
    obj.oPosZ = m.pos.z

    if obj.oTimer == 0 then
        m.usedObj = obj
        -- obj.oPreviousLakituCamMode = gLakituState.mode
        --  gLakituState.mode = CAMERA_MODE_SHOCK_ROCKET
    end

    if m.controller.buttonPressed & B_BUTTON ~= 0 then
        cur_obj_play_sound_2(SOUND_OBJ_POUNDING_CANNON)
        cur_obj_shake_screen(SHAKE_POS_SMALL)
        obj_set_hitbox(obj, sShockRocketHitbox)
        obj.oAction = obj.oAction + 1
    end

    if (m.action & ACT_FLAG_INVULNERABLE) ~= 0 then
        obj.oAction = 2
    end

    if obj.oTimer > 5 and (m.action ~= ACT_IDLE or m.controller.buttonPressed & L_TRIG ~= 0) then
        shock_rocket_quit(obj)
    end
end

function shock_rocket_move(obj)
    if obj.oTimer == 5 then
        obj.oInteractType = INTERACT_DAMAGE
    end
    local m = gMarioStates[network_local_index_from_global(obj.parentObj.globalPlayerIndex)]
    obj_attack_collided_from_other_object(obj)
    cur_obj_update_floor_and_walls()
    play_sound(SOUND_AIR_BOBOMB_LIT_FUSE, gGlobalSoundSource)

    shock_rocket_stick_control(obj)
    local slow = 1 --ability_chronos_current_slow_factor() todo

    obj.oPosX = obj.oPosX + sins(obj.oMoveAngleYaw) * coss(obj.oMoveAnglePitch) * obj.oForwardVel * slow
    obj.oPosY = obj.oPosY - sins(obj.oMoveAnglePitch) * obj.oForwardVel * slow
    obj.oPosZ = obj.oPosZ + coss(obj.oMoveAngleYaw) * coss(obj.oMoveAnglePitch) * obj.oForwardVel * slow

    obj.oMoveAngleRoll = sins(obj.oTimer * 0x1000) * degrees_to_sm64(1.0)

    if find_water_level(obj.oPosX, obj.oPosZ) > obj.oPosY then
        spawn_object(obj, E_MODEL_BUBBLE, bhvRocketSmoke)
    else
        spawn_object(obj, E_MODEL_SMOKE, bhvRocketSmoke)
    end

    local ceilHeight = find_ceil_height(obj.oPosX, obj.oPosY, obj.oPosZ)

    if obj.oTimer > 300
        or (obj.oMoveFlags & OBJ_MOVE_HIT_WALL ~= 0)
        or (obj.oPosY - obj.oFloorHeight < 35)
        or (ceilHeight - obj.oPosY < 25)
        or (obj.oInteractStatus & INT_STATUS_INTERACTED ~= 0)
        or (obj.numCollidedObjs > 0 and obj.oInteractType == INTERACT_DAMAGE)
        or (m.controller.buttonPressed & B_BUTTON ~= 0)
    then
        obj.oAction = obj.oAction + 1
    end

    set_mario_action(m, ACT_IDLE, 0);

    if m.action ~= ACT_IDLE then
        -- spawn_object(obj, E_MODEL_EXPLOSION, id_bhvExplosion)
        -- shock_rocket_quit(obj)
    end

    if m == gMarioStates[0] then
        camera_freeze()
        local yaw = obj.oMoveAngleYaw;
        local pitch = obj.oMoveAnglePitch;
        local cossPitch = coss(pitch);
        local camDecrement;
        if obj.oAction == SHOCK_ROCKET_ACT_ARMED then
            camDecrement = 150; --iming zoom
        elseif obj.oAction == SHOCK_ROCKET_ACT_MOVE then
            camDecrement = 100; --omving zoom
        elseif obj.oAction == SHOCK_ROCKET_ACT_WAIT_BEFORE_QUITING then
            camDecrement = 400; --uuiting zoom
        end


        local camOffset = {
            x = (sins(yaw) * cossPitch) *
                ((obj.oForwardVel --[[* ability_chronos_current_slow_factor()]]) - camDecrement),
            y = (sins(pitch)) * ((obj.oForwardVel --[[* ability_chronos_current_slow_factor()]]) + camDecrement),
            z = (coss(yaw) * cossPitch) *
                ((obj.oForwardVel --[[* ability_chronos_current_slow_factor()]]) - camDecrement)
        };
        local newPos = { x = 0, y = 0, z = 0 };

        vec3f_copy(gLakituState.focus, { x = obj.oPosX, y = obj.oPosY, z = obj.oPosZ });

        vec3f_copy(newPos, gLakituState.focus);
        vec3f_add(newPos, camOffset);
        vec3f_copy(gLakituState.pos, newPos);
    end
end

function shock_rocket_wait_before_quitting(obj)
    if obj.oTimer == 0 then
        spawn_object(obj, E_MODEL_EXPLOSION, id_bhvExplosion)
        cur_obj_disable()
        obj.oForwardVel = 0
    end

    if obj.oTimer == DELAY then
        shock_rocket_quit(obj)
    end
end

function bhv_shock_rocket_init(obj)
    obj.oFlags = obj.oFlags|OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW
    --network_init_object(obj, true, { "oAction", "oTimer", "oPosX", "oPosY", "oPosZ" })
end

function bhv_shock_rocket_loop(obj)
    --  djui_chat_message_create("Ec")
    if obj.oAction == SHOCK_ROCKET_ACT_ARMED then
        shock_rocket_armed(obj)
    elseif obj.oAction == SHOCK_ROCKET_ACT_MOVE then
        shock_rocket_move(obj)
    elseif obj.oAction == SHOCK_ROCKET_ACT_WAIT_BEFORE_QUITING then
        shock_rocket_wait_before_quitting(obj)
    end
end

function bhv_rocket_smoke_init(void)
    cur_obj_scale((random_float() * 2 + 2.0) / 15);
end
