const BehaviorScript bhvGBananaDee[] = {
	BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
	OR_INT(oFlags, OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
	SET_INTERACT_TYPE(INTERACT_TEXT),
	SET_HITBOX(130, 100),
	SET_INT(oInteractionSubtype, INT_SUBTYPE_NPC),
	//LOAD_ANIMATIONS(oAnimations, g_banana_dee_anims),
	//ANIMATE(0),
	BEGIN_LOOP(),
        CALL_NATIVE(bhv_npc_loop),
		SET_INT(oIntangibleTimer, 0),
		SET_INT(oInteractStatus, 0),
	END_LOOP(),
};

const BehaviorScript bhvLevelPipe[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(level_pipe_collision),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(level_pipe_init),
    BEGIN_LOOP(),
        CALL_NATIVE(level_pipe_loop),
    END_LOOP(),
};

const BehaviorScript bhvGSpring[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(g_spring_collision),
    SET_FLOAT(oDrawingDistance, 16000),
    CALL_NATIVE(bhv_g_spring_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_spring_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvGWaddleDee[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW )),
    //LOAD_ANIMATIONS(oAnimations, g_waddle_dee_anims),
    SET_HOME(),
    //SET_FLOAT(oDrawingDistance, 16000),
    //ANIMATE(0),
    CALL_NATIVE(bhv_g_waddle_dee_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_waddle_dee_loop),
    END_LOOP(),
};

const BehaviorScript bhvGAttachedRope[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_g_attached_rope_init),
    //SET_FLOAT(oDrawingDistance, 16000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_attached_rope_loop),
    END_LOOP(),
};

const BehaviorScript bhvHubPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(hub_platform_collision),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    //SET_FLOAT(oDrawingDistance, 20000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hub_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvGBrontoBurt[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    //LOAD_ANIMATIONS(oAnimations, g_bronto_burt_anims),
    SET_HOME(),
    //SET_FLOAT(oDrawingDistance, 16000),
    //ANIMATE(0),
    CALL_NATIVE(bhv_g_bronto_burt_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_bronto_burt_loop),
    END_LOOP(),
};

