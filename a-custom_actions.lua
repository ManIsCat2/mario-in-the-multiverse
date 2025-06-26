ACT_CUTSCENE_CONTROLLED = allocate_mario_action(ACT_GROUP_CUTSCENE)
ACT_ENTER_HUB_PIPE = allocate_mario_action(ACT_GROUP_CUTSCENE)
ACT_CUTTER_THROW_AIR = allocate_mario_action(ACT_GROUP_AIRBORNE)
ACT_CUTTER_DASH = allocate_mario_action(ACT_GROUP_MOVING)
ACT_BUBBLE_HAT_JUMP = allocate_mario_action(ACT_GROUP_AIRBORNE|ACT_FLAG_AIR)
ACT_SQUID = allocate_mario_action(ACT_FLAG_MOVING | ACT_FLAG_ALLOW_FIRST_PERSON | ACT_FLAG_ALLOW_FIRST_PERSON)

local function act_cutscene_controlled(m)
    vec3f_copy(m.marioObj.header.gfx.pos, m.pos)
    vec3s_set(m.marioObj.header.gfx.angle, 0, m.faceAngle.y, 0)
    return 0
end

local behImmuneToCutter = {
    bhvKingBobomb,
    bhvUkiki,
    bhvBowser,
    bhvMips,
    bhvBreakableBoxSmall,
    bhvJumpingBox,
    bhvPlum,
    bhvFdynamite,
    bhvChuckya,
}

function is_behavior_immune_to_cutter(behavior)
    for i = 1, #behImmuneToCutter do
        if behavior == behImmuneToCutter[i] then
            return true
        end
    end
    return false
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
        play_character_sound_if_no_flag(m, CHAR_SOUND_PUNCH_HOO, MARIO_ACTION_SOUND_PLAYED)
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
        spawn_object_relative2(0, 0, 100, 0, m.marioObj, MODEL_CUTTER_BLADE, bhvCutterBlade)
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
        set_mario_animation(m, MARIO_ANIM_A_POSE)
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

local function act_bubble_hat_jump(m)
    if m.actionTimer == 0 then
        play_sound(SOUND_ACTION_SPIN, m.marioObj.header.gfx.cameraToObject)
    end

    if m.actionTimer < 30 and m.vel.y < 10.0 then
        m.vel.y = m.vel.y + 5.0 * ((30.0 - m.actionTimer) / 30.0)
    end

    if m.vel.y < -10.0 and m.actionTimer < 120 then
        m.vel.y = -10.0
    end

    m.vel.y = m.vel.y + 0.5

    cur_obj_play_sound_1(SOUND_ENV_WIND1)

    update_air_with_turn(m)
    common_air_action_step(m, ACT_JUMP_LAND, MARIO_ANIM_HANG_ON_OWL, AIR_STEP_CHECK_LEDGE_GRAB)

    if m.forwardVel < 0.0 then
        m.forwardVel = 0.0
    end

    if m.actionTimer >= 10 and (m.input & (INPUT_B_PRESSED | INPUT_A_PRESSED)) ~= 0 then
        m.input = m.input|INPUT_B_PRESSED
        return set_mario_action(m, ACT_FREEFALL, 0)
    end

    -- set_mario_animation(m, MARIO_ANIM_MISSING_CAP)
    -- m.marioObj.header.gfx.animInfo.animFrame = 25

    m.actionTimer = m.actionTimer + 1
    return 0
end

