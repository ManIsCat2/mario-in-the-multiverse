#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "make_const_nonconst.h"
#include "levels/lll/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_lll_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _lll_segment_7SegmentRomStart, _lll_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bitfs_skybox_mio0SegmentRomStart, _bitfs_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario),
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, lll_area_1),
		WARP_NODE(2, LEVEL_LLL, 0x02, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_LLL, 0x01, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(4 /* lap 2 */, LEVEL_LLL, 5, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(5 /*exit*/, LEVEL_LLL, 0x06, 1, WARP_NO_CHECKPOINT),
		WARP_NODE(240 /*win*/, LEVEL_LLL, 0x06, 1, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_LLL, 0x06, 0x05, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 6700, 300, 0),
		OBJECT(MODEL_L_CHEESESLIME, 8016, 300, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 5550, -600, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -2900, -400, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -6500, 0, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 6900, -1300, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -450, -100, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 300, -600, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -1800, -600, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -750, 600, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -1850, 900, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -4000, 300, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CLOCK, -1950, 1250, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -1850, 1250, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -1850, 1350, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -1950, 1350, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -1450, 350, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -1350, 350, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -1250, 350, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -4750, 350, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -4650, 350, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -4550, 350, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -4650, -550, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -4550, -550, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -4450, -550, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 750, -550, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 850, -550, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 950, -550, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3350, -550, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3450, -550, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3550, -550, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 6650, -250, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 6750, -250, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 6850, -250, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 7750, -50, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 7450, 150, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_NONE, -5300, 300, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2000, -300, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4257, -600, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1800, -800, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2450, 1200, 8, 0, -180, 0, (2 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, 6250, 300, 10, 0, -180, 0, (5 << 16), bhvLDoor),
		OBJECT(MODEL_L_JOHNBLOCK, 9450, 650, 0, 0, 0, 0, (0 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 9450, 750, 0, 0, 0, 0, (0 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 6450, 350, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 6450, 450, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 6450, 550, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 6450, 650, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 6450, 750, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 6450, 850, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 6450, 950, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 6450, 1050, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 6450, 1150, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_PORTAL, 9700, 600, 0, 0, 0, 0, (4 << 16), bhvL_PizzaPortal),
		OBJECT(MODEL_PT_METAL_BOX, -7000, 0, 0, 0, 0, 0, 0x00000000, bhvPtMetalBox),
		OBJECT(MODEL_PT_METAL_BOX, -100, -603, 0, 0, 0, 0, 0x00000000, bhvPtMetalBox),
		OBJECT(MODEL_PT_METAL_BOX, -1000, -600, 0, 0, 0, 0, 0x00000000, bhvPtMetalBox),
		OBJECT(MODEL_PT_METAL_BOX, 7100, -300, 0, 0, 0, 0, 0x00000000, bhvPtMetalBox),
		OBJECT(MODEL_PT_METAL_BOX, 8700, -1100, 0, 0, 0, 0, 0x00000000, bhvPtMetalBox),
		OBJECT(MODEL_RED_COIN, 8700, -1300, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7600, -300, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -600, -600, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -8000, -200, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9200, 600, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5300, -900, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3184, 193, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -700, 300, 0, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 8200, 600, 0, 0, 0, 0, (1 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR, 6700, 600, 0, 0, 0, 0, (5 << 24), bhvL_EscapeStar),
		TERRAIN(lll_area_1_collision),
		MACRO_OBJECTS(lll_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, lll_area_2),
		WARP_NODE(2, LEVEL_LLL, 0x01, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_LLL, 0x02, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_LLL, 0x02, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_LLL, 0x02, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_LLL, 0x02, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(7, LEVEL_LLL, 0x03, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(8, LEVEL_LLL, 0x04, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(9, LEVEL_LLL, 0x05, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(241 /*death*/, LEVEL_LLL, 0x06, 0x05, WARP_NO_CHECKPOINT),
	//	OBJECT(MODEL_ABILITY, -541, 2638, -12, 0, 0, 0, (ABILITY_KNIGHT << 16), bhvAbilityUnlock),
	//	OBJECT(MODEL_ABILITY_SIGN, -11015, 16, 88, 0, -180, 0, (ABILITY_HM_FLY << 16), bhvStaticObject),
		OBJECT(MODEL_L_ANCHOVY, 2459, -2978, 0, 0, 90, 0, 0x00000000, bhvL_Anchovy),
		OBJECT(MODEL_L_ANCHOVY, -9591, 567, 0, 0, 90, 0, 0x00000000, bhvL_Anchovy),
		OBJECT(MODEL_L_ANCHOVY, 9859, 327, 0, 0, 90, 0, 0x00000000, bhvL_Anchovy),
		OBJECT(MODEL_L_CHEESESLIME, -1241, 1716, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -1941, 2016, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -591, 1416, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -5394, 516, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 8587, -3484, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 6154, -3484, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 6733, -3484, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 7412, -3484, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -9741, -1084, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -11741, 16, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 3659, 916, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 3159, -2784, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 8509, -2384, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 8659, -1284, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 10559, -584, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 8068, 1316, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CLOCK, 4609, -2834, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 4609, -2934, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 4609, -3034, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 4609, -3134, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 4209, -3134, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 4209, -3034, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 4209, -2934, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3609, -2934, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3709, -3134, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3709, -3534, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3609, -3334, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 2509, -3334, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 2409, -3334, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 2509, -3034, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 2409, -3034, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 2509, -2734, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 2409, -2734, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 1309, -434, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 1309, -34, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 1309, 66, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 1309, 166, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 2109, 166, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 2509, 166, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 2909, 166, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3609, 166, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 4409, 166, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 4809, 466, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 5009, 866, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 4609, 1066, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 5009, 1366, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3509, 1066, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3409, 1066, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3509, 1166, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3409, 1166, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 2609, 1366, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 2509, 1366, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 2609, 1466, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 2509, 1466, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3009, 1766, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 2909, 1766, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3009, 1866, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 2909, 1866, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -11891, -734, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -11691, -734, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -11491, -734, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -11291, -734, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -10191, 66, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -9991, 66, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -9791, 66, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -9591, 66, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -9191, 566, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -9091, 566, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -9091, 666, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -9191, 666, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -6891, 566, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -6791, 566, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -6791, 666, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -6891, 666, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -7491, 766, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -7891, 766, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -4991, 666, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -4891, 666, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -4891, 766, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -4991, 766, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_NONE, 14189, 5440, 5, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4059, 116, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1053, 716, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1529, 1116, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -6241, 816, 3, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -8591, 516, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -10641, -788, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5159, -3684, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 8259, -684, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 11009, 416, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2009, 1916, 14, 0, -180, 0, (2 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, 1009, -484, 14, 0, -180, 0, (3 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, -3991, 716, 14, 0, -180, 0, (4 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, -12691, -584, 14, 0, -180, 0, (5 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, 1609, -2784, 14, 0, -180, 0, (6 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, 6909, 216, 14, 0, -180, 0, (7 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, 8409, 1016, 14, 0, -180, 0, (8 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, 5109, -2684, 14, 0, -180, 0, (9 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, 11268, 1791, 0, 0, 0, 0, (0 << 16), bhvDreamCatalyst),
		OBJECT(MODEL_L_JOHNBLOCK, 2609, 1266, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 2509, 1266, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 4709, -2734, 0, 0, 0, 0, (0 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 4609, -2734, 0, 0, 0, 0, (0 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 5709, -3234, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 5709, -3334, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 5709, -3434, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 2309, 966, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 2309, 1066, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 2309, 1166, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 2209, 1166, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 2209, 1066, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 2209, 966, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 2909, 1666, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 3009, 1666, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 1309, -134, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_PT_METAL_BOX, 3459, 116, 0, 0, 0, 0, 0x00000000, bhvPtMetalBox),
		OBJECT(MODEL_PT_METAL_BOX, 3359, -3684, 0, 0, 0, 0, 0x00000000, bhvPtMetalBox),
		OBJECT(MODEL_PT_METAL_BOX, 9359, -2384, 0, 0, 0, 0, 0x00000000, bhvPtMetalBox),
		OBJECT(MODEL_PT_METAL_BOX, 7759, 216, 0, 0, 0, 0, 0x00000000, bhvPtMetalBox),
		OBJECT(MODEL_HEART, 9309, 315, 0, 0, 0, 0, 0x00000000, bhvRecoveryHeart),
		OBJECT(MODEL_STAR, -1941, 2771, 0, 0, 0, 0, (0 << 24), bhvStar),
		OBJECT(MODEL_STAR, -10841, 2557, 0, 0, 0, 0, (2 << 24), bhvStar),
		OBJECT(MODEL_NONE, 2771, 1183, 0, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -232, 2254, 0, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -10791, 447, 0, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2090, -3388, 0, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_THWOMP, 10309, 716, 0, 0, -180, 0, 0x00000000, bhvThwomp2),
		OBJECT(MODEL_THWOMP, 9609, 1016, 0, 0, -180, 0, 0x00000000, bhvThwomp2),
		TERRAIN(lll_area_2_collision),
		MACRO_OBJECTS(lll_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, lll_area_3),
		WARP_NODE(2, LEVEL_LLL, 0x02, 7, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_LLL, 0x03, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_LLL, 0x03, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_LLL, 0x02, 6/*undef*/, WARP_NO_CHECKPOINT),
		WARP_NODE(241 /*death*/, LEVEL_LLL, 0x06, 0x05, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_L_CHEESESLIME, 11059, 1150, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 6117, 650, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 10769, -950, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 7400, -650, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 7850, -650, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 900, 250, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -6106, 650, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -5600, 147, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -6006, -350, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -5497, -850, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -5994, -1350, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -5600, -1850, 0, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_NONE, 9950, 1150, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5800, -650, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 8900, -650, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2728, 247, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1400, 250, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -3563, 650, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 7834, 650, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 11950, 1150, 26, 0, -180, 0, (2 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, 11850, -350, 26, 0, -180, 0, (3 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, 3650, 250, 26, 0, -180, 0, (4 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, 10747, 414, 0, 0, 0, 0, (1 << 16), bhvDreamCatalyst),
		OBJECT(MODEL_PT_METAL_BOX, 1000, -150, 0, 0, 0, 0, 0x00000000, bhvPtMetalBox),
		OBJECT(MODEL_PT_METAL_BOX, -4700, 650, 0, 0, 0, 0, 0x00000000, bhvPtMetalBox),
		OBJECT(MODEL_HEART, 11540, -251, 0, 0, 0, 0, 0x00000000, bhvRecoveryHeart),
		OBJECT(MODEL_HEART, 11540, 1249, 0, 0, 0, 0, 0x00000000, bhvRecoveryHeart),
		OBJECT(MODEL_BLUE_COIN_SWITCH, 2000, 250, 0, 0, 0, 0, (3 << 24) | (45 << 16), bhvStarPieceSwitch),
		OBJECT(MODEL_STAR_PIECE, -5500, 650, 0, 0, 0, 0, 0x00000000, bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -6200, 150, 0, 0, 0, 0, 0x00000000, bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -5500, -350, 0, 0, 0, 0, 0x00000000, bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -6200, -850, 0, 0, 0, 0, 0x00000000, bhvStarPiece),
		OBJECT(MODEL_STAR_PIECE, -5500, -1350, 0, 0, 0, 0, 0x00000000, bhvStarPiece),
		OBJECT(MODEL_NONE, -4450, -1264, 0, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4450, -264, 0, 0, 0, 0, (1 << 16), bhvCoinFormation),
		TERRAIN(lll_area_3_collision),
		MACRO_OBJECTS(lll_area_3_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, lll_area_4),
		WARP_NODE(2, LEVEL_LLL, 0x02, 8, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_LLL, 0x05, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(241 /*death*/, LEVEL_L, 0x06, 0x05, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_L_ANCHOVY, 1674, 5230, 0, 0, 90, 0, 0x00000000, bhvL_Anchovy),
		OBJECT(MODEL_L_ANCHOVY, 2100, 3535, 0, 0, 90, 0, 0x00000000, bhvL_Anchovy),
		OBJECT(MODEL_L_ANCHOVY, 1048, -422, 0, 0, 90, 0, 0x00000000, bhvL_Anchovy),
		OBJECT(MODEL_L_ANCHOVY, -1432, -1626, 0, 0, 90, 0, 0x00000000, bhvL_Anchovy),
		OBJECT(MODEL_L_CHEESESLIME, -11568, -6100, -65, 0, -90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 2000, 1000, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 950, -2100, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -1676, -4100, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 1700, -4100, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 1567, -5100, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -1548, -4900, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -3688, -5200, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_NONE, -11372, 3025, -60, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1050, 5900, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 350, 3500, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1118, 1000, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 166, -1100, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 166, -3100, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2550, 5900, 10, 0, -180, 0, (2 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, -4650, -4800, 10, 0, -180, 0, (3 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, 2004, 4844, 0, 0, 0, 0, (2 << 16), bhvDreamCatalyst),
		OBJECT(MODEL_PT_METAL_BOX, -2200, -4900, 0, 0, 0, 0, 0x00000000, bhvPtMetalBox),
		OBJECT(MODEL_PT_METAL_BOX, 1400, -2100, 0, 0, 0, 0, 0x00000000, bhvPtMetalBox),
		OBJECT(MODEL_PT_METAL_BOX, 1800, -3100, 0, 0, 0, 0, 0x00000000, bhvPtMetalBox),
		OBJECT(MODEL_PT_METAL_BOX, 2700, 3000, 0, 0, 0, 0, 0x00000000, bhvPtMetalBox),
		OBJECT(MODEL_STAR, 3050, 3200, 0, 0, 0, 0, (4 << 24), bhvStar),
		OBJECT(MODEL_NONE, 100, 1995, 0, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2700, 221, 71, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -2400, -1661, 100, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2500, -2637, 0, 0, 0, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 204, 4570, 0, 0, 0, 0, (1 << 16), bhvCoinFormation),
		TERRAIN(lll_area_4_collision),
		MACRO_OBJECTS(lll_area_4_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(5, lll_area_5),
		WARP_NODE(2, LEVEL_LLL, 0x04, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_LLL, 0x02, 9, WARP_NO_CHECKPOINT),
		WARP_NODE(4 /* lap 2 start */, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(5 /* escape fail */, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(241 /*death*/, LEVEL_LLL, 0x06, 0x05, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_L_ANCHOVY, -952, -248, 0, 0, 90, 0, 0x00000000, bhvL_Anchovy),
		OBJECT(MODEL_L_ANCHOVY, 3707, -499, 0, 0, 90, 0, 0x00000000, bhvL_Anchovy),
		OBJECT(MODEL_L_ANCHOVY, 8073, -339, 0, 0, 90, 0, 0x00000000, bhvL_Anchovy),
		OBJECT(MODEL_L_ANCHOVY, 11244, 996, 0, 0, 90, 0, 0x00000000, bhvL_Anchovy),
		OBJECT(MODEL_L_ANCHOVY, 10275, 996, 0, 0, 90, 0, 0x00000000, bhvL_Anchovy),
		OBJECT(MODEL_L_ANCHOVY, 9513, 2007, 0, 0, 90, 0, 0x00000000, bhvL_Anchovy),
		OBJECT(MODEL_L_CHEESESLIME, -6050, 50, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -6050, 450, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -6050, 850, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -3370, -550, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -1805, 450, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, -2448, -550, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 1300, 750, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CHEESESLIME, 1317, 150, 0, 0, 90, 0, 0x00000000, bhvL_Cheeseslime),
		OBJECT(MODEL_L_CLOCK, 9450, -1100, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 9550, -1100, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 9650, -1100, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 9250, -400, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 9550, -100, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 9250, 500, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 11850, 1000, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 11450, 1400, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 11850, 1800, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 11850, 1900, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 11850, 2000, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 7750, 1700, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 7650, 1700, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 7550, 1700, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 7550, -1100, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 7450, -1100, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 7350, -1100, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 4950, -1100, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 4850, -1100, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 4750, -1100, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 5950, -600, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 5850, -600, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 5750, -600, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3650, -700, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3550, -700, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 3450, -700, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 1650, -600, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 1550, -600, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, 1450, -600, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -50, -700, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -150, -700, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -250, -700, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -1150, -500, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -1250, -500, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -1350, -500, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -4150, -500, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -4250, -500, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -4350, -500, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -6450, -200, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -6550, -200, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -6650, -200, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -7950, -700, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -8050, -700, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -8050, -600, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -7950, -600, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -10850, -500, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -10950, -500, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -10950, -400, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -10850, -400, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -13150, -500, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -13250, -500, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -13250, -400, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -13150, -400, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -15450, -400, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -15550, -400, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -15550, -300, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_L_CLOCK, -15450, -300, 0, 0, 0, 0, 0x00000000, bhvLclock),
		OBJECT(MODEL_NONE, -6801, 850, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -5344, -250, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -658, 750, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 1450, -850, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5750, -850, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 10594, -1150, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 12070, -1150, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 9250, 1650, 0, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -7950, 350, 21, 0, -180, 0, (2 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, -17350, -550, 21, 0, -180, 0, (3 << 16), bhvLDoor),
		OBJECT(MODEL_NONE, 10741, 83, 0, 0, 0, 0, (3 << 16), bhvDreamCatalyst),
		OBJECT(MODEL_NONE, 12700, -750, 0, 0, -90, 0, (5 << 16), bhvAirborneDeathWarp),
		OBJECT(MODEL_L_JOHNBLOCK, 9150, -900, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, 9150, -800, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, -7150, -200, 0, 0, 0, 0, (0 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, -7250, -200, 0, 0, 0, 0, (0 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, -7250, -100, 0, 0, 0, 0, (0 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, -7150, -100, 0, 0, 0, 0, (0 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, -7450, 800, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, -7550, 800, 0, 0, 0, 0, (1 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, -1750, -400, 0, 0, 0, 0, (0 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, -1750, -500, 0, 0, 0, 0, (0 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, -2150, -300, 0, 0, 0, 0, (0 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, -2250, -300, 0, 0, 0, 0, (0 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, -2450, 100, 0, 0, 0, 0, (0 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHNBLOCK, -2550, 100, 0, 0, 0, 0, (0 << 16), bhvJohnBlock),
		OBJECT(MODEL_L_JOHN, 13688, -1150, 0, 0, 0, 0, 0x00000000, bhvL_JohnPillar),
		OBJECT(MODEL_NONE, 12800, -750, 0, 0, -90, 0, (4 << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 7619, 1122, 0, 0, 0, 0, (6 << 16), bhvCollectablePainting),
		OBJECT(MODEL_THWOMP, 11050, 1650, 0, 0, -180, 0, 0x00000000, bhvThwomp2),
		TERRAIN(lll_area_5_collision),
		MACRO_OBJECTS(lll_area_5_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(6, lll_area_6),
		WARP_NODE(1 /*exit1*/, LEVEL_LLL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(2 /*exit2*/, LEVEL_LLL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(3 /*door 1*/, LEVEL_LLL, 0x01, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(4 /*door 2*/, LEVEL_LLL, 0x07, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(5/*death entry*/, LEVEL_LLL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(241 /*death*/, LEVEL_LLL, 0x06, 0x05, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0A /*entry*/, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 265, 0, 0, 0, 0, (5 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, -1356, 0, 0, 0, 0, 0, (10 << 24) | (3 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 1356, 0, 0, 0, 0, 0, (10 << 24) | (4 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 0, 265, 0, 0, 0, 0, (0x0A << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -790, 0, 0, 0, 90, 0, (1 << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 812, 0, 0, 0, -90, 0, (2 << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_LEVEL_PIPE, 0, 0, -1275, 0, 0, 0, 0x00000000, bhvLevelPipe),
		OBJECT(MODEL_NONE, 0, 704, 2406, 0, 0, 0, 0x00000000, bhvPepperArt),
		OBJECT(MODEL_L_PEPPERMAN, 0, 0, 1267, 0, -180, 0, (7 << 24), bhvL_PeppermanNPC),
		TERRAIN(lll_area_6_collision),
		MACRO_OBJECTS(lll_area_6_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(7, lll_area_7),
		WARP_NODE(241 /*death*/, LEVEL_LLL, 0x06, 0x05, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0A /*entry*/, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(240 /*win*/, LEVEL_LLL, 0x06, 2, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_YELLOW_COIN, 1078, 108, 1078, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -1078, 108, 1078, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -1078, 108, -1078, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 1078, 108, -1078, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_L_PEPPERMAN, 0, 108, -870, 0, 0, 0, (6 << 24), bhvL_PeppermanBoss),
		OBJECT(MODEL_NONE, 0, 424, 930, 0, -180, 0, (0x0A << 16), bhvSpinAirborneWarp),
		TERRAIN(lll_area_7_collision),
		MACRO_OBJECTS(lll_area_7_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 6700, 300, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};