const BehaviorScript bhvGCannon[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_COLLISION_DATA(g_cannon_collision),
    //SET_FLOAT(oDrawingDistance, 16000),
    CALL_NATIVE(bhv_g_cannon_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_cannon_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvGAttachedBlock[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(g_fixed_block_collision),
    SET_FLOAT(oCollisionDistance, 3000),
    CALL_NATIVE(bhv_g_attached_block_init),
    //SET_FLOAT(oDrawingDistance, 16000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_attached_block_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvCutterBlade[] = {
    BEGIN(OBJ_LIST_DESTRUCTIVE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    SET_HOME(),
    CALL_NATIVE(bhv_cutter_blade_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cutter_blade_loop),
    END_LOOP(),
};

const BehaviorScript bhvStarProjectile[] = {
    BEGIN(OBJ_LIST_DESTRUCTIVE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    SET_HOME(),
    CALL_NATIVE(bhv_star_projectile_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_star_projectile_loop),
    END_LOOP(),
};

const BehaviorScript bhvLevelGCutscenes[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_level_g_cutscenes_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_level_g_cutscenes_loop),
    END_LOOP(),
};

const BehaviorScript bhvStarDrop[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_star_drop_init),
    SET_FLOAT(oDrawingDistance, 16000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_star_drop_loop),
    END_LOOP(),
};

const BehaviorScript bhvAbilityUnlock[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_FLOAT(oGraphYOffset, 100),
    CALL_NATIVE(bhv_ability_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ability),
    END_LOOP(),
};

const BehaviorScript bhvGCutRock[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(g_cut_rock_collision),
    SET_FLOAT(oDrawingDistance, 16000),
    CALL_NATIVE(bhv_g_cut_rock_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_cut_rock_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvGCannonSwitch[] = {
    BEGIN(OBJ_LIST_SURFACE),
    // Floor switch - common:
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),//DO OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW
    LOAD_COLLISION_DATA(purple_switch_seg8_collision_0800C7A8),
    SET_FLOAT(oDrawingDistance, 16000),
    SET_INT(oIntangibleTimer, 0),//--E
    SET_HITBOX(/*Radius*/ 160, /*Height*/ 100),//--E
    CALL_NATIVE(bhv_g_cannon_switch_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_cannon_switch_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvCollectablePainting[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_collectable_painting),
    END_LOOP(),
};

const BehaviorScript bhvGMovingPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL)),
    LOAD_COLLISION_DATA(g_moving_platform_collision),
    SET_FLOAT(oDrawingDistance, 20000),
    CALL_NATIVE(bhv_g_moving_platform_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_moving_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvJelly[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    //LOAD_ANIMATIONS(oAnimations, jelly_anims),
    CALL_NATIVE(jelly_init),
    //ANIMATE(0),
    BEGIN_LOOP(),
        CALL_NATIVE(jelly_loop),
    END_LOOP(),
};

const BehaviorScript bhvTikiBox[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(tikibox_collision),
    SCALE(0, 150),
    CALL_NATIVE(tiki_box_init),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(tiki_box_loop),
    END_LOOP(),
};

const BehaviorScript bhvTramp[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(tramp_collision),
    //SET_FLOAT(oDrawingDistance, 9000.0f),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(trampoline_loop),
    END_LOOP(), 
};

const BehaviorScript bhvAcage[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(a_cage_collision),
    //SET_FLOAT(oDrawingDistance, 9000.0f),
    //SET_FLOAT(oCollisionDistance, 9000.0f),
    SET_HOME(),
    CALL_NATIVE(a_cage_init),
    BEGIN_LOOP(),
        CALL_NATIVE(a_cage_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(), 
};

const BehaviorScript bhvFloatingCheckerPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(floating_checker_platform_collision),
    //ANIMATE(0),
    SCALE(0, 160),
    //LOAD_ANIMATIONS(oAnimations, floating_checker_platform_anims),
    SET_FLOAT(oDrawingDistance, 8000),
    BEGIN_LOOP(),
        CALL_NATIVE(fcp_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTaxiStop[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(taxistop_collision),
    SCALE(0, 200),
    SET_FLOAT(oDrawingDistance, 30000),
    BEGIN_LOOP(),
        CALL_NATIVE(taxistop_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvtsBoat[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    //LOAD_ANIMATIONS(oAnimations, boat_anims),
    //ANIMATE(0),
    SCALE(0, 200),
    BEGIN_LOOP(),
        CALL_NATIVE(tsboat_loop),
    END_LOOP(),
};

const BehaviorScript bhvFightWavesManager[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_fight_waves_manager_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fight_waves_manager_loop),
    END_LOOP(),
};

const BehaviorScript bhvOctoball[] = {
    BEGIN(OBJ_LIST_DESTRUCTIVE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    SET_INT(oIntangibleTimer, 0),
    SET_FLOAT(oGraphYOffset, 85),
    SCALE(0, 85),
    SET_HOME(),
    CALL_NATIVE(bhv_octoball_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_octoball_loop),
    END_LOOP(),
};

const BehaviorScript bhvOctoballWaves[] = {
    BEGIN(OBJ_LIST_DESTRUCTIVE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    SET_INT(oIntangibleTimer, 0),
    SET_FLOAT(oGraphYOffset, 85),
    SCALE(0, 85),
    SET_HOME(),
    CALL_NATIVE(bhv_octoball_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_octoball_loop),
    END_LOOP(),
};

const BehaviorScript bhvPaintStain[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    DROP_TO_FLOOR(),
    SET_INT(oOpacity, 255),
    CALL_NATIVE(bhv_paint_stain_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_paint_stain_loop),
    END_LOOP(),
};

const BehaviorScript bhvInkMovingPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(ink_moving_platform_collision),
    //SET_FLOAT(oCollisionDistance, 1000),
    //SET_FLOAT(oDrawingDistance, 10000),
    CALL_NATIVE(bhv_ink_moving_platform_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ink_moving_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvPaintGun[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE)),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_NOT_GRABBABLE),
    SET_INT(oAnimState, 1),
    CALL_NATIVE(bhv_paint_gun_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_paint_gun_loop),
        SET_INT(oIntangibleTimer, 0),
    END_LOOP(),
};

const BehaviorScript bhvPaintBullet[] = {
    BEGIN(OBJ_LIST_DESTRUCTIVE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oDrawingDistance, 8000),
    SET_FLOAT(oCollisionDistance, 500),
    SET_FLOAT(oForwardVel, 70),
    SET_INT(oWallHitboxRadius, 40),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_paint_bullet_loop),
    END_LOOP(),
};

const BehaviorScript bhvRotatingFunkyPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_COLLISION_DATA(funky_road_collision),
    SET_FLOAT(oDrawingDistance, 5000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rotating_funky_platform),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvNitroBox[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(oDamageOrCoinValue, 99),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    SET_HOME(),
    SET_HITBOX_WITH_OFFSET( 150,150, 0),
    CALL_NATIVE(bhv_nitro_box_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_bowser_bomb_loop),
        CALL_NATIVE(bhv_nitro_box_loop),
    END_LOOP(),
};

const BehaviorScript bhvMovingFunkyPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_COLLISION_DATA(funky_road_collision),
    SET_FLOAT(oDrawingDistance, 5000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_moving_funky_platform),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBhButton[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(bh_red_button_collision),
    CALL_NATIVE(bridgesbutton_init),
    BEGIN_LOOP(),
        CALL_NATIVE(button_for_bridge_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBhButton2[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(bh_red_button_collision),
    CALL_NATIVE(bridgesbutton_init),
    BEGIN_LOOP(),
        CALL_NATIVE(button_for_bridge_loop_2),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

extern const Collision bhbridge_collision[];
extern const struct Animation *const bhbridge_anims[];
const BehaviorScript bhvRBridge[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(bhbridge_collision),
    //LOAD_ANIMATIONS(oAnimations, bhbridge_anims),
    //ANIMATE(0),
    CALL_NATIVE(bridgesbutton_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bridge_loop),
        //CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

extern const Collision a_plank_collision[];
extern const struct Animation *const a_plank_anims[];
const BehaviorScript bhvRPlank[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    //LOAD_ANIMATIONS(oAnimations, a_plank_anims),
    //ANIMATE(0),
    CALL_NATIVE(bridgesbutton_init),
    LOAD_COLLISION_DATA(a_plank_collision),
    BEGIN_LOOP(),
        //CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bridge2_loop),
    END_LOOP(),
};

const BehaviorScript bhvNitroBoom[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_nitro_boom_loop),
    END_LOOP(),
};

const BehaviorScript bhvStarPieceSwitch[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),//--E
    LOAD_COLLISION_DATA(blue_coin_switch_seg8_collision_08000E98),
    SET_INT(oIntangibleTimer, 0),//--E
    SET_HITBOX(/*Radius*/ 120, /*Height*/ 100),//--E
    SET_INT(oAnimState, 1),
    SET_HOME(),//prevent fucking the bcs with timeslow
    CALL_NATIVE(bhv_star_piece_switch_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_star_piece_switch_loop),
    END_LOOP(),
};

const BehaviorScript bhvStarPiece[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    CALL_NATIVE(bhv_star_piece_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_star_piece_loop),
    END_LOOP(),
};

const BehaviorScript bhvCrane[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW)),
    CALL_NATIVE(bhv_crane_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_crane_loop),
    END_LOOP(),
};

const BehaviorScript bhvCraneHead[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_crane_head_loop),
    END_LOOP(),
};

const BehaviorScript bhvCraneArrowController[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_crane_arrow_controller_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_crane_arrow_controller_loop),
    END_LOOP(),
};

const BehaviorScript bhvCraneArrow[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(crane_arrow_collision),
    DROP_TO_FLOOR(),
    CALL_NATIVE(bhv_crane_arrow_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_crane_arrow_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvCraneRock[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oDrawingDistance, 9000),
    CALL_NATIVE(bhv_crane_rock_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_crane_rock_loop),
    END_LOOP(),
};

const BehaviorScript bhvCheckpointFlag[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    // LOAD_ANIMATIONS(oAnimations, checkpoint_flag_anims),
    SCALE(0, 140),
    // ANIMATE(0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_checkpoint_flag),
    END_LOOP(),
};

const BehaviorScript bhvFLaser[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_star_piece_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_f_laser),
    END_LOOP(),
};

const BehaviorScript bhvGadgetAim[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    CALL_NATIVE(bhv_star_piece_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_gadget_aim),
    END_LOOP(),
};

/* these are behavior functions from behavior_data.c in mario in the multiverse
extern void bhv_hub_platform_loop(void);

extern void bhv_shopitem_loop(void);
const BehaviorScript bhvShopItem[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_FLOAT(oDrawingDistance, 20000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_shopitem_loop),
    END_LOOP(),
};

extern void bhv_shop_controller(void);
const BehaviorScript bhvShopController[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_shop_controller),
    END_LOOP(),
};

extern void bhv_ability(void);

const BehaviorScript bhvCheckpointFlag[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    //LOAD_ANIMATIONS(oAnimations, checkpoint_flag_anims),
    SCALE(/*Unused*\ 0, /*Field*\ 140),
    //ANIMATE(0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_checkpoint_flag),
    END_LOOP(),
};

const BehaviorScript bhvFlipswitch[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET),
    LOAD_COLLISION_DATA(flipswitch_collision),
    SET_FLOAT(oDrawingDistance, 20000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_flipswitch),
    END_LOOP(),
};

const BehaviorScript bhvNoteblock[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(noteblock_collision),
    SET_FLOAT(oDrawingDistance, 4000),
    SET_FLOAT(oCollisionDistance, 1000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_noteblock),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvDashBoosterParticle[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_dash_booster_particle),
    END_LOOP(),
};

const BehaviorScript bhvCutsceneManager[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    BEGIN_LOOP(),
        CALL_NATIVE(cm_manager_object_loop),
    END_LOOP(),
};
const BehaviorScript bhvCutsceneCamera[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(cm_camera_object_loop),
    END_LOOP(),
};

const BehaviorScript bhvBioshockFloaty[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(floaty_collision),
    SET_FLOAT(oFloatingPlatformHeightOffset, 64),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_floating_platform_b_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvGauge[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_NO_DREAM_COMET),
    LOAD_COLLISION_DATA(gauge_collision),
    LOAD_ANIMATIONS(oAnimations, gauge_anims),
    ANIMATE(0),
    CALL_NATIVE(bhv_gauge_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_gauge_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWaterfallHidden[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE )),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_waterfall_hidden_loop),
    END_LOOP(),
};

const BehaviorScript bhvWaterfall[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE )),
    LOAD_COLLISION_DATA(waterfall_collision),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_waterfall_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvDebris[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE )),
    LOAD_COLLISION_DATA(debris_collision),
    SET_FLOAT(oDrawingDistance, 7000),
    CALL_NATIVE(bhv_debris_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_debris_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvAirlock[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE )),
    LOAD_COLLISION_DATA(airlock_collision),
    SET_FLOAT(oDrawingDistance, 20000),
    SET_HOME(),
    CALL_NATIVE(bhv_airlock_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_airlock_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvAirlockButton[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE )),
    LOAD_COLLISION_DATA(airlock_button_collision),
    SET_FLOAT(oDrawingDistance, 7000),
    CALL_NATIVE(bhv_airlock_button_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_airlock_button_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvAirlockWater[] = {
    BEGIN(OBJ_LIST_SPAWNER),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(airlock_water_collision),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_airlock_water_loop),
    END_LOOP(),
};

const BehaviorScript bhvBigDaddy[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_ANIMATIONS(oAnimations, bigdaddy_anims),
    ANIMATE(2),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 30, /*Gravity*\ -400, /*Bounciness*\ -50, /*Drag strength*\ 0, /*Friction*\ 0, /*Buoyancy*\ 0, /*Unused*\ 0, 0),
    SET_HOME(),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_HITBOX(/*Radius*\ 170, /*Height*\ 420),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_big_daddy_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_big_daddy_loop),
    END_LOOP(),
};

const BehaviorScript bhvLittleSister[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, little_sister_anims),
    ANIMATE(0),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 30, /*Gravity*\ -400, /*Bounciness*\ 0, /*Drag strength*\ 0, /*Friction*\ 0, /*Buoyancy*\ 200, /*Unused*\ 0, 0),
    SET_INT(oInteractType, INTERACT_TEXT),
    //SET_INT(oInteractionSubtype, INT_SUBTYPE_HOLDABLE_NPC),
    SET_INT(oIntangibleTimer, 0),
    SET_HITBOX(/*Radius*\ 55, /*Height*\ 230),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_little_sister_loop),
    END_LOOP(),
};

const BehaviorScript bhvCrusher[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(crusher_collision),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 30, /*Gravity*\ 0, /*Bounciness*\ -50, /*Drag strength*\ 0, /*Friction*\ 0, /*Buoyancy*\ 0, /*Unused*\ 0, 0),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    SET_HITBOX(/*Radius*\ 243, /*Height*\ 706),
    SET_FLOAT(oDrawingDistance, 4000),
    CALL_NATIVE(bhv_crusher_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_crusher_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTurretBody[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    SET_HITBOX(/*Radius*\ 110, /*Height*\ 210),
    SET_INTERACT_TYPE(INTERACT_SPINY_WALKING),
    SET_FLOAT(oDamageOrCoinValue, 2),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 40, /*Gravity*\ -400, /*Bounciness*\ -50, /*Drag strength*\ 1000, /*Friction*\ 1000, /*Buoyancy*\ 200, /*Unused*\ 0, 0),
    CALL_NATIVE(bhv_turret_body_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_turret_body_loop),
    END_LOOP(),
};

const BehaviorScript bhvTurretHead[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags,(OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, turret_head_heavy_anims),
    CALL_NATIVE(bhv_turret_head_init),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_turret_head_loop),
    END_LOOP(),
};

const BehaviorScript bhvTurretHeavy[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags,(OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, turret_head_heavy_anims),
    CALL_NATIVE(bhv_turret_head_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_turret_head_loop),
    END_LOOP(),
};

const BehaviorScript bhvTurretPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(turret_platform_collision),
    OR_INT(oFlags,(OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_ACTIVE_FROM_AFAR)),
    SET_FLOAT(oDrawingDistance, 4000),
    CALL_NATIVE(bhv_turret_platform_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_turret_platform),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTurretCover[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags,(OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_ACTIVE_FROM_AFAR)),
    //LOAD_COLLISION_DATA(turret_cover_collision),
    SET_FLOAT(oDrawingDistance, 4000),
    CALL_NATIVE(bhv_turret_cover_init),
    BEGIN_LOOP(),
        //CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_turret_cover),
    END_LOOP(),
};

const BehaviorScript bhvTurretPanel[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags,(OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_ACTIVE_FROM_AFAR)),
    SET_FLOAT(oDrawingDistance, 4000),
    LOAD_COLLISION_DATA(turret_panel_collision),
    CALL_NATIVE(bhv_turret_panel_init),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_turret_panel),
    END_LOOP(),
};

const BehaviorScript bhvGate[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags,(OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_ACTIVE_FROM_AFAR)),
    SET_HOME(),
    LOAD_COLLISION_DATA(bgate_collision),
    SET_FLOAT(oDrawingDistance, 4000),
    CALL_NATIVE(bhv_gate_init),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_gate),
    END_LOOP(),
};

const BehaviorScript bhvAlarm[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_ANIMATIONS(oAnimations, alarm_anims),
    ANIMATE(0),
    SET_FLOAT(oDrawingDistance, 4000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_alarm),
    END_LOOP(),
};

const BehaviorScript bhvCork[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(megacork_collision),
    SET_FLOAT(oDrawingDistance, 6000),
    //CALL_NATIVE(bhv_cork_init),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_cork),
    END_LOOP(),
};

extern void bhv_watertemple_init(void);
const BehaviorScript bhvWaterTemple[] = {
    BEGIN(OBJ_LIST_SPAWNER),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(watertemple_collision),
    SET_HOME(),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    CALL_NATIVE(bhv_watertemple_init),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_watertemple),
    END_LOOP(),
};

const BehaviorScript bhvBossDaddy[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_Y_WITH_TERMINAL_VEL | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_ANIMATIONS(oAnimations, bigdaddy_anims),
    ANIMATE(2),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 170, /*Gravity*\ -400, /*Bounciness*\ 0, /*Drag strength*\ 5000, /*Friction*\ 5000, /*Buoyancy*\ 0, /*Unused*\ 0, 0),
    SET_HITBOX(/*Radius*\ 170, /*Height*\ 420),
    SET_INTERACT_TYPE(INTERACT_BULLY),
    SET_FLOAT(oDrawingDistance, 6000),
    SET_HOME(),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_boss_daddy_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_boss_daddy),
    END_LOOP(),
};

const BehaviorScript bhvSafeExplosion[] = {
    BEGIN(OBJ_LIST_SPAWNER),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_INTERACT_TYPE(INTERACT_NONE),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    CALL_NATIVE(bhv_explosion_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_explosion_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};
/* GROUP B END *\

/* GROUP E START *\

//--Level
const BehaviorScript bhvE_PistolGuy[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_E__SG_ENEMY)),
    SET_INT(oBehParams2ndByte, 0),
    GOTO(bhvE_Enemy + 1),
};

const BehaviorScript bhvE_ChaingunGuy[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_E__SG_ENEMY)),
    SET_INT(oBehParams2ndByte, 1),
    GOTO(bhvE_Enemy + 1),
};

const BehaviorScript bhvE_Caco[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_E__SG_ENEMY)),
    SET_INT(oBehParams2ndByte, 3),
    GOTO(bhvE_Enemy + 1),
};

const BehaviorScript bhvIntroCloth[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
    END_LOOP(),
};

const BehaviorScript bhvIntroBreakdoor[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
    END_LOOP(),
};

const BehaviorScript bhvE_Door[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_E__SG_COLLISION_CUSTOM)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_e__door),
    END_LOOP(),
};

const BehaviorScript bhvE_Key[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_E__SG_CUSTOM)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_e__key),
    END_LOOP(),
};

const BehaviorScript bhvE_KeyCollect[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_e__key_collect),
    END_LOOP(),
};

const BehaviorScript bhvE_Elevator[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_e__elevator),
    END_LOOP(),
};
const BehaviorScript bhvE_ElevatorBase[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_COLLISION_DATA(e_elevator_base_collision),
    SET_FLOAT(oDrawingDistance, 20000),
    CALL_NATIVE(load_object_static_model),
    BREAK(),
};

const BehaviorScript bhvE_Candelabra[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_E__SG_CUSTOM)),
    CALL_NATIVE(bhv_e__candelabra),
    BREAK(),
};

const BehaviorScript bhvE_Switch[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_E__SG_COLLISION_CUSTOM | OBJ_FLAG_NO_DREAM_COMET)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_e__switch),
    END_LOOP(),
};

const BehaviorScript bhvE_Teleport[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_e__teleport),
    END_LOOP(),
};
const BehaviorScript bhvE_TeleportEffect[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_e__teleport_effect),
    END_LOOP(),
};
const BehaviorScript bhvE_Medkit[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_E__SG_CUSTOM)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_e__medkit),
    END_LOOP(),
};

const BehaviorScript bhvE_Tutorial[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_e__tutorial),
    END_LOOP(),
};
const BehaviorScript bhvE_Target[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(e_tb_collision),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_e__target),
    END_LOOP(),
};

//--Ability
/* GROUP E END *\

const BehaviorScript bhvIntroPeach[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oOpacity, 255),
    LOAD_ANIMATIONS(oAnimations, peach_seg5_anims_0501C41C),
    ANIMATE(PEACH_ANIM_WAVING),
    BEGIN_LOOP(),
    END_LOOP(),
};
const BehaviorScript bhvIntroToad[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, toad_seg6_anims_0600FB58),
    ANIMATE(TOAD_ANIM_WEST_WAVING_BOTH_ARMS),
    SET_INT(oOpacity, 255),
    BEGIN_LOOP(),
    END_LOOP(),
};
const BehaviorScript bhvIntroEgadd[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, egadd_anims),
    ANIMATE(0),
    BEGIN_LOOP(),
    END_LOOP(),
};
const BehaviorScript bhvIntroMachine[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, machine_anims),
    ANIMATE(0),
    SET_INT(oOpacity, 0),
    BEGIN_LOOP(),
    END_LOOP(),
};

const BehaviorScript bhvIntroBowser[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, wedser_anims),
    ANIMATE(1),
    DROP_TO_FLOOR(),
    BEGIN_LOOP(),
    END_LOOP(),
};

const BehaviorScript bhvEndBowser[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, endser_anims),
    ANIMATE(0),
    BEGIN_LOOP(),
    END_LOOP(),
};

/* GROUP F START *\

extern void bhv_layton_hint_loop(void);
const BehaviorScript bhvLayton[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, layton_anims),
    DROP_TO_FLOOR(),
    SCALE(0, 45),
    ANIMATE(0),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_NPC),
    SET_HITBOX(/*Radius*\ 100, /*Height*\ 250),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_layton_hint_loop),
    END_LOOP(),
};

extern void bhv_morshu_loop(void);
const BehaviorScript bhvMorshu[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    LOAD_ANIMATIONS(oAnimations, morshu_anims),
    DROP_TO_FLOOR(),
    ANIMATE(0),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_NPC),
    SET_HITBOX(/*Radius*\ 100, /*Height*\ 250),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_morshu_loop),
    END_LOOP(),
};

extern void bhv_music_menu_loop(void);
extern void bhv_redd_paintings_loop(void);
const BehaviorScript bhvRedd[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    LOAD_ANIMATIONS(oAnimations, redd_anims),
    DROP_TO_FLOOR(),
    ANIMATE(0),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_NPC),
    SET_HITBOX(/*Radius*\ 100, /*Height*\ 250),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_redd_paintings_loop),
    END_LOOP(),
};

const BehaviorScript bhvMumbo[] = {
	BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
	OR_INT(oFlags, OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, mumbo_anims),
    ANIMATE(0),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_NPC),
    SET_HITBOX(/*Radius*\ 175, /*Height*\ 250),
    SPAWN_CHILD(MODEL_SYNTHESIZER, bhvSynthesizer),
	BEGIN_LOOP(),
		SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_music_menu_loop),
	END_LOOP(),
};

const BehaviorScript bhvSynthesizer[] = {
	BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
	OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
	LOAD_COLLISION_DATA(synthesizer_collision),
	BEGIN_LOOP(),
		//CALL_NATIVE(load_object_collision_model),
	END_LOOP(),
};

/* GROUP A START *\
extern const struct Animation *const jelly_anims[];

extern const Collision jfplatform_collision[];
const BehaviorScript bhvJellyfishFieldsPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(jfplatform_collision),
    SET_FLOAT(oDrawingDistance, 8000),
    BEGIN_LOOP(),
        CALL_NATIVE(jfplatform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

extern const Collision taxistop_collision[];
extern const struct Animation *const boat_anims[];

extern const Collision tikibox_collision[];

extern const Collision tramp_collision[];

extern const Collision floating_checker_platform_collision[];
extern const struct Animation *const floating_checker_platform_anims[];

extern const struct Animation *const kingjelly_anims[];
const BehaviorScript bhvKingJelly[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_NO_DREAM_COMET)),
    SCALE(0, 400),
    ANIMATE(0),
    LOAD_ANIMATIONS(oAnimations, kingjelly_anims),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(king_jelly_boss_loop),
    END_LOOP(),
};

const BehaviorScript bhvKingJellyZap[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_ENEMY)),//--E
    LOAD_ANIMATIONS(oAnimations, dAmpAnimsList),
    ANIMATE(AMP_ANIM_DEFAULT),
    SCALE(0, 600),
    BEGIN_LOOP(),
    END_LOOP(),
};

const BehaviorScript bhvKingJellyShock[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_ENEMY)),
    SCALE(0, 120),
    BEGIN_LOOP(),
        //CALL_NATIVE(king_jelly_boss_shock),
    END_LOOP(),
};

extern const struct Animation *const squidward_anims[];
const BehaviorScript bhvSquidward[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    ANIMATE(0),
    LOAD_ANIMATIONS(oAnimations, squidward_anims),
    CALL_NATIVE(squidward_init),
    SCALE(0, 230),
    BEGIN_LOOP(),
        CALL_NATIVE(squidward_loop),
        SET_INT(oInteractStatus, 0),
    END_LOOP(),
};

extern const Collision kktable_collision[];
const BehaviorScript bhvKKTable[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(kktable_collision),
    SCALE(0, 180),
    CALL_NATIVE(load_object_static_model),
    BEGIN_LOOP(),
        //CALL_NATIVE(kktable_loop),
    END_LOOP(),
};

extern const Collision kkb_collision[];
const BehaviorScript bhvKKB[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(kkb_collision),
    SCALE(0, 180),
    CALL_NATIVE(load_object_static_model),
    BEGIN_LOOP(),
        //CALL_NATIVE(kktable_loop),
    END_LOOP(),
};

extern const Collision bh_red_button_collision[];

const BehaviorScript bhvGooSwitch[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(bh_red_button_collision),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        //CALL_NATIVE(king_jelly_boss_goo_switch),
    END_LOOP(),
};

const BehaviorScript bhvSpawnJellyKJ[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_E__SG_ENEMY)),
    LOAD_ANIMATIONS(oAnimations, jelly_anims),
    ANIMATE(0),
    BEGIN_LOOP(),
        //CALL_NATIVE(king_jelly_boss_jelly),
    END_LOOP(),
};

const BehaviorScript bhvGooDrop[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        //CALL_NATIVE(king_jellyfish_goo_loop),
    END_LOOP(),
};

extern const Collision a_cage_collision[];
void a_cage_loop(void);

extern const Collision a_ufo_robot_collision[];
extern const struct Animation *const a_ufo_robot_anims[];
void a_ufo_robot_init(void);
void a_ufo_robot_loop(void);
const BehaviorScript bhvAUFORobot[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    LOAD_COLLISION_DATA(a_ufo_robot_collision),
    LOAD_ANIMATIONS(oAnimations, a_ufo_robot_anims),
    ANIMATE(0),
    CALL_NATIVE(a_ufo_robot_init),
    BEGIN_LOOP(),
        CALL_NATIVE(a_ufo_robot_loop),
    END_LOOP(),
};

void chum_bucket_cutscene_loop(void);
const BehaviorScript bhvChumBucketCutscene[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(chum_bucket_cutscene_loop),
    END_LOOP(),
};

void beat_em_up_object(void);
const BehaviorScript bhvBeatEmUpObject[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW)),
    BEGIN_LOOP(),
        CALL_NATIVE(beat_em_up_object),
    END_LOOP(),
};

extern const struct Animation *const a_ham_robot_anims[];
void ham_robot_init(void);
void ham_robot_loop(void);
const BehaviorScript bhvAHamRobot[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    LOAD_ANIMATIONS(oAnimations, a_ham_robot_anims),
    ANIMATE(0),
    CALL_NATIVE(ham_robot_init),
    BEGIN_LOOP(),
        CALL_NATIVE(ham_robot_loop),
    END_LOOP(),
};

extern const struct Animation *const a_launched_box_anims[];
void a_launched_box(void);
const BehaviorScript bhvALaunchedBox[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, a_launched_box_anims),
    ANIMATE(0),
    SCALE(0, 50),
    BEGIN_LOOP(),
        CALL_NATIVE(a_launched_box),
    END_LOOP(),
};

void a_robot_launcher_loop(void);
const BehaviorScript bhvARobotLauncher[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(a_robot_launcher_loop),
    END_LOOP(),
};

extern const struct Animation *const dog_robot_anims[];
void a_dog_robot_init(void);
void a_dog_robot_loop(void);
const BehaviorScript bhvADogRobot[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    LOAD_ANIMATIONS(oAnimations, dog_robot_anims),
    ANIMATE(0),
    CALL_NATIVE(a_dog_robot_init),
    BEGIN_LOOP(),
        CALL_NATIVE(a_dog_robot_loop),
    END_LOOP(),
};

void a_gas_cloud_loop(void);
const BehaviorScript bhvAGasCloud[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_ENEMY)),
    BEGIN_LOOP(),
        CALL_NATIVE(a_gas_cloud_loop),
    END_LOOP(),
};

void a_chained_cage_loop(void);
const BehaviorScript bhvAChainedCage[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(a_chained_cage_loop),
    END_LOOP(),
};

/* GROUP A END *\

/* GROUP B START *\

const BehaviorScript bhvConcreteBlock[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_E__SG_COLLISION_BREAKABLE)),
    LOAD_COLLISION_DATA(concrete_block_collision),
    SET_FLOAT(oCollisionDistance, 1000),
    CALL_NATIVE(bhv_concrete_block_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_concrete_block_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
    BREAK(),
};



/* GROUP B END *\

/* GROUP C START *\

const BehaviorScript bhvCamera[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BREAK(),
};

const BehaviorScript bhvLevelSplatoonTarget[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(oInteractStatus, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_target_loop),
    END_LOOP(),
};

const BehaviorScript bhvTargetBox[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_E__SG_BREAKABLE)),//--E
    LOAD_COLLISION_DATA(target_box_collision),
    SET_FLOAT(oCollisionDistance, 1000),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_breakable_box_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
    BREAK(),
};

const BehaviorScript bhvFlag[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, flag_anims),
    ANIMATE(0),
    BEGIN_LOOP(),
    END_LOOP(),
};

const BehaviorScript bhvOctozepplin[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL  |OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW)),
    SET_FLOAT(oDrawingDistance, 15000),
    SET_FLOAT(oForwardVel, 15.0f),
    SET_INT(oHealth, 50),
    SET_INT(oF4, 0),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_octozepplin_loop),
    END_LOOP(),
};

const BehaviorScript bhvJellyFish[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oBobombBuddyRole, 0),
    LOAD_ANIMATIONS(oAnimations, jelly_fish_anims),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*\ 100, /*Height*\ 60),
    ANIMATE(0),
    SET_HOME(),
    CALL_NATIVE(bhv_bobomb_buddy_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_jelly_fish_loop),
    END_LOOP(),
};

/* GROUP C END *\

/* GROUP D START *\
extern void bhv_nitro_boom_loop(void);
extern void bhv_d_elevator(void);
const BehaviorScript bhvDelevator[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(d_elevator_collision),
    SET_FLOAT(oDrawingDistance, 16000),
    SET_FLOAT(oCollisionDistance, 1000),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_d_elevator),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};
const BehaviorScript bhvDbridge[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_seesaw_platform_init),
    LOAD_COLLISION_DATA(d_bridge_collision),
    SET_FLOAT(oDrawingDistance, 20000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_seesaw_platform_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};
/* GROUP D END *\

/* GROUP E START *\

//--Level

const BehaviorScript bhvE_Enemy[] = {//base enemy behavior
    BEGIN(OBJ_LIST_PUSHABLE),
    ID(id_bhvNewId),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_e__enemy),
    END_LOOP(),
};



//--Ability
const BehaviorScript bhvE_RocketBlast[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_e__rocket_blast),
    END_LOOP(),
};

const BehaviorScript bhvE_MuzzleFlash[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DELAY(1),
    DEACTIVATE(),
};
const BehaviorScript bhvE_FlattenedObj[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_e__flattened_obj),
    END_LOOP(),
};
const BehaviorScript bhvE_PushObj[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_e__push_obj),
    END_LOOP(),
};

/* GROUP E END *\

/* GROUP F START *\

const BehaviorScript bhvBriefcase[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HITBOX(/*Radius*\ 100, /*Height*\ 100),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        ADD_INT(oFaceAngleYaw, 0x100),
        CALL_NATIVE(bhv_hidden_star_trigger_loop),
    END_LOOP(),
};

extern void bhv_fdoor_loop(void);
const BehaviorScript bhvFdoor[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW),//--E
    LOAD_COLLISION_DATA(f_door_collision),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fdoor_loop),
    END_LOOP(),
};

const BehaviorScript bhvKeypad[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_PERSISTENT_RESPAWN)),//--E
    BEGIN_LOOP(),
    END_LOOP(),
};

extern void bhv_ffence_loop(void);
const BehaviorScript bhvFfence[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW),//--E
    LOAD_COLLISION_DATA(f_fence_collision),
    SET_FLOAT(oDrawingDistance, 25000),
    SET_FLOAT(oCollisionDistance, 5000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ffence_loop),
    END_LOOP(),
};

extern void bhv_ftrinket_loop(void);
const BehaviorScript bhvFTrinket[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ftrinket_loop),
    END_LOOP(),
};

extern void bhv_fblastwall_loop(void);
const BehaviorScript bhvFblastwall[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW),//--E
    LOAD_COLLISION_DATA(blastwall1_collision),
    SET_FLOAT(oDrawingDistance, 25000),
    SET_FLOAT(oCollisionDistance, 5000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fblastwall_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

extern void bhv_fdynamite_loop(void);
const BehaviorScript bhvFdynamite[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    DROP_TO_FLOOR(),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fdynamite_loop),
    END_LOOP(),
};

extern void bhv_fsg_keypad_loop(void);
const BehaviorScript bhvFSGkeypad[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_PERSISTENT_RESPAWN)),//--E
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fsg_keypad_loop),
    END_LOOP(),
};

const BehaviorScript bhvFhidden[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_PERSISTENT_RESPAWN)),//--E
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hidden_by_uv),
    END_LOOP(),
};

extern void bhv_poof_on_watch(void);
const BehaviorScript bhvPoofOnWatch[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_poof_on_watch),
    END_LOOP(),
};

extern void bhv_gold_button_f_init(void);
const BehaviorScript bhvFRocketButtonGold[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW | OBJ_FLAG_E__SG_CUSTOM)),
    SET_INT(oIntangibleTimer, 0),
    SET_FLOAT(oDrawingDistance, 16000),
    SET_HITBOX(/*Radius*\ 80, /*Height*\ 130),
    //SET_FLOAT(oGraphYOffset, 65),
    CALL_NATIVE(bhv_gold_button_f_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rocket_button_loop),
    END_LOOP(),
};

extern void bhv_sch_board_loop(void);
const BehaviorScript bhvF_SchBoard[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_E__SG_COLLISION_BREAKABLE)),//--E
    LOAD_COLLISION_DATA(f_sch_board_collision),
    SET_FLOAT(oDrawingDistance, 25000),
    SET_FLOAT(oCollisionDistance, 5000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sch_board_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

extern void bhv_f_trapdoor(void);
const BehaviorScript bhvFtrapdoor[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_COLLISION_DATA(f_trapdoor_collision),
    SET_FLOAT(oDrawingDistance, 25000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_f_trapdoor),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

extern void bhv_f_key(void);
const BehaviorScript bhvFkey[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE|OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_f_key),
    END_LOOP(),
};

extern void bhv_f_shooter(void);
const BehaviorScript bhvFshooter[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    ID(id_bhvNewId),
    SET_FLOAT(oDrawingDistance, 10000),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_E__SG_ENEMY | OBJ_FLAG_NO_DREAM_COMET)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_f_shooter),
    END_LOOP(),
};

extern void bhv_f_shooter_star(void);
const BehaviorScript bhvFshooterStar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_NO_DREAM_COMET),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_f_shooter_star),
    END_LOOP(),
};

extern void bhv_f_keydoor(void);
const BehaviorScript bhvFKeydoor[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(f_keydoor_collision),
    LOAD_ANIMATIONS(oAnimations, keydoor_anims),
    SET_FLOAT(oDrawingDistance, 25000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_f_keydoor),
    END_LOOP(),
};

extern void bhv_f_curtainplatform(void);
const BehaviorScript bhvFCurtainPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(f_curtainplatform_collision),
    SET_FLOAT(oDrawingDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_f_curtainplatform),
    END_LOOP(),
};

extern void bhv_f_missiles(void);
const BehaviorScript bhvFMissiles[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oDrawingDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_f_missiles),
    END_LOOP(),
};

extern void bhv_f_blowvent(void);
const BehaviorScript bhvFBlowVent[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_f_blowvent),
    END_LOOP(),
};

extern void bhv_f_boat(void);
const BehaviorScript bhvFBoat[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_COLLISION_DATA(f_boat_collision),
    SET_FLOAT(oDrawingDistance, 32000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_f_boat),
    END_LOOP(),
};

extern void bhv_f_heli(void);
const BehaviorScript bhvFHeli[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    ID(id_bhvNewId),
    SET_FLOAT(oDrawingDistance, 32000),
    LOAD_ANIMATIONS(oAnimations, f_heli_anims),
    ANIMATE(0),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_NO_DREAM_COMET)),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_f_heli),
    END_LOOP(),
};

extern void bhv_helicopter_ball_loop(void);
const BehaviorScript bhvHeliBalls[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_BREAKABLE)),//--E
    BILLBOARD(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 10, /*Gravity*\ 0, /*Bounciness*\ -50, /*Drag strength*\ 1000, /*Friction*\ 1000, /*Buoyancy*\ 200, /*Unused*\ 0, 0),
    CALL_NATIVE(bhv_init_room),
    SET_FLOAT(oGraphYOffset, 10),
    SCALE(/*Unused*\ 0, /*Field*\ 20),
    SET_FLOAT(oDrawingDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_helicopter_ball_loop),
    END_LOOP(),
};

extern void bhv_f_laser(void);

/* GROUP F END *\

/* GROUP H START *\
const BehaviorScript bhvHLoader[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    SET_INT(oNumLootCoins, 5),
    // Whomp - common:
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, hloader_anims),
    LOAD_COLLISION_DATA(whomp_seg6_collision_06020A0C),
    SET_HITBOX(/*Radius*\ 200, /*Height*\ 400),//--E
    ANIMATE(WHOMP_ANIM_WALK),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 0, /*Gravity*\ -400, /*Bounciness*\ -50, /*Drag strength*\ 0, /*Friction*\ 0, /*Buoyancy*\ 200, /*Unused*\ 0, 0),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_whomp_loop),
    END_LOOP(),
};

extern void bhv_hglass_loop(void);
const BehaviorScript bhvHGlass[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_E__SG_COLLISION_BREAKABLE)),
    LOAD_COLLISION_DATA(hglass_collision),
    SET_FLOAT(oCollisionDistance, 3000),
    SET_FLOAT(oDrawingDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hglass_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
    BREAK(),
};
/* GROUP H END *\

/* GROUP I START *\
const BehaviorScript bhvShockRocket[] = {
    BEGIN(OBJ_LIST_DESTRUCTIVE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO |OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW)),
    SCALE(/*Unused*\ 0, /*Field*\ 20),
    SET_INT(oWallHitboxRadius, 40),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 30, /*Gravity*\ 0, /*Bounciness*\ 0, /*Drag strength*\ 0, /*Friction*\ 0, /*Buoyancy*\ 0, /*Unused*\ 0, 0),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_shock_rocket_loop),
    END_LOOP(),
};

const BehaviorScript bhvRocketSmoke[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_FLOAT(oGraphYOffset, -5),
    BILLBOARD(),
    CALL_NATIVE(bhv_rocket_smoke_init),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_REPEAT(3),
        ADD_INT(oAnimState, 1),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvRocketButton[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW | OBJ_FLAG_E__SG_CUSTOM)),
    SET_INT(oIntangibleTimer, 0),
    SET_FLOAT(oDrawingDistance, 16000),
    SET_HITBOX(/*Radius*\ 80, /*Height*\ 130),
    SET_FLOAT(oGraphYOffset, 65),
    CALL_NATIVE(bhv_rocket_button_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rocket_button_loop),
    END_LOOP(),
};

const BehaviorScript bhvRocketButtonGroup[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rocket_button_group_loop),
    END_LOOP(),
};

const BehaviorScript bhvHoodmonger[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW | OBJ_FLAG_E__SG_ENEMY)),
    LOAD_ANIMATIONS(oAnimations, hoodmonger_anims),
    SET_FLOAT(oDrawingDistance, 6000),
    SET_INT(oDamageOrCoinValue, 2),
    SET_INT(oHealth, 1),
    SET_INT(oNumLootCoins, 3),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    ANIMATE(0),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*\ 80, /*Height*\ 210),
    CALL_NATIVE(bhv_hoodmonger_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hoodmonger_loop),
        SET_INT(oIntangibleTimer, 0),
        SET_INT(oInteractStatus, 0),
    END_LOOP(),
};


const BehaviorScript bhvHoodmongerAlertManager[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hoodmonger_alert_manager_loop),
    END_LOOP(),
};

const BehaviorScript bhvHoodmongerBullet[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oDrawingDistance, 8000),
    SET_FLOAT(oCollisionDistance, 500),
    SET_FLOAT(oForwardVel, 25.0f),
    SET_FLOAT(oGraphYOffset, 40),
    SET_INT(oDamageOrCoinValue, 2),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    SET_INT(oWallHitboxRadius, 40),
    SET_HITBOX(/*Radius*\ 45, /*Height*\ 80),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hoodmonger_bullet_loop),
        SET_INT(oIntangibleTimer, 0),
        SET_INT(oInteractStatus, 0),
    END_LOOP(),
};

const BehaviorScript bhvBlackLums[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SCALE(0, 40),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_blacklums_update),
    END_LOOP(),
};

const BehaviorScript bhvDollar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oDrawingDistance, 8000),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_dollar_loop),
    END_LOOP(),
};

const BehaviorScript bhvHoodboomer[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW | OBJ_FLAG_E__SG_ENEMY)),
    LOAD_ANIMATIONS(oAnimations, hoodboomer_anims),
    SET_FLOAT(oDrawingDistance, 6000),
    SET_INT(oDamageOrCoinValue, 3),
    SET_INT(oHealth, 1),
    SET_INT(oNumLootCoins, -1),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    ANIMATE(0),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*\ 80, /*Height*\ 210),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hoodboomer_loop),
        SET_INT(oIntangibleTimer, 0),
        SET_INT(oInteractStatus, 0),
    END_LOOP(),
};

const BehaviorScript bhvHoodboomerBomb[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_BREAKABLE)),//--E
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 30, /*Gravity*\ 0, /*Bounciness*\ 0, /*Drag strength*\ 0, /*Friction*\ 0, /*Buoyancy*\ 0, /*Unused*\ 0, 0),
    SET_HITBOX(80, 50),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    SET_INT(oDamageOrCoinValue, 4),
    CALL_NATIVE(bhv_hoodboomer_bomb_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hoodboomer_bomb_loop),
        CALL_NATIVE(bhv_three_axis_rotative_object),
        SET_INT(oIntangibleTimer, 0),
        SET_INT(oInteractStatus, 0),
    END_LOOP(),
};

const BehaviorScript bhvBlackSmokeHoodboomer[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_FLOAT(oGraphYOffset, 50),
    SET_INT(oOpacity, 255),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_black_smoke_hoodboomer_loop),
    END_LOOP(),
};

const BehaviorScript bhvPigpot[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_E__SG_CUSTOM)),
    DROP_TO_FLOOR(),
    SET_INT(oNumLootCoins, 3),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_NOT_GRABBABLE),
    SET_HITBOX(/*Radius*\ 60, /*Height*\ 100),
    SET_INT(oIntangibleTimer, 0),
    SET_FLOAT(oDeathSound, SOUND_GENERAL_BREAK_BOX),
    SCALE(0, 120),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pigpot_loop),
    END_LOOP(),
};

const BehaviorScript bhvRotatingGearDecorative[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_rotating_gear_decorative_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rotating_gear_decorative_loop),
    END_LOOP(),
};

const BehaviorScript bhvGrillOpenableByRocketButton[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_COLLISION_DATA(i_gate_collision),
    SET_FLOAT(oCollisionDistance, 500),
    SET_FLOAT(oDrawingDistance, 10000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_grill_openable_by_rocket_button_loop),
        CALL_NATIVE(load_object_collision_model),
        SET_INT(oIntangibleTimer, 0),
    END_LOOP(),
};

const BehaviorScript bhvWoodenLever[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_NOT_GRABBABLE),
    SET_HITBOX(/*Radius*\ 100, /*Height*\ 110),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wooden_lever_loop),
        SET_INT(oInteractStatus, INT_STATUS_NONE),
    END_LOOP(),
};

const BehaviorScript bhvPlum[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    SET_HITBOX(/*Radius*\ 80, /*Height*\ 100),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 30, /*Gravity*\ 100, /*Bounciness*\ -50, /*Drag strength*\ 1000, /*Friction*\ 0, /*Buoyancy*\ 200, /*Unused*\ 0, 0),
    SET_INT(oIntangibleTimer, 0),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_plum_loop),
    END_LOOP(),
};

const BehaviorScript bhvPlumBucket[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HITBOX(/*Radius*\ 200, /*Height*\ 200),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_plum_bucket_loop),
    END_LOOP(),
};

const BehaviorScript bhvCagedToad[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_NO_DREAM_COMET)),
    SET_HITBOX(/*Radius*\ 120, /*Height*\ 200),
    SET_INT(oIntangibleTimer, 0),
    SET_FLOAT(oDrawingDistance, 8000),
    SET_FLOAT(oGraphYOffset, 60),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_caged_toad_loop),
    END_LOOP(),
};

const BehaviorScript bhvFallingToad[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 30, /*Gravity*\ 100, /*Bounciness*\ -50, /*Drag strength*\ 1000, /*Friction*\ 0, /*Buoyancy*\ 200, /*Unused*\ 0, 0),
    GOTO(bhvToadMessage + 1),
};

const BehaviorScript bhvHiddenCagedToadsStar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    CALL_NATIVE(bhv_caged_toad_star_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bhv_caged_toad_star_loop),
    END_LOOP(),
};

const BehaviorScript bhvPlankAttachedToRope[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_ATTACHABLE_BY_ROPE | OBJ_FLAG_DONT_CALC_COLL_DIST)),
    SET_FLOAT(oCollisionDistance, 6000),
    SET_FLOAT(oDrawingDistance, 6000),
    SET_FLOAT(oGravity, 2),
    SET_FLOAT(oBounciness, -50),
    LOAD_COLLISION_DATA(plank_rope_collision),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_plank_attached_to_rope_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBarrierAttachedToRope[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_ATTACHABLE_BY_ROPE)),
    LOAD_COLLISION_DATA(barrier_rope_collision),
    SET_FLOAT(oCollisionDistance, 4000),
    SET_FLOAT(oDrawingDistance, 7000),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 30, /*Gravity*\ 100, /*Bounciness*\ -50, /*Drag strength*\ 1000, /*Friction*\ 0, /*Buoyancy*\ 200, /*Unused*\ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_barrier_attached_to_rope_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvFunkyShell[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 30, /*Gravity*\ -400, /*Bounciness*\ -50, /*Drag strength*\ 1000, /*Friction*\ 1000, /*Buoyancy*\ 200, /*Unused*\ 0, 0),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_funky_shell_loop),
    END_LOOP(),
};

const BehaviorScript bhvSkrinkingBlackDoorSpawner[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_skrinking_black_door_spawner),
    END_LOOP(),
};

const BehaviorScript bhvSkrinkingBlackDoor[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    SET_FLOAT(oDrawingDistance, 6000),
    SET_FLOAT(oFloatF4, 1.0f),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_skrinking_black_door),
    END_LOOP(),
};

const BehaviorScript bhvThreeAxisRotativeObject[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    SET_FLOAT(oDrawingDistance, 16000),
     BEGIN_LOOP(),
        CALL_NATIVE(bhv_three_axis_rotative_object),
    END_LOOP(),
};

const BehaviorScript bhvOpeningWall[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(opening_wall_collision),
    SET_FLOAT(oDrawingDistance, 5000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_opening_wall_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvMasterKaag[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),//--E
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 30, /*Gravity*\ 0, /*Bounciness*\ -50, /*Drag strength*\ 1000, /*Friction*\ 1000, /*Buoyancy*\ 200, /*Unused*\ 0, 0),
    LOAD_ANIMATIONS(oAnimations, master_kaag_anims),
    SET_INT(oIntangibleTimer, 0),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    SET_HITBOX(/*Radius*\ 300, /*Height*\ 300),
    SET_HOME(),
    DROP_TO_FLOOR(),
    ANIMATE(0),
    SCALE(0, 150),
    SET_INT(oHealth, 3),
    SET_INT(oDamageOrCoinValue, 3),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_master_kaag_loop),
        SET_INT(oInteractStatus, 0),
    END_LOOP(),
};

const BehaviorScript bhvMasterKaagWeakPoint[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    SET_HITBOX(/*Radius*\ 100, /*Height*\ 180),
    SET_INT(oIntangibleTimer, 0),
    SET_FLOAT(oGraphYOffset, 65),
    BEGIN_LOOP(),
        SET_INT(oInteractStatus, 0),
    END_LOOP(),
};

const BehaviorScript bhvHoodooSorcerer[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW | OBJ_FLAG_E__SG_ENEMY)),
    LOAD_ANIMATIONS(oAnimations, hoodoo_sorcerer_anims),
    SET_FLOAT(oDrawingDistance, 8000),
    SET_INT(oDamageOrCoinValue, 1),
    SET_INT(oHealth, 1),
    SET_INT(oNumLootCoins, 3),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    DROP_TO_FLOOR(),
    ANIMATE(0),
    SET_HITBOX(/*Radius*\ 80, /*Height*\ 400),
    CALL_NATIVE(bhv_hoodoo_sorcerer_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hoodoo_sorcerer_loop),
        SET_INT(oIntangibleTimer, 0),
        SET_INT(oInteractStatus, 0),
    END_LOOP(),
};

const BehaviorScript bhvLevelIBossDoor[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW)),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 30, /*Gravity*\ 100, /*Bounciness*\ -50, /*Drag strength*\ 1000, /*Friction*\ 0, /*Buoyancy*\ 200, /*Unused*\ 0, 0),
    LOAD_COLLISION_DATA(boss_gate_collision),
    SET_FLOAT(oDrawingDistance, 16000),
    SET_HITBOX(10, 10),
    //DROP_TO_FLOOR(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_level_I_boss_door_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvLevelIBossDoorStarSlot[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW)),
    SET_FLOAT(oDrawingDistance, 16000),
    BEGIN_LOOP(),
    END_LOOP(),
};

const BehaviorScript bhvBountyHunterToad[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_ANIMATIONS(oAnimations, toad_seg6_anims_0600FB58),
    ANIMATE(TOAD_ANIM_WEST_WAVING_BOTH_ARMS),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_HITBOX(/*Radius*\ 80, /*Height*\ 100),
    SET_INT(oIntangibleTimer, 0),
    SET_FLOAT(oDrawingDistance, 32000),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_bounty_hunter_toad_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bounty_hunter_toad_loop),
    END_LOOP(),
};

const BehaviorScript bhvLevelIStartToad[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_level_I_start_toad_init),
    GOTO(bhvToadMessage + 1),
};

/* GROUP I END *\

/* GROUP J START *\
const BehaviorScript bhvDragonite[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW | OBJ_FLAG_PERSISTENT_RESPAWN)),
    LOAD_ANIMATIONS(oAnimations, dragonite_anims),
    SET_FLOAT(oDrawingDistance, 32000),
    CALL_NATIVE(bhv_dragonite_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_dragonite_loop),
    END_LOOP(),
};

const BehaviorScript bhvFallingPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW)),
    LOAD_COLLISION_DATA(falling_platform_collision),
    SET_FLOAT(oCollisionDistance, 2000),
    SET_FLOAT(oDrawingDistance, 32000),
    CALL_NATIVE(bhv_falling_platform_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_falling_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};


const BehaviorScript bhvTiltyHexagon[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(tilty_hexagon_collision),
    SET_HOME(),
    CALL_NATIVE(bhv_platform_normals_init),
    SET_FLOAT(oDrawingDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tilting_inverted_pyramid_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvSkarmory[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_ANIMATIONS(oAnimations, skarmory_anims),
    SET_FLOAT(oDrawingDistance, 20000),
    CALL_NATIVE(bhv_skarmory_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_skarmory_loop),
    END_LOOP(),
};

const BehaviorScript bhvSkarmoryStarSpawner[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_skarmory_star_spawner_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_skarmory_star_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvYoungster[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, youngster_anims),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*\ 100, /*Height*\ 60),
    ANIMATE(0),
    SET_HOME(),
    CALL_NATIVE(bhv_youngster_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_npc_loop),
    END_LOOP(),
};

const BehaviorScript bhvSpinarak[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE | OBJ_FLAG_E__SG_ENEMY)),
    LOAD_ANIMATIONS(oAnimations, spinarak_anims),
    ANIMATE(0),
    SET_HOME(),
    CALL_NATIVE(bhv_spinarak_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_spinarak_loop),
    END_LOOP(),
};

const BehaviorScript bhvGeodude[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW)),
    LOAD_ANIMATIONS(oAnimations, geodude_anims),
    SET_HOME(),
    CALL_NATIVE(bhv_geodude_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_geodude_loop),
    END_LOOP(),
};

const BehaviorScript bhvGeodudePunchHitbox[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_geodude_punch_hitbox_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_geodude_punch_hitbox_loop),
    END_LOOP(),
};

const BehaviorScript bhvBerry[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 30, /*Gravity*\ -400, /*Bounciness*\ -50, /*Drag strength*\ 0, /*Friction*\ 0, /*Buoyancy*\ 200, /*Unused*\ 0, 0),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_HOLDABLE_NPC),
    SET_INT(oIntangibleTimer, 0),
    SET_HITBOX(/*Radius*\ 40, /*Height*\ 40),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_berry_loop),
    END_LOOP(),
};

const BehaviorScript bhvHooh[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_ANIMATIONS(oAnimations, hooh_anims),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 32000),
    CALL_NATIVE(bhv_hooh_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hooh_loop),
    END_LOOP(),
};

const BehaviorScript bhvHoohFlame[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_HOME(),
    SCALE(/*Unused*\ 0, /*Field*\ 700),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    SET_HITBOX_WITH_OFFSET(/*Radius*\ 50, /*Height*\ 25, /*Downwards offset*\ 25),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_hooh_flame_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hooh_flame_loop),
        SET_INT(oInteractStatus, INT_STATUS_NONE),
        ANIMATE_TEXTURE(oAnimState, 2),
    END_LOOP(),
};

const BehaviorScript bhvHoohRock[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    SET_HITBOX_WITH_OFFSET(/*Radius*\ 100, /*Height*\ 100, /*Downwards offset*\ 0),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(oDamageOrCoinValue, 2),
    CALL_NATIVE(bhv_hooh_rock_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hooh_rock_loop),
        SET_INT(oInteractStatus, INT_STATUS_NONE),
    END_LOOP(),   
};

const BehaviorScript bhvHoohFlame2[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_HOME(),
    SCALE(/*Unused*\ 0, /*Field*\ 700),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    SET_HITBOX_WITH_OFFSET(/*Radius*\ 50, /*Height*\ 25, /*Downwards offset*\ 25),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hooh_flame2_loop),
        SET_INT(oInteractStatus, INT_STATUS_NONE),
        ANIMATE_TEXTURE(oAnimState, 2),
    END_LOOP(),
};

const BehaviorScript bhvMiltank[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_NO_DREAM_COMET)),
    CALL_NATIVE(bhv_miltank_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_miltank_loop),
    END_LOOP(),
};

const BehaviorScript bhvMiltankStar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_miltank_star_loop),
    END_LOOP(),
};

const BehaviorScript bhvHaunter[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    // Boo - common:
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),//--E
    SET_INT(oIntangibleTimer, 0),
    SET_HOME(),
    SET_INT(oDamageOrCoinValue, 2),
    LOAD_ANIMATIONS(oAnimations, haunter_anims),
    ANIMATE(0),
    SET_HITBOX(/*Radius*\ 140, /*Height*\ 80),
    SET_HURTBOX(/*Radius*\ 40, /*Height*\ 60),
    SET_FLOAT(oGraphYOffset, 30),
    CALL_NATIVE(bhv_init_room),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 30, /*Gravity*\ 0, /*Bounciness*\ -50, /*Drag strength*\ 1000, /*Friction*\ 1000, /*Buoyancy*\ 200, /*Unused*\ 0, 0),
    CALL_NATIVE(bhv_boo_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_boo_loop),
    END_LOOP(),
};

const BehaviorScript bhvGengar[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    // Big boo - common:
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),//--E
    SET_HOME(),
    LOAD_ANIMATIONS(oAnimations, gengar_anims),
    ANIMATE(0),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 30, /*Gravity*\ 0, /*Bounciness*\ -50, /*Drag strength*\ 1000, /*Friction*\ 1000, /*Buoyancy*\ 200, /*Unused*\ 0, 0),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_boo_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_big_boo_loop),
    END_LOOP(),
};

const BehaviorScript bhvElder[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_ANIMATIONS(oAnimations, elder_anims),
    DROP_TO_FLOOR(),
    ANIMATE(0),
    SET_HOME(),
    CALL_NATIVE(bhv_elder_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_npc_loop),
    END_LOOP(),
};

const BehaviorScript bhvKimonoGirl[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_ANIMATIONS(oAnimations, elder_anims),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*\ 100, /*Height*\ 60),
    ANIMATE(0),
    SET_HOME(),
    CALL_NATIVE(bhv_npc_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_npc_loop),
    END_LOOP(),
};

const BehaviorScript bhvMorty[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_ANIMATIONS(oAnimations, morty_anims),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*\ 100, /*Height*\ 60),
    ANIMATE(0),
    SET_FLOAT(oDrawingDistance, 32000),
    SET_HOME(),
    CALL_NATIVE(bhv_npc_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_npc_loop),
    END_LOOP(),
};

const BehaviorScript bhvSentret[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_E__SG_ENEMY)),
    LOAD_ANIMATIONS(oAnimations, sentret_anims),
    SET_HOME(),
    CALL_NATIVE(bhv_sentret_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sentret_loop),
    END_LOOP(),
};

const BehaviorScript bhvSkiploom[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_ENEMY)),//--E
    LOAD_ANIMATIONS(oAnimations, skiploom_anims),
    ANIMATE(0),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 50, /*Gravity*\ 0, /*Bounciness*\ 0, /*Drag strength*\ 0, /*Friction*\ 1000, /*Buoyancy*\ 600, /*Unused*\ 0, 0),
    CALL_NATIVE(bhv_init_room),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_TWIRL_BOUNCE),
    SET_FLOAT(oGraphYOffset, 30),
    SCALE(/*Unused*\ 0, /*Field*\ 150),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fly_guy_update),
    END_LOOP(),
};

const BehaviorScript bhvGravelerRamp[] = {
    BEGIN(OBJ_LIST_SPAWNER),
    ID(id_bhvNewId),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_graveler_ramp_loop),
    END_LOOP(),
};

const BehaviorScript bhvOldMan[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, old_man_anims),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*\ 100, /*Height*\ 60),
    ANIMATE(0),
    SET_HOME(),
    CALL_NATIVE(bhv_npc_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_npc_loop),
    END_LOOP(),
};

const BehaviorScript bhvSnorlax[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    LOAD_ANIMATIONS(oAnimations, snorlax_anims),
    SET_INTERACT_TYPE(INTERACT_IGLOO_BARRIER),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*\ 200, /*Height*\ 200),
    ANIMATE(0),
    CALL_NATIVE(bhv_snorlax_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_snorlax_loop),
    END_LOOP(),
};

const BehaviorScript bhvMagikarp[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE |  OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW)),
    LOAD_ANIMATIONS(oAnimations, magikarp_anims),
    ANIMATE(0),
    SET_HOME(),
    CALL_NATIVE(bhv_magikarp_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_magikarp_loop),
    END_LOOP(),
};

/* GROUP J END *\

/* GROUP K START *\
extern void bhv_k_fan(void);
const BehaviorScript bhvKfan[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(k_fan_collision),
    SET_FLOAT(oDrawingDistance, 32000),
    SET_FLOAT(oCollisionDistance, 500),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_k_fan),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

extern void bhv_k_blood(void);
const BehaviorScript bhvKblood[] = {
    SET_FLOAT(oDrawingDistance, 
        ID(id_320NewId),bhvKblood),
    SET_FLOAT(oCollisionDistance, 500),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_k_blood),
    END_LOOP(),
};

void bhv_dancer(void);
const BehaviorScript bhvKdancer[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, kdancer_anims),
    ANIMATE(0),
    SET_HOME(),
    SET_FLOAT(oGraphYOffset, -25),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_dancer),
    END_LOOP(),
};

const BehaviorScript bhvKDisco[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        ADD_INT(oFaceAngleYaw, 0x200),
    END_LOOP(),
};

extern void bhv_k_bartender(void);
const BehaviorScript bhvKbartender[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, k_bartender_anims),
    ANIMATE(0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_k_bartender),
    END_LOOP(),
};

extern void bhv_k_strong_terry(void);
const BehaviorScript bhvStrongTerry[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    LOAD_ANIMATIONS(oAnimations, humanoid_anims),
    ANIMATE(1),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_k_strong_terry),
    END_LOOP(),
};

extern void bhv_k_skinny_ricky(void);
const BehaviorScript bhvSkinnyRicky[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    LOAD_ANIMATIONS(oAnimations, humanoid_anims),
    ANIMATE(1),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_k_skinny_ricky),
    END_LOOP(),
};

extern void bhv_k_shieldo(void);
const BehaviorScript bhvShieldo[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    LOAD_ANIMATIONS(oAnimations, humanoid_anims),
    ANIMATE(1),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_k_shieldo),
    END_LOOP(),
};

extern void bhv_k_electrohead(void);
const BehaviorScript bhvElectrohead[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_ANIMATIONS(oAnimations, humanoid_anims),
    ANIMATE(1),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_k_electrohead),
    END_LOOP(),
};

extern void bhv_k_billionare(void);
const BehaviorScript bhvKbillionare[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_ANIMATIONS(oAnimations, humanoid_anims),
    ANIMATE(1),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_k_billionare),
    END_LOOP(),
};

extern void bhv_k_tv(void);
const BehaviorScript bhvKtv[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_NO_DREAM_COMET),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_k_tv),
    END_LOOP(),
};

extern void bhv_k_tv_aim(void);
const BehaviorScript bhvKtvAim[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_k_tv_aim),
    END_LOOP(),
};

extern void bhv_k_pounder(void);
const BehaviorScript bhvKpounder[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(k_pounder_collision),
    SET_FLOAT(oDrawingDistance, 32000),
    SET_FLOAT(oCollisionDistance, 3000),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_k_pounder),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};
/* GROUP K END *\

/* GROUP L START *\
const BehaviorScript bhvPtMetalBox[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(pt_mb_collision),
    SET_FLOAT(oDrawingDistance, 16000),
    SET_FLOAT(oCollisionDistance, 500),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pt_mb),
    END_LOOP(),
};

extern void bhv_l_door_loop(void);
const BehaviorScript bhvLDoor[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    SET_INT(oInteractType, INTERACT_WARP_DOOR),
    // Door - common:
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, door_seg3_anims_030156C0),
    ANIMATE(DOOR_ANIM_CLOSED),
    SET_HITBOX(/*Radius*\ 80, /*Height*\ 100),
    SET_INT(oIntangibleTimer, 0),
    SET_FLOAT(oCollisionDistance, 1000),
    SET_HOME(),
    CALL_NATIVE(bhv_door_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_l_door_loop),
    END_LOOP(),
};

extern void bhv_l_pillar(void);
const BehaviorScript bhvL_JohnPillar[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_NO_DREAM_COMET),
    SET_HITBOX(/*Radius*\ 212, /*Height*\ 1000),
    LOAD_ANIMATIONS(oAnimations, johnp_anims),
    ANIMATE(0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_l_pillar),
    END_LOOP(),
};

extern void bhv_l_johnblock(void);
const BehaviorScript bhvJohnBlock[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(johnblock_collision),
    SET_FLOAT(oDrawingDistance, 16000),
    SET_FLOAT(oCollisionDistance, 500),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_NO_DREAM_COMET)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_l_johnblock),
    END_LOOP(),
};

extern void bhv_escape_collect_star_loop(void);
const BehaviorScript bhvL_EscapeStar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_collect_star_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_escape_collect_star_loop),
    END_LOOP(),
};

const BehaviorScript bhvL_Cheeseslime[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_ENEMY | OBJ_FLAG_ATTACHABLE_BY_ROPE)),//--E
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, cheeseslime_anims),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 40, /*Gravity*\ -400, /*Bounciness*\ -50, /*Drag strength*\ 1000, /*Friction*\ 1000, /*Buoyancy*\ 0, /*Unused*\ 0, 0),
    CALL_NATIVE(bhv_goomba_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_goomba_update),
    END_LOOP(),
};

extern void bhv_npc_pepperman_loop(void);
const BehaviorScript bhvL_PeppermanNPC[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_ANIMATIONS(oAnimations, pepperman_anims),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*\ 100, /*Height*\ 60),
    ANIMATE(0),
    SET_HOME(),
    CALL_NATIVE(bhv_npc_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_npc_pepperman_loop),
    END_LOOP(),
};

extern void bhv_boss_pepperman_loop(void);
const BehaviorScript bhvL_PeppermanBoss[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_NO_DREAM_COMET)),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 100, /*Gravity*\ -400, /*Bounciness*\ -50, /*Drag strength*\ 500, /*Friction*\ 500, /*Buoyancy*\ 0, /*Unused*\ 0, 0),
    LOAD_ANIMATIONS(oAnimations, pepperman_anims),
    DROP_TO_FLOOR(),
    ANIMATE(0),
    SET_HOME(),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_boss_pepperman_loop),
    END_LOOP(),
};

extern void bhv_boss_pepperman_statue(void);
const BehaviorScript bhvL_PeppermanStatue[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 100, /*Gravity*\ -400, /*Bounciness*\ -50, /*Drag strength*\ 500, /*Friction*\ 500, /*Buoyancy*\ 0, /*Unused*\ 0, 0),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_boss_pepperman_statue),
    END_LOOP(),
};

extern void bhv_l_clock(void);
const BehaviorScript bhvLclock[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HITBOX(/*Radius*\ 100, /*Height*\ 100),
    LOAD_ANIMATIONS(oAnimations, lclock_anims),
    ANIMATE(0),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_l_clock),
    END_LOOP(),
};

extern void bhv_pizza_portal_loop(void);
const BehaviorScript bhvL_PizzaPortal[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oInteractType, INTERACT_WARP),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pizza_portal_loop),
    END_LOOP(),
};
/* GROUP L END *\

/* GROUP M START *\
extern void bhv_m_boss_elevator(void);
const BehaviorScript bhvM_BossElevator[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_COLLISION_DATA(m_bossplatform_collision),
    SET_FLOAT(oCollisionDistance, 4000),
    SET_FLOAT(oDrawingDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_m_boss_elevator),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

extern void bhv_m_classc(void);
const BehaviorScript bhvM_ClassC[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_NO_DREAM_COMET)),
    SET_FLOAT(oDrawingDistance, 32000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_m_classc),
    END_LOOP(),
};

extern void bhv_m_gate(void);
const BehaviorScript bhvM_Gate[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_COLLISION_DATA(m_gate_collision),
    SET_FLOAT(oCollisionDistance, 4000),
    SET_FLOAT(oDrawingDistance, 32000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_m_gate),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

extern void goliath_jelly_boss_loop(void);
const BehaviorScript bhvM_Jelly[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_NO_DREAM_COMET)),
    SCALE(0, 400),
    ANIMATE(0),
    LOAD_ANIMATIONS(oAnimations, m_jelly_anims),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(goliath_jelly_boss_loop),
    END_LOOP(),
};

extern void bhv_m_elevator(void);
const BehaviorScript bhvMelevator[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_COLLISION_DATA(m_elevator_collision),
    SET_FLOAT(oCollisionDistance, 4000),
    SET_FLOAT(oDrawingDistance, 32000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_m_elevator),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

extern void bhv_m_jelly_laser_loop(void);
const BehaviorScript bhvM_JellyLaser[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_m_jelly_laser_loop),
    END_LOOP(),
};
/* GROUP M END *\

/* GROUP N START *\
const BehaviorScript bhvPhysicsMarble[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    CALL_NATIVE(bhv_marble_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_marble_loop),
    END_LOOP(),
};
extern void bhv_marble_cannon_loop(void);
const BehaviorScript bhvMarbleCannon[] = {
    CALL_NATIVE(bhv_marble_init),
    ID(id_bhvNewId),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_marble_cannon_loop),
    END_LOOP(),
};
/* GROUP N END *\

/* GROUP O START *\
extern void bhv_red_arrow(void);
const BehaviorScript bhvRedArrow[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_red_arrow),
    END_LOOP(),
};

extern void bhv_o_walker_update(void);
const BehaviorScript bhvOZombie[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, o_zombie_anims),
    ANIMATE(0),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 40, /*Gravity*\ -400, /*Bounciness*\ -1, /*Drag strength*\ 1000, /*Friction*\ 1000, /*Buoyancy*\ 0, /*Unused*\ 0, 0),
    SET_HITBOX(/*Radius*\ 80, /*Height*\ 130),
    SET_FLOAT(oDrawingDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_o_walker_update),
    END_LOOP(),
};

extern void bhv_zambie_spawner(void);
const BehaviorScript bhvOZombieSpawner[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_COMPUTE_DIST_TO_MARIO),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_zambie_spawner),
    END_LOOP(),
};

extern void bhv_o_tree_init(void);
const BehaviorScript bhvOTree[] = {
    BEGIN(OBJ_LIST_POLELIKE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_OPACITY_FROM_CAMERA_DIST)),
    SET_INT(oInteractType, INTERACT_POLE),
    SET_HITBOX(/*Radius*\ 80, /*Height*\ 500),
    SET_INT(oIntangibleTimer, 0),
    SET_FLOAT(oDrawingDistance, 32000),
    CALL_NATIVE(bhv_o_tree_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pole_base_loop),
    END_LOOP(),
};

const BehaviorScript bhvOuvstar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_NO_DREAM_COMET),
    SET_HITBOX(/*Radius*\ 150, /*Height*\ 100),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        ADD_INT(oFaceAngleYaw, 0x200),
        CALL_NATIVE(bhv_hidden_star_trigger_loop),
        CALL_NATIVE(bhv_hidden_by_uv),
    END_LOOP(),
};

extern void bhv_o_lift(void);
const BehaviorScript bhvOlift[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(o_lift_collision),
    SET_FLOAT(oDrawingDistance, 16000),
    SET_FLOAT(oCollisionDistance, 800),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_o_lift),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

extern void bhv_o_garage(void);
const BehaviorScript bhvOgarage[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(o_garage_collision),
    SET_FLOAT(oDrawingDistance, 32000),
    SET_FLOAT(oCollisionDistance, 800),
    SET_HOME(),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_ATTACHABLE_BY_ROPE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_o_garage),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

extern void bhv_o_speaker(void);
const BehaviorScript bhvOspeaker[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_NO_DREAM_COMET),
    SET_HITBOX(/*Radius*\ 200, /*Height*\ 200),
    SET_FLOAT(oGraphYOffset, 100),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_o_speaker),
    END_LOOP(),
};

extern void bhv_o_easystreet_mission_controller(void);
const BehaviorScript bhvOeasystreetcontroller[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_NO_DREAM_COMET)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_o_easystreet_mission_controller),
    END_LOOP(),
};

extern void bhv_o_gerik(void);
const BehaviorScript bhvO_Gerik[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM | OBJ_FLAG_NO_DREAM_COMET)),
    LOAD_ANIMATIONS(oAnimations, humanoid_anims),
    ANIMATE(0),
    SET_HOME(),
    SCALE(/*Unused*\ 0, /*Field*\ 250),
    SET_HITBOX(/*Radius*\ 500, /*Height*\ 300),
    SET_FLOAT(oDrawingDistance, 30000),
    SET_INTERACT_TYPE(INTERACT_NONE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_o_gerik),
    END_LOOP(),
};

/* Group O; Secret Boss *\

extern void bhv_sb_torch(void);
const BehaviorScript bhvSbTorch[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sb_torch),
    END_LOOP(),
};

extern void bhv_sb_actor(void);
const BehaviorScript bhvSbGaster[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    LOAD_ANIMATIONS(oAnimations, sb_humanoid_anims),
    ANIMATE(0),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sb_actor),
    END_LOOP(),
};

const BehaviorScript bhvSbYukari[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    LOAD_ANIMATIONS(oAnimations, sb_humanoid_anims),
    ANIMATE(0),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sb_actor),
    END_LOOP(),
};

void bhv_sb_gap(void);
const BehaviorScript bhvSbGap[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sb_gap),
    END_LOOP(),
};

extern void bhv_sb_manager(void);
const BehaviorScript bhvSbManager[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    LOAD_ANIMATIONS(oAnimations, humanoid_anims),
    ANIMATE(1),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sb_manager),
    END_LOOP(),
};

extern void bhv_sb_train(void);
const BehaviorScript bhvSbTrain[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(sb_train_collision),
    SET_FLOAT(oDrawingDistance, 32000),
    SET_FLOAT(oCollisionDistance, 8000),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_DONT_CALC_COLL_DIST)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sb_train),
    END_LOOP(),
};

extern void bhv_sb_blaster(void);
const BehaviorScript bhvSbBlaster[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, sb_blaster_anims),
    ANIMATE(0),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sb_blaster),
    END_LOOP(),
};


extern void bhv_sb_blast(void);
const BehaviorScript bhvSbBlast[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oDrawingDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sb_blast),
    END_LOOP(),
};

/* GROUP O END *\

const BehaviorScript bhvCutterBlast[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oDrawingDistance, 20000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cutter_blast_loop),
    END_LOOP(),
};

const BehaviorScript bhvSlashParticle[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_slash_particle_loop),
    END_LOOP(),
};

const BehaviorScript bhvStarDoorStar[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_star_door_star_init),
    SET_FLOAT(oDrawingDistance, 16000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_star_door_star_loop),
    END_LOOP(),
};

const BehaviorScript bhvGreatCaveOffensiveController[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_great_cave_offensive_controller_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_great_cave_offensive_controller_loop),
    END_LOOP(),
};

const BehaviorScript bhvGMarx[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_E__SG_BOSS | OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ACTIVE_FROM_AFAR)),
    LOAD_ANIMATIONS(oAnimations, marx_anims),
    CALL_NATIVE(bhv_g_marx_init),
    SET_FLOAT(oDrawingDistance, 16000),
    ANIMATE(0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_marx_loop),
    END_LOOP(),
};

const BehaviorScript bhvGMarxCutter[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_g_marx_cutter_init),
    SET_FLOAT(oDrawingDistance, 16000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_marx_cutter_loop),
    END_LOOP(),
};

const BehaviorScript bhvGMarxSeed[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    CALL_NATIVE(bhv_g_marx_seed_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_marx_seed_loop),
    END_LOOP(),
};

const BehaviorScript bhvGMarxVine[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    CALL_NATIVE(bhv_g_marx_vine_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_marx_vine_loop),
    END_LOOP(),
};

const BehaviorScript bhvGMarxThornSegment[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_FLOAT(oDrawingDistance, 16000),
    CALL_NATIVE(bhv_g_marx_thorn_segment_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_marx_thorn_segment_loop),
    END_LOOP(),
};

const BehaviorScript bhvGMarxHalf[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oDrawingDistance, 16000),
    CALL_NATIVE(bhv_g_marx_half_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_marx_half_loop),
    END_LOOP(),
};

const BehaviorScript bhvGMarxBlackHole[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    BILLBOARD(),
    SET_FLOAT(oDrawingDistance, 16000),
    CALL_NATIVE(bhv_g_marx_black_hole_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_marx_black_hole_loop),
    END_LOOP(),
};

const BehaviorScript bhvGMarxArrow[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW)),
    CALL_NATIVE(bhv_g_marx_arrow_init),
    SET_FLOAT(oDrawingDistance, 16000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_marx_arrow_loop),
    END_LOOP(),
};

const BehaviorScript bhvGMarxBodyLaser[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW)),
    CALL_NATIVE(bhv_g_marx_body_laser_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_marx_body_laser_loop),
    END_LOOP(),
};

const BehaviorScript bhvGMarxLaser[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_g_marx_laser_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_marx_laser_loop),
    END_LOOP(),
};

const BehaviorScript bhvGMarxIceBomb[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    BILLBOARD(),
    SET_FLOAT(oDrawingDistance, 16000),
    CALL_NATIVE(bhv_g_marx_ice_bomb_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_marx_ice_bomb_loop),
    END_LOOP(),
};

const BehaviorScript bhvGMarxBlackHoleEffect[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_g_marx_black_hole_effect_init),
    SET_FLOAT(oDrawingDistance, 16000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_marx_black_hole_effect_loop),
    END_LOOP(),
};

const BehaviorScript bhvGMarxDoor[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_COLLISION_DATA(g_marx_door_collision),
    SET_FLOAT(oDrawingDistance, 16000),
    CALL_NATIVE(bhv_g_marx_door_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_marx_door_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

extern void bhv_matplatform(void);
const BehaviorScript bhvMatPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_matplatform),
        //CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBcTilting[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(bc_tilting_collision),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_seesaw_platform_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBcWaddleDee[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_E__SG_ENEMY | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW )),
    LOAD_ANIMATIONS(oAnimations, bc_waddle_dee_anims),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 16000),
    ANIMATE(0),
    CALL_NATIVE(bhv_g_waddle_dee_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_g_waddle_dee_loop),
    END_LOOP(),
};

const BehaviorScript bhvBcJelly[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_ENEMY)),
    LOAD_ANIMATIONS(oAnimations, bc_jelly_anims),
    CALL_NATIVE(jelly_init),
    ANIMATE(0),
    BEGIN_LOOP(),
        CALL_NATIVE(jelly_loop),
    END_LOOP(),
};

const BehaviorScript bhvBcHoodmonger[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW | OBJ_FLAG_E__SG_ENEMY)),
    LOAD_ANIMATIONS(oAnimations, bc_hoodmonger_anims),
    SET_FLOAT(oDrawingDistance, 6000),
    SET_INT(oDamageOrCoinValue, 2),
    SET_INT(oHealth, 1),
    SET_INT(oNumLootCoins, 3),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    ANIMATE(0),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*\ 80, /*Height*\ 210),
    CALL_NATIVE(bhv_hoodmonger_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hoodmonger_loop),
        SET_INT(oIntangibleTimer, 0),
        SET_INT(oInteractStatus, 0),
    END_LOOP(),
};

const BehaviorScript bhvBcFspinner[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(bc_fspinner_collision),
    SET_FLOAT(oCollisionDistance, 4000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lll_rotating_block_fire_bars_loop),
    END_LOOP(),
};

void bc_stair_loop(void);
const BehaviorScript bhvBcStair[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_VELOCITY_PLATFORM)),
    LOAD_COLLISION_DATA(bc_stair_collision),
    SET_FLOAT(oCollisionDistance, 4000),
    SET_FLOAT(oDrawingDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bc_stair_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBcSkiploom[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_ENEMY)),//--E
    LOAD_ANIMATIONS(oAnimations, bc_skiploom_anims),
    ANIMATE(0),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*\ 50, /*Gravity*\ 0, /*Bounciness*\ 0, /*Drag strength*\ 0, /*Friction*\ 1000, /*Buoyancy*\ 600, /*Unused*\ 0, 0),
    CALL_NATIVE(bhv_init_room),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_TWIRL_BOUNCE),
    SET_FLOAT(oGraphYOffset, 30),
    SCALE(/*Unused*\ 0, /*Field*\ 150),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fly_guy_update),
    END_LOOP(),
};

extern void bhv_atreus_bosscontroller(void);
const BehaviorScript bhvBcAtreus[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_ANIMATIONS(oAnimations, bc_atreus_anims),
    ANIMATE(0),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 32000),
    SCALE(/*Unused*\ 0, /*Field*\ 900),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_atreus_bosscontroller),
    END_LOOP(),
};

extern void bhv_final_boss_bowser(void);
const BehaviorScript bhvBcBowser[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    LOAD_ANIMATIONS(oAnimations, bc_bowser_anims),
    ANIMATE(2),
    DROP_TO_FLOOR(),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_final_boss_bowser),
    END_LOOP(),
};

extern void bhv_pingas_plane(void);
const BehaviorScript bhvBcPingasPlane[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_E__SG_CUSTOM)),
    LOAD_ANIMATIONS(oAnimations, bc_pingas_plane_anims),
    ANIMATE(1),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pingas_plane),
    END_LOOP(),
};

const BehaviorScript bhvBcPingasBall[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(oDamageOrCoinValue, 1),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    SET_HOME(),
    SET_HITBOX_WITH_OFFSET(/*Radius*\ 250, /*Height*\ 400, /*Downwards offset*\ 145),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        SET_INT(oInteractStatus, 0),
    END_LOOP(),
};

const BehaviorScript bhvBcBosslanding[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_PERSISTENT_RESPAWN)),
    LOAD_COLLISION_DATA(bc_bosslanding_collision),
    SET_FLOAT(oDrawingDistance, 32000),
    SET_FLOAT(oCollisionDistance, 32000),
    BEGIN_LOOP(),
        //CALL_NATIVE(bhv_seesaw_platform_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

extern void bhv_golem_limb(void);
const BehaviorScript bhvBcGolemBody[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(bc_golem_body_collision),
    OR_INT(oFlags, (OBJ_FLAG_DONT_CALC_COLL_DIST)),
    SET_FLOAT(oCollisionDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_golem_limb),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBcGolemLimb[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(bc_golem_limb_collision),
    OR_INT(oFlags, (OBJ_FLAG_DONT_CALC_COLL_DIST)),
    SET_FLOAT(oCollisionDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_golem_limb),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBcGolemHead[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    LOAD_COLLISION_DATA(bc_golem_head_collision),
    OR_INT(oFlags, (OBJ_FLAG_DONT_CALC_COLL_DIST)),
    SET_FLOAT(oCollisionDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_golem_limb),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

extern void bhv_golem_crystal(void);
const BehaviorScript bhvBcGolemCrystal[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_golem_crystal),
    END_LOOP(),
};

extern void bhv_golem_crystalp(void);
const BehaviorScript bhvBcGolemCrystalp[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_E__SG_CUSTOM)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_golem_crystalp),
    END_LOOP(),
};

extern void bhv_golem_foot(void);
const BehaviorScript bhvBcGolemFoot[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_golem_foot),
    END_LOOP(),
};

extern void bhv_golem_laser(void);
const BehaviorScript bhvBcGolemLaser[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_golem_laser),
    END_LOOP(),
};

extern void bhv_npc_egadd_loop(void);
const BehaviorScript bhvEgaddNPC[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, egadd_anims),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*\ 100, /*Height*\ 60),
    ANIMATE(0),
    SET_HOME(),
    CALL_NATIVE(bhv_npc_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_npc_egadd_loop),
    END_LOOP(),
};

extern void bhv_artreus_artifact_on_machine(void);
const BehaviorScript bhvAArtifactOnMachine[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_FLOAT(oDrawingDistance, 20000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_artreus_artifact_on_machine),
    END_LOOP(),
};

void bhv_machine_door(void);
const BehaviorScript bhvHubDoor[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(hub_door_collision),
    SET_FLOAT(oCollisionDistance, 4000),
    SET_FLOAT(oDrawingDistance, 32000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_machine_door),
    END_LOOP(),
};

extern void bhv_stargoo(void);
const BehaviorScript bhvStarGoo[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_FLOAT(oDrawingDistance, 20000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_stargoo),
    END_LOOP(),
};

const BehaviorScript bhvHubTargetBox[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_E__SG_BREAKABLE)),//--E
    LOAD_COLLISION_DATA(hub_target_box_collision),
    SET_FLOAT(oCollisionDistance, 1000),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_breakable_box_loop),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_target_box_init),
    END_LOOP(),
    BREAK(),
};

extern void bhv_credits_slab_loob(void);
const BehaviorScript bhvCreditsSlab[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_credits_slab_loob),
    END_LOOP(),
};

const BehaviorScript bhvDreamCatalyst[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_dream_catalyst),
    END_LOOP(),
};

extern void bhv_collectable_painting(void);

extern void bhv_cardstar_init(void);
extern void bhv_cardstar(void);
const BehaviorScript bhvCarboardStarBody[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    CALL_NATIVE(bhv_cardstar_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cardstar),
    END_LOOP(),
};

extern void bhv_boss_defeat_star(void);
const BehaviorScript bhvBdStar[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_boss_defeat_star),
    END_LOOP(),
};

extern void bhv_boss_defeat_wave(void);
const BehaviorScript bhvBdWave[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    ID(id_bhvNewId),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_boss_defeat_wave),
    END_LOOP(),
};

extern void bhv_final_boss_hint_sign(void);
const BehaviorScript bhvBcFinalBossHintSign[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_final_boss_hint_sign),
    END_LOOP(),
};

extern void bhv_floor_switch_teleporter(void);
const BehaviorScript bhvFloorSwitchTeleporter[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    ID(id_bhvNewId),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_floor_switch_teleporter),
    END_LOOP(),
};

extern void bhv_coin_pile_init(void);
const BehaviorScript bhvCoinPile[] = {
    BEGIN(OBJ_LIST_LEVEL),
    ID(id_bhvNewId),
    // Yellow coin - common:
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_PERSISTENT_RESPAWN)),
    CALL_NATIVE(bhv_coin_pile_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_yellow_coin_loop),
    END_LOOP(),
};
*/