function act_squid(m)
    local mitm = gPlayerSyncTable[m.playerIndex]

    m.marioObj.header.gfx.animInfo.animAccel = 65536
    smlua_anim_util_set_animation(m.marioObj, "mario_anim_squid")

    local surfie
    local wall
    local intend_x, intend_y, intend_z
    local fheight
    local v3 = { x = 0, y = 0, z = 0 }
    local wall_angle

    local ray_vec = { 0, 0, 0 }
    local ray_origin = { x = 0, y = 0, z = 0 }
    local ray_hit_pos = { x = 0, y = 0, z = 0 }
    local ray_surface
    local gPlayer1Controller = m.controller


    if m.actionState == 0 then -- out of the ink
        perform_air_step(m, 0)

        fheight, surfie = find_floor_height(m.pos.x, m.pos.y, m.pos.z), collision_find_floor(m.pos.x, m.pos.y, m.pos.z)
        if surfie and fheight + 10.0 > m.pos.y and surfie.type == SURFACE_SQUID_INK then
            mitm.squid_x_vel, mitm.squid_y_vel, mitm.squid_z_vel = 0.0, 0.0, 0.0
            m.actionState = 1
            vec3f_set(m.vel, 0, 0, 0)
        end
        if surfie and fheight + 10.0 > m.pos.y and m.actionState == 0 then
            stationary_ground_step(m)
        end
    elseif m.actionState == 1 then -- ink ground move
        mitm.squid_x_vel = approach_f32_asymptotic(mitm.squid_x_vel, sins(m.intendedYaw) * m.intendedMag, 0.2)
        mitm.squid_z_vel = approach_f32_asymptotic(mitm.squid_z_vel, coss(m.intendedYaw) * m.intendedMag, 0.2)

        mitm.squid_goop_timer = mitm.squid_goop_timer + (math.abs(mitm.squid_x_vel) / 60.0) +
            (math.abs(mitm.squid_z_vel) / 60.0)

        intend_x = m.pos.x + mitm.squid_x_vel
        intend_z = m.pos.z + mitm.squid_z_vel

        v3.x = intend_x
        v3.y = m.pos.y
        v3.z = intend_z

        wall = resolve_and_return_wall_collisions(v3, 150.0, 50.0)

        if wall and wall.type == SURFACE_SQUID_INK then
            m.pos.x = intend_x
            m.pos.y = m.pos.y + 10.0
            m.pos.z = intend_z
            --mitm.squid_wall = wall
            mitm.sqwall_normalx = wall.normal.x
            mitm.sqwall_normalz = wall.normal.z
            m.actionState = 2
            mitm.squid_y_vel = 0.0
            return false
        end

        fheight, surfie = find_floor_height(m.pos.x, m.pos.y, m.pos.z),
            collision_find_floor(intend_x, m.pos.y + 15.0, intend_z)
        if surfie then
            if fheight > m.pos.y - 40.0 and surfie.type == SURFACE_SQUID_INK then
                m.pos.x = intend_x
                m.pos.y = fheight
                m.pos.z = intend_z
                m.faceAngle.y = m.intendedYaw
            else
                wall = resolve_and_return_wall_collisions(v3, -40.0, 120.0)
                if wall and wall.type == SURFACE_SQUID_INK then
                    m.pos.y = m.pos.y - 10.0
                    --mitm.squid_wall = wall
                    mitm.sqwall_normalx = wall.normal.x
                    mitm.sqwall_normalz = wall.normal.z
                    m.actionState = 2
                    mitm.squid_y_vel = 0.0
                    return false
                end
            end
        end

        vec3f_copy(m.marioObj.header.gfx.pos, m.pos)
        vec3s_set(m.marioObj.header.gfx.angle, 0, atan2s(mitm.squid_z_vel, mitm.squid_x_vel), 0)
    elseif m.actionState == 2 then -- ink wall move
        mitm.squid_x_vel = approach_f32_asymptotic(mitm.squid_x_vel, sins(m.intendedYaw) * m.intendedMag, 0.2)
        mitm.squid_z_vel = approach_f32_asymptotic(mitm.squid_z_vel, coss(m.intendedYaw) * m.intendedMag, 0.2)

        m.pos.x = m.pos.x + mitm.squid_x_vel
        m.pos.z = m.pos.z + mitm.squid_z_vel

        -- vec3f_copy(ray_origin, m.pos)
        ray_origin.x = m.pos.x
        ray_origin.y = m.pos.y
        ray_origin.z = m.pos.z

        ray_origin.x = ray_origin.x + mitm.sqwall_normalx * 50.0
        ray_origin.y = ray_origin.y + 10.0
        ray_origin.z = ray_origin.z + mitm.sqwall_normalz * 50.0

        ray_vec[1] = mitm.sqwall_normalx * -120.0
        ray_vec[2] = 0.0
        ray_vec[3] = mitm.sqwall_normalz * -120.0

        local RAY = collision_find_surface_on_ray(ray_origin.x, ray_origin.y, ray_origin.z,
            ray_vec[1], ray_vec[2], ray_vec[3],
            2)

        ray_surface = RAY.surface
        vec3f_copy(ray_hit_pos, RAY.hitPos)

        if ray_surface and ray_surface.type == SURFACE_SQUID_INK then
            --mitm.squid_wall = ray_surface
            mitm.sqwall_normalx = ray_surface.normal.x
            mitm.sqwall_normalz = ray_surface.normal.z
            m.pos.x = ray_hit_pos.x + ray_surface.normal.x * 20.0
            m.pos.z = ray_hit_pos.z + ray_surface.normal.z * 20.0

            mitm.squid_y_vel = approach_f32_asymptotic(mitm.squid_y_vel, (gPlayer1Controller.rawStickY / 4.0), 0.2)
            intend_y = mitm.squid_y_vel
            m.pos.y = m.pos.y + intend_y

            wall_angle = atan2s(ray_surface.normal.z, ray_surface.normal.x)

            if ray_surface.object ~= nil then
                m.pos.y = m.pos.y + ray_surface.object.oVelY
            end

            vec3f_copy(m.marioObj.header.gfx.pos, m.pos)
            vec3s_set(m.marioObj.header.gfx.angle, -0x4000, wall_angle + 0x8000, 0)

            if intend_y < 0.0 then
                fheight, surfie = find_floor_height(m.pos.x, m.pos.y, m.pos.z),
                    collision_find_floor(m.pos.x + ray_surface.normal.x * 10.0, m.pos.y + 20.0,
                        m.pos.z + ray_surface.normal.z * 10.0)
                if surfie and fheight + 20.0 > m.pos.y then
                    m.pos.y = fheight
                    if surfie.type == SURFACE_SQUID_INK then
                        m.actionState = 1
                    else
                        m.vel.y = 0.0
                        m.actionState = 0
                    end
                end
            end

            mitm.squid_goop_timer = mitm.squid_goop_timer + (math.abs(mitm.squid_x_vel) / 60.0) +
                (math.abs(mitm.squid_z_vel) / 60.0) +
                (math.abs(mitm.squid_y_vel) / 60.0)
        else
            wall_angle = atan2s(mitm.sqwall_normalz, mitm.sqwall_normalx)
            fheight, surfie = find_floor_height(m.pos.x, m.pos.y, m.pos.z), collision_find_floor(
                m.pos.x + sins(wall_angle + 0x8000) * 40.0,
                m.pos.y + 20.0,
                m.pos.z + coss(wall_angle + 0x8000) * 40.0
            )
            if surfie and surfie.type == SURFACE_SQUID_INK then
                m.actionState = 1
                m.pos.x = m.pos.x + sins(wall_angle + 0x8000) * 20.0
                m.pos.y = fheight
                m.pos.z = m.pos.z + coss(wall_angle + 0x8000) * 20.0
            else
                m.vel.y = 0.0
                m.actionState = 0
            end
        end
    end

    if mitm.squid_goop_timer > 15.0 then
        mitm.squid_goop_timer = 0.0
        play_sound(SOUND_GENERAL_QUIET_BUBBLE2, gGlobalSoundSource)
    end

    if m.playerIndex == 0 then
        if not using_ability(m, ABILITY_SQUID) then
            gPlayerSyncTable[0].modelId = nil
            return set_mario_action(m, ACT_IDLE, 0)
        end
        gPlayerSyncTable[0].modelId = MODEL_SQUID
    end
    --end

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
            audio_stream_play(SOUND_ABILITY_CUTTER_DASH, false, 1)
            return ACT_CUTTER_DASH
        end
    end
end

hook_event(HOOK_BEFORE_SET_MARIO_ACTION, cutter_ability_overrides)

hook_mario_action(ACT_CUTTER_THROW_AIR, act_cutter_throw_air)
hook_mario_action(ACT_CUTSCENE_CONTROLLED, act_cutscene_controlled)
hook_mario_action(ACT_ENTER_HUB_PIPE, act_enter_hub_pipe)
hook_mario_action(ACT_CUTTER_DASH, act_cutter_dash, INT_KICK)
hook_mario_action(ACT_BUBBLE_HAT_JUMP, act_bubble_hat_jump)
hook_mario_action(ACT_SQUID, act_squid)
