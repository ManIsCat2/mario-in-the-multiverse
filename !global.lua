-- Global Variables --

-- Custom Mod

TEX_DPAD                 = get_texture_info("dpad_texture")
TEX_HUDBAR               = get_texture_info("hudbar_texture")
TEX_MAINMENU             = get_texture_info("mainmenu_texture")
TEX_SELECTOR             = get_texture_info("selecterhud_texture")
TEX_METER1               = get_texture_info("meter_1_hp_circle_ia8")
TEX_METER2               = get_texture_info("meter_2_hp_circle_ia8")
TEX_METER3               = get_texture_info("meter_3_hp_circle_ia8")
TEX_METER4               = get_texture_info("meter_4_hp_circle_ia8")
TEX_METER5               = get_texture_info("meter_5_hp_circle_ia8")
TEX_METER6               = get_texture_info("meter_6_hp_circle_ia8")
TEX_METER7               = get_texture_info("meter_7_hp_circle_ia8")
TEX_METER8               = get_texture_info("meter_8_hp_circle_ia8")
TEX_METER_CIRCLE         = get_texture_info("meter_bg_circle_transparent_ia8")
TEX_HEART_METER          = get_texture_info("meter_hp_heart_ia8")
TEX_AKU_METER            = get_texture_info("meter_aku_stars_ia8")
ability_util             = { str = nil, display = false, seq = false }

-- Defining NULL

NULL                     = nil

-- Level Nums

LEVEL_INK_TEST           = 39
LEVEL_X                  = 40
LEVEL_G                  = 41
LEVEL_B                  = 42
LEVEL_A                  = 43
LEVEL_F                  = 44
LEVEL_E                  = 45
LEVEL_I                  = 46
LEVEL_J                  = 47
LEVEL_M                  = 48
LEVEL_O                  = 49
LEVEL_D                  = 50
LEVEL_N                  = 51
LEVEL_H                  = 52
LEVEL_C                  = 53
LEVEL_BIRTHDAY           = 54
LEVEL_L                  = 55
LEVEL_BOWSER_COURSE      = 56
LEVEL_K                  = 57
LEVEL_SB                 = 58
LEVEL_MC                 = 59
LEVEL_BB                 = 60

-- Ability Enum

ABILITY_DEFAULT          = 0
ABILITY_CUTTER           = 1
ABILITY_BUBBLE_HAT       = 2
ABILITY_SQUID            = 3
ABILITY_SHOCK_ROCKET     = 4
ABILITY_PHASEWALK        = 5
ABILITY_BIG_DADDY        = 6
ABILITY_KNIGHT           = 7
ABILITY_CHRONOS          = 8
ABILITY_E_SHOTGUN        = 9
ABILITY_GADGET_WATCH     = 10
ABILITY_HM_FLY           = 11
ABILITY_AKU              = 12
ABILITY_ESTEEMED_MORTAL  = 13
ABILITY_MARBLE           = 14
ABILITY_DASH_BOOSTER     = 15
ABILITY_UTIL_COMPASS     = 16
ABILITY_UTIL_MILK        = 17
ABILITY_UTIL_MIRROR      = 18
ABILITY_NONE             = 19
ABILITY_LOCK_IMAGE_INDEX = 20

-- Menu

LMENU_ABILITY_HUD        = 0
LMENU_HUD_ALPHA          = 20
LMENU_TITLE_CARD         = 21
LMENU_DIALOG_OPEN        = 22
LMENU_DIALOG_SCALE       = 23
LMENU_TRANSITION         = 24
LMENU_PAUSE              = 25
LMENU_FILE_1             = 26
LMENU_FILE_2             = 27
LMENU_FILE_3             = 28
LMENU_FILE_BACKCARD      = 29
LMENU_COUNT              = 30

-- Hud
TEXT_PIPE_NOT_ENOUGH     = ("Needed : ")
TEXT_QUESTION            = ("???")
TEXT_PIPE_ENTER          = (" :Enter   :Cancel")
TEXT_PIPE_A              = (" A")
TEXT_PIPE_B              = ("          B")
TEXT_PIPE_Z              = ("[Z]")

TEXT_ABILITY_DEFAULT     = {
    "Mario's Cap:",
    "Mario's basic moveset as you know it."
}

TEXT_ABILITY_A           = {
    "Bubble Hat & Net: Spongebob's prized toolset.",
    "Lets you catch jellyfish & break tiki boxes.",
    "Press [A] midair to do a bubble glide!"
}

TEXT_ABILITY_B           = {
    "Helmet & Drill: From a deceased Big Daddy.",
    "The drill can break cement blocks.",
    "While underwater you maintain normal movement."
}

TEXT_ABILITY_C           = {
    "Inkling: You're a kid now, you're a squid now!",
    "Press [L] to transform to and from squid form.",
    "Can swim in ink puddles, but water kills you."
}

TEXT_ABILITY_D           = {
    "Aku Aku: A mask with a spirit inside.",
    "Press [L] to spend 10 coins and activate 10",
    "seconds of invincibility. Can walk on lava."
}

TEXT_ABILITY_E           = {
    "Doom Shotgun:  Press [L] to fire!",
    "On ground, Mario will fire forward. In the air,",
    "he'll fire downward. Toggle aim mode with [R]."
}

TEXT_ABILITY_F           = {
    "Gadget Watch: Belongs to James Bond.",
    "Will target switches and breakable objects.",
    "Once targeted, press [L] to zap the object."
}

TEXT_ABILITY_G           = {
    "Cutter: A set of cut-based abilities.",
    "[B] - Cutter Throw, [B](moving) - Cutter Dash",
    "[B](near enemy) - Final Cutter"
}

TEXT_ABILITY_H           = {
    "Phasewalk: Press [L] to activate. Mario will",
    "become invisible and get an increase in running",
    "speed, and get a jump boost at the end."
}

TEXT_ABILITY_I           = {
    "Shock Rocket: A guided exploding rocket.",
    "Press [L] while static to aim, then [B] to fire.",
    "Once launched, guide it with the analog stick."
}

TEXT_ABILITY_J           = {
    "HM Fly: Call upon your Pokemon pal to soar",
    "high into the sky.",
    "Press [A] while in the air to begin flying."
}

TEXT_ABILITY_K           = {
    "Chronos: A dangerous precognitive drug,",
    "alongside an even deadlier katana.",
    "Press [B] to slash, and hold [L] to slow time."
}

TEXT_ABILITY_L           = {
    "Pizza Knight: A heavy suit of knight armor.",
    "Limits Mario's move set, but lets him slide off",
    "slopes to break metal blocks and double jump."
}

TEXT_ABILITY_M           = {
    "Dash Booster: Allows Mario to air dash.",
    "Press [Z] to go up, [L] to go horizontal.",
    "Limit of 3 dashes per jump."
}

TEXT_ABILITY_N           = {
    "Hamster Ball: A hollow ball that Mario can",
    "enter. Use the analog stick to roll around",
    "with sphere physics!"
}

TEXT_ABILITY_O           = {
    "Esteemed Mortal: A walker slaying saw-axe.",
    "Replaces your dive with an axe jump.",
    "Hold [B] to hop and hold [A] to jump higher."
}

TEXT_ABILITY_UTIL_1      = {
    "Compass: Powered by Redstone!",
    "When held, will point to the nearest red coin or",
    "star mission specific object."
}

TEXT_ABILITY_UTIL_2      = {
    "Lon Lon Milk: Highly nutritious!",
    "Press [L] to drink and restore 5 HP.",
    "Refills between levels and after deaths."
}

TEXT_ABILITY_UTIL_3      = {
    "Magic Mirror: Gaze in the mirror to return home.",
    "Press [L] to warp to the last checkpoint."
}

pipe_string_not_enough   = TEXT_PIPE_NOT_ENOUGH
pipe_string_enter        = TEXT_PIPE_ENTER
pipe_string_a            = TEXT_PIPE_A
pipe_string_b            = TEXT_PIPE_B
pipe_string_z            = TEXT_PIPE_Z

abstr_def                = TEXT_ABILITY_DEFAULT
abstr_a                  = TEXT_ABILITY_A
abstr_b                  = TEXT_ABILITY_B
abstr_c                  = TEXT_ABILITY_C
abstr_d                  = TEXT_ABILITY_D
abstr_e                  = TEXT_ABILITY_E
abstr_f                  = TEXT_ABILITY_F
abstr_g                  = TEXT_ABILITY_G
abstr_h                  = TEXT_ABILITY_H
abstr_i                  = TEXT_ABILITY_I
abstr_j                  = TEXT_ABILITY_J
abstr_k                  = TEXT_ABILITY_K
abstr_l                  = TEXT_ABILITY_L
abstr_m                  = TEXT_ABILITY_M
abstr_n                  = TEXT_ABILITY_N
abstr_o                  = TEXT_ABILITY_O

abstr_util_1             = TEXT_ABILITY_UTIL_1
abstr_util_2             = TEXT_ABILITY_UTIL_2
abstr_util_3             = TEXT_ABILITY_UTIL_3


-- Behavior
MODEL_LEVEL_PIPE                = smlua_model_util_get_id("level_pipe_geo")
MODEL_CHECKPOINT_FLAG           = smlua_model_util_get_id("checkpoint_flag_geo")
MODEL_G_BANANA_DEE              = smlua_model_util_get_id("g_banana_dee_geo")
MODEL_G_SPRING                  = smlua_model_util_get_id("g_spring_geo")
MODEL_G_WADDLE_DEE              = smlua_model_util_get_id("g_waddle_dee_geo")
MODEL_ATTACHED_ROPE             = smlua_model_util_get_id("attached_rope_geo")
MODEL_HUBPLATFORM               = smlua_model_util_get_id("hub_platform_geo")
MODEL_G_BRONTO_BURT             = smlua_model_util_get_id("g_bronto_burt_geo")
MODEL_G_CANNON                  = smlua_model_util_get_id("g_cannon_geo")
MODEL_G_CHECKER_BLOCK_1         = smlua_model_util_get_id("checker_block_1_geo")
MODEL_G_SIR_KIBBLE              = smlua_model_util_get_id("sir_kibble_geo")
MODEL_CUTTER_BLADE              = smlua_model_util_get_id("cutter_blade_geo")
MODEL_G_STAR_PROJECTILE         = smlua_model_util_get_id("star_projectile_geo")
MODEL_G_STAR_BLOCK              = smlua_model_util_get_id("star_block_geo")
MODEL_ABILITY                   = smlua_model_util_get_id("ability_unlock_geo")
MODEL_G_CUT_ROCK                = smlua_model_util_get_id("g_cut_rock_geo")
MODEL_G_CUT_ROCK2               = smlua_model_util_get_id("g_cut_rock2_geo")
MODEL_G_CUT_ROCK3               = smlua_model_util_get_id("g_cut_rock3_geo")
MODEL_PAINTING                  = smlua_model_util_get_id("collectable_painting_geo")
MODEL_G_MOVING_PLATFORM         = smlua_model_util_get_id("g_moving_platform_geo")
MODEL_JELLY                     = smlua_model_util_get_id("jelly_geo")
MODEL_TIKI_WOOD                 = smlua_model_util_get_id("tikibox_geo")
MODEL_TIKI_STONE                = smlua_model_util_get_id("stone_tiki_geo")
MODEL_TIKI_FLOAT                = 0 --0x15A
MODEL_TRAMP                     = smlua_model_util_get_id("tramp_geo")
MODEL_ABILITY_SIGN              = smlua_model_util_get_id("ability_sign_geo")
MODEL_A_CAGE                    = smlua_model_util_get_id("a_cage_geo")
MODEL_FLOATING_CHECKER_PLATFORM = smlua_model_util_get_id("floating_checker_platform_geo")
MODEL_TAXISTOP                  = smlua_model_util_get_id("taxistop_geo")
MODEL_TSBOAT                    = smlua_model_util_get_id("boat_geo")
MODEL_OCTOBA                    = smlua_model_util_get_id("octoba_geo")
MODEL_OCTOBALL                  = smlua_model_util_get_id("octoball_geo")
MODEL_PAINT_STAIN               = smlua_model_util_get_id("paint_stain_geo")
MODEL_SQUID                     = smlua_model_util_get_id("squid_geo")
MODEL_INK_MOVING_PLATFORM       = smlua_model_util_get_id("ink_moving_platform_geo")
MODEL_PAINT_GUN                 = smlua_model_util_get_id("paint_gun_geo")
MODEL_PAINT_BULLET              = smlua_model_util_get_id("paint_bullet_geo")
MODEL_FUNKY_ROAD                = smlua_model_util_get_id("funky_road_geo")
MODEL_NITRO_BOX                 = smlua_model_util_get_id("nitro_geo")
MODEL_BUBBLENET_RED_BUTTON      = smlua_model_util_get_id("bh_red_button_geo")
MODEL_BHBRIDGE                  = smlua_model_util_get_id("bhbridge_geo")
MODEL_A_PLANK                   = smlua_model_util_get_id("a_plank_geo")
MODEL_NITRO_BOOM                = smlua_model_util_get_id("nitroboom_geo")
MODEL_STAR_PIECE                = smlua_model_util_get_id("star_piece_geo")
MODEL_STAR_BOULDER              = smlua_model_util_get_id("star_boulder_geo")
MODEL_CRANE_ARROW               = smlua_model_util_get_id("crane_arrow_geo")
MODEL_CRANE_HEAD                = smlua_model_util_get_id("crane_head_geo")
MODEL_CRANE                     = smlua_model_util_get_id("crane_geo")

BP3_ATTACH_ROPE                    = 0xF0

OBJ_FLAG_ATTACHABLE_BY_ROPE        = OBJ_FLAG_1000
OBJ_FLAG_NO_DREAM_COMET            = (1 << 22)
----E SG coll
OBJ_FLAG_E__SG_ENEMY               = (1 << 24) --Used for common enemies - flattens the enemy against the surface that they were shot against, spawns their coins
OBJ_FLAG_E__SG_BOSS                = (1 << 25) --Used for bosses mostly. Pushes them back, if they don't take damage from being shot
OBJ_FLAG_E__SG_BREAKABLE           = (1 << 26) --Usually used for small static objects - creates a small breaking effect and spawns the object's contents
OBJ_FLAG_E__SG_COLLISION_BREAKABLE = (1 << 27) --Used for larger objects with collision models. If oHealth is set to 0 (or has its default value of 2048), it'll break in one shot.\
--Otherwise, oHealth will determine how many shots it takes to break, and will increment its model ID by 1, to show that damage is being done to the object\
--(Load all model IDs of different states of damage in a row, going from least to most damaged)

--[[
    Note: Objects that use either of these 'custom' flags need to reset oShotByShotgun back to 0 again after they're shot, if you want them to be able to be shot more than once.
    This is very much like how you reset oInteractStatus to 0, when managing interactions on a more manual level.
    ]]
OBJ_FLAG_E__SG_CUSTOM                = (1 << 28) --Only adds to oShotByShotgun to let the object know that it was shot, so that the object's behavior can do what it needs to from there
OBJ_FLAG_E__SG_COLLISION_CUSTOM      = (1 << 29) --Same as OBJ_FLAG_E__SG_CUSTOM, but for objects with collision models
OBJ_FLAG_ABILITY_CHRONOS_SMOOTH_SLOW = (1 << 31)

-- Music
SEQ_CUSTOM_KIRBY_BOSS                = 0x26
SOUND_ABILITY_CUTTER_CATCH           = audio_stream_load("ability_cutter_catch.aiff")
SOUND_ABILITY_CUTTER_DASH            = audio_stream_load("ability_cutter_dash.aiff")
SOUND_ABILITY_CUTTER_THROW           = audio_sample_load("ability_cutter_throw.aiff")
SOUND_MITM_LEVEL_TLIM_TAXI           = audio_sample_load("tlim_taxi.aiff")
SOUND_ABILITY_AKU_AKU                = audio_stream_load("ability_aku.aiff")

-- Floor
SURFACE_SQUID_INK                    = SURFACE_TRAPDOOR + 16
SURFACE_TOXIC_INK                    = SURFACE_TRAPDOOR + 32

CAMERA_MODE_PAINT_GUN                = CAMERA_MODE_ROM_HACK + 0x01

function set_custom_mario_animation_with_accel(m, targetAnimID, accel, a)
    local o = m.marioObj

    o.header.gfx.animInfo.animID = targetAnimID
    smlua_anim_util_set_animation(o, a)

    return o.header.gfx.animInfo.animFrame
end

local function BIT(i) return (1 << (i)) end
local function BITMASK(size) return ((BIT(size)) - 1) end

-- Number of bparams in oBehParams
NUM_BPARAMS = 4
-- Number of bits in one bparam
BPARAM_SIZE = 8
-- Number of bits in bparam bitmask
local function BPARAM_MASK_SIZE(num) return (BPARAM_SIZE * (num)) end
-- bparam bitmask ('num' 1 -> 0xFF, 'num' 2 -> 0xFFFF, etc.)
local function BPARAM_MASK(num) return BITMASK(BPARAM_MASK_SIZE(num)) end
-- Returns the amount of bits to shift a bparam value ('index' == bparam index)
local function BPARAM_NSHIFT(index, num) return (((NUM_BPARAMS - ((num) - 1)) - (index)) * BPARAM_SIZE) end
-- Returns the bparam(s) value from the index location in oBehParams
local function GET_BPARAMS(behParams, index, num) return ((behParams >> BPARAM_NSHIFT((index), (num))) & BPARAM_MASK(num)) end

-- Read 2 bparams as a single value

function GET_BPARAM34(behParams) return GET_BPARAMS((behParams), 3, 2) end

-- Dream Data

mitmdd_a                                 = { ability_lock = { ABILITY_DEFAULT, ABILITY_MARBLE, ABILITY_NONE, ABILITY_NONE }, dream_star_ct = 5 } ---@type mitm_dream_data
mitmdd_b                                 = { ability_lock = { ABILITY_DEFAULT, ABILITY_UTIL_MIRROR, ABILITY_BIG_DADDY, ABILITY_NONE }, dream_star_ct = 6 } ---@type mitm_dream_data
mitmdd_c                                 = { ability_lock = { ABILITY_DEFAULT, ABILITY_PHASEWALK, ABILITY_NONE, ABILITY_NONE }, dream_star_ct = 5 } ---@type mitm_dream_data
mitmdd_d                                 = { ability_lock = { ABILITY_DEFAULT, ABILITY_UTIL_MIRROR, ABILITY_AKU, ABILITY_NONE }, dream_star_ct = 7 } ---@type mitm_dream_data
mitmdd_e                                 = { ability_lock = { ABILITY_DEFAULT, ABILITY_UTIL_MIRROR, ABILITY_E_SHOTGUN, ABILITY_NONE }, dream_star_ct = 8 } ---@type mitm_dream_data
mitmdd_f                                 = { ability_lock = { ABILITY_DEFAULT, ABILITY_GADGET_WATCH, ABILITY_PHASEWALK, ABILITY_NONE }, dream_star_ct = 6 } ---@type mitm_dream_data
mitmdd_g                                 = { ability_lock = { ABILITY_DEFAULT, ABILITY_UTIL_MIRROR, ABILITY_NONE, ABILITY_NONE }, dream_star_ct = 7 } ---@type mitm_dream_data
mitmdd_h                                 = { ability_lock = { ABILITY_DEFAULT, ABILITY_UTIL_MIRROR, ABILITY_PHASEWALK, ABILITY_NONE }, dream_star_ct = 7 } ---@type mitm_dream_data
mitmdd_i                                 = { ability_lock = { ABILITY_DEFAULT, ABILITY_CUTTER, ABILITY_NONE, ABILITY_NONE }, dream_star_ct = 7 } ---@type mitm_dream_data
mitmdd_j                                 = { ability_lock = { ABILITY_DEFAULT, ABILITY_BUBBLE_HAT, ABILITY_SQUID, ABILITY_NONE }, dream_star_ct = 8 } ---@type mitm_dream_data
mitmdd_k                                 = { ability_lock = { ABILITY_DEFAULT, ABILITY_UTIL_MIRROR, ABILITY_CHRONOS, ABILITY_NONE }, dream_star_ct = 7 } ---@type mitm_dream_data
mitmdd_l                                 = { ability_lock = { ABILITY_DEFAULT, ABILITY_KNIGHT, ABILITY_NONE, ABILITY_NONE }, dream_star_ct = 4 } ---@type mitm_dream_data
mitmdd_m                                 = { ability_lock = { ABILITY_DEFAULT, ABILITY_UTIL_MIRROR, ABILITY_PHASEWALK, ABILITY_KNIGHT }, dream_star_ct = 8 } ---@type mitm_dream_data
mitmdd_n                                 = { ability_lock = { ABILITY_DEFAULT, ABILITY_E_SHOTGUN, ABILITY_BUBBLE_HAT, ABILITY_NONE }, dream_star_ct = 7 } ---@type mitm_dream_data
mitmdd_o                                 = { ability_lock = { ABILITY_DEFAULT, ABILITY_UTIL_MIRROR, ABILITY_HM_FLY, ABILITY_GADGET_WATCH }, dream_star_ct = 8 } ---@type mitm_dream_data

--In course order, not alphabetical!
--Only mess with --[[ Level ]] entry, everything else is pre-configured
---@type mitm_level_data[]
mitm_levels                              = {
    --[[ Name, Author(s)]]
    --[[Level     StarFlags     StarReq  StartArea  ReturnWarp  StarCt DreamData]]
    [0] = { name = "MARIO SUPER STAR ULTRA", author = "CowQuack", author_abridged = "CowQuack", level = LEVEL_G, course = COURSE_BOB, star_requirement = 0, start_area = 3, return_id = 20, star_count = 8, dream_data = mitmdd_g },
    --[[A]] { name = "MARIO IN BIKINI BOTTOM", author = "JoshTheBosh",           author_abridged = "JoshTheBosh",     level = LEVEL_A,             course = COURSE_WF,    star_requirement = 2,  start_area = 1,        return_id = 21, star_count = 8, dream_data = mitmdd_a },
    --[[C]] { name = "PIRANHA PIT",  author = "Drahnokks, Idea by: Woissil",     author_abridged = "Drahnokks & Co.", level = LEVEL_C,             course = COURSE_JRB,   star_requirement = 2,  start_area = 1,        return_id = 22, star_count = 8, dream_data = mitmdd_c },
    --[[I]] { name = "MUSHROOM HAVOC", author = "Drahnokks",                     author_abridged = "Drahnokks",       level = LEVEL_I,             course = COURSE_CCM,   star_requirement = 5,  start_area = 1,        return_id = 23, star_count = 8, dream_data = mitmdd_i },
    --[[H]] { name = "OPPORTUNITY",  author = "joopii",                          author_abridged = "joopii",          level = LEVEL_H,             course = COURSE_BBH,   star_requirement = 10, start_area = 1,        return_id = 24, star_count = 8, dream_data = mitmdd_h },
    --[[B]] { name = "BIOSHOCK RAPTURE", author = "furyiousfight",               author_abridged = "furyiousfight",   level = LEVEL_B,             course = COURSE_HMC,   star_requirement = 15, start_area = 1,        return_id = 25, star_count = 8, dream_data = mitmdd_b },
    --[[L]] { name = "BEYOND THE CURSED PIZZA", author = "luigiman0640",         author_abridged = "luigiman0640",    level = LEVEL_L,             course = COURSE_LLL,   star_requirement = 20, start_area = 6,        return_id = 26, star_count = 8, dream_data = mitmdd_l },
    --[[K]] { name = "KATANA MARIO NEW MECCA", author = "KeyBlader, Ability by: axollyon", author_abridged = "KeyBlader & Co.", level = LEVEL_K,   course = COURSE_SSL,   star_requirement = 20, start_area = 2,        return_id = 27, star_count = 8, dream_data = mitmdd_k },
    --[[E]] { name = "DOOM",         author = "Dorrieal",                        author_abridged = "Dorrieal",        level = LEVEL_E,             course = COURSE_DDD,   star_requirement = 30, start_area = 1,        return_id = 28, star_count = 8, dream_data = mitmdd_e },
    --[[F]] { name = "FROM RUSSIA WITH LOVE", author = "Aeza",                   author_abridged = "Aeza",            level = LEVEL_F,             course = COURSE_SL,    star_requirement = 30, start_area = 1,        return_id = 29, star_count = 8, dream_data = mitmdd_f },
    --[[J]] { name = "ECRUTEAK CITY", "SpK",                                     author = "SpK",                      author_abridged = NULL,      level = LEVEL_J,       course = COURSE_WDW,   star_requirement = 40, start_area = 1, return_id = 30, star_count = 8,       dream_data = mitmdd_j },
    --[[D]] { name = "NEW N-SANITY ISLAND", author = "JakeDower",                author_abridged = "JakeDower",       level = LEVEL_D,             course = COURSE_TTM,   star_requirement = 50, start_area = 1,        return_id = 31, star_count = 8, dream_data = mitmdd_d },
    --[[O]] { name = "SAINTS, SINNERS, & MARIO", author = "Rovertronic",         author_abridged = "Rovertronic",     level = LEVEL_O,             course = COURSE_THI,   star_requirement = 50, start_area = 1,        return_id = 32, star_count = 8, dream_data = mitmdd_o },
    --[[N]] { name = "MARIO IN HAMSTERBALL", author = "LinCrash",                author_abridged = "LinCrash",        level = LEVEL_N,             course = COURSE_TTC,   star_requirement = 60, start_area = 1,        return_id = 33, star_count = 8, dream_data = mitmdd_n },
    --[[M]] { name = "ENVIRONMENTAL STATION M", author = "Mel",                  author_abridged = "Mel",             level = LEVEL_M,             course = COURSE_RR,    star_requirement = 60, start_area = 1,        return_id = 34, star_count = 8, dream_data = mitmdd_m },
    --[[BC]] { name = "CENTRUM OMNIUM", author = NULL,                           author_abridged = NULL,              level = LEVEL_BOWSER_COURSE, course = COURSE_BITDW, star_requirement = 80, start_area = 0,        return_id = 37, star_count = 1, dream_data = NULL },
    --[[HUB]] { name = "METAXY ISLES", author = NULL,                            author_abridged = NULL,              level = NULL,                course = COURSE_BITFS, star_requirement = 0,  start_area = 0,        return_id = 34, star_count = 2, dream_data = NULL },
    --[[PW]] { name = "PAINTING WORLD", author = NULL,                           author_abridged = NULL,              level = NULL,                course = COURSE_NONE,  star_requirement = 0,  start_area = 0,        return_id = 36, star_count = 0, dream_data = NULL },
    --[[SB]] { name = "GAPS AND HANDS", author = NULL,                           author_abridged = NULL,              level = NULL,                course = COURSE_NONE,  star_requirement = 0,  start_area = 0,        return_id = 36, star_count = 0, dream_data = NULL },
    --[[MC]] { name = "Mute City",   author = "BroDute",                         author_abridged = "BroDute",         level = NULL,                course = COURSE_PSS,   star_requirement = 0,  start_area = 0,        return_id = 36, star_count = 1, dream_data = NULL },
    --[[BB]] { name = "Big Blue",    author = "BroDute",                         author_abridged = "BroDute",         level = NULL,                course = COURSE_WMOTR, star_requirement = 0,  start_area = 0,        return_id = 36, star_count = 1, dream_data = NULL },
};

mario_right_hand_closed                  = gfx_get_from_name("mario_right_hand_closed")
local cutter_hat_Circle_mesh_layer_1     = gfx_get_from_name("cutter_hat_Circle_mesh_layer_1")
local net_hand_2_hand_mesh               = gfx_get_from_name("net_hand_2_hand_mesh")
local bubble_hat_bhat_mesh               = gfx_get_from_name("bubble_hat_bhat_mesh")
cutter_hand_right_hand_open_mesh_layer_1 = gfx_get_from_name("cutter_hand_right_hand_open_mesh_layer_1")
bubblehat_hand_hand_mesh                 = gfx_get_from_name("bubblehat_hand_hand_mesh")
gfx_empty                                = gfx_get_from_name("GFXEMPTY")
local squid_hat_lunette_mesh             = gfx_get_from_name("squid_hat_lunette_mesh")
local ability_d_mask_hat_mesh            = gfx_get_from_name("ability_d_mask_hat_mesh")

-- Ability struct
ability_struct                           = {
    --           HAND DISPLAY LIST        HAT DISPLAY LIST     MARIO MODEL ID     STRING
    --Default
    [0] = { hand = mario_right_hand_closed, hat = gfx_empty, model_id = nil, string = abstr_def },
    --G
    { hand = mario_right_hand_closed,                hat = cutter_hat_Circle_mesh_layer_1, model_id = nil,                string = abstr_g },
    --A
    { hand = net_hand_2_hand_mesh,                   hat = bubble_hat_bhat_mesh,           model_id = nil,                string = abstr_a },
    --C
    { hand = mario_right_hand_closed,                hat = squid_hat_lunette_mesh,         model_id = nil,                string = abstr_c },
    --I
    { hand = rocket_hand_RaymanMissile_mesh_layer_1, hat = gfx_empty,                      model_id = nil,                string = abstr_i },
    --H
    { hand = phasewalk_hand_hand_mesh,               hat = gfx_empty,                      model_id = nil,                string = abstr_h },
    --B
    { hand = bigdaddyhand_Plane_mesh,                hat = bigdaddyhat_bigdaddy_mesh,      model_id = nil,                string = abstr_b },
    --L
    { hand = mario_right_hand_closed,                hat = gfx_empty,                      model_id = MODEL_KNIGHT_MARIO, string = abstr_l },
    --K
    { hand = mario_right_hand_closed,                hat = gfx_empty,                      model_id = nil_K,              string = abstr_k },
    --E
    { hand = mario_right_hand_closed,                hat = gfx_empty,                      model_id = MODEL_E__MARIO,     string = abstr_e },
    --F
    { hand = hand_f_hand_mesh,                       hat = hat_f_hat_mesh,                 model_id = nil,                string = abstr_f },
    --J
    { hand = pokeball_hand_hand_mesh,                hat = gfx_empty,                      model_id = nil,                string = abstr_j },
    --D
    { hand = mario_right_hand_closed,                hat = ability_d_mask_hat_mesh,        model_id = nil,                string = abstr_d },
    --O
    { hand = mario_right_hand_closed,                hat = gfx_empty,                      model_id = MODEL_SAWAXE_MARIO, string = abstr_o },
    --N
    { hand = mario_right_hand_closed,                hat = gfx_empty,                      model_id = nil,                string = abstr_n },
    --M
    { hand = hand_m_hand_mesh,                       hat = gfx_empty,                      model_id = nil,                string = abstr_m },

    --Util1
    { hand = compass_hand_hand_mesh,                 hat = gfx_empty,                      model_id = nil,                string = abstr_util_1 },
    --Util2
    { hand = milk_hand_hand_mesh,                    hat = gfx_empty,                      model_id = nil,                string = abstr_util_2 },
    --Util3
    { hand = mirror_hand_hand_mesh,                  hat = gfx_empty,                      model_id = nil,                string = abstr_util_3 },
}

title_card_data                          = {
    [0] = get_texture_info("custom_titlecard_G.rgba16")
    ,
    get_texture_info("custom_titlecard_A.rgba16")
    ,
    get_texture_info("custom_titlecard_C.rgba16")
    ,
    get_texture_info("custom_titlecard_I.rgba16")
    ,
    get_texture_info("custom_titlecard_H.rgba16")
    ,
    get_texture_info("custom_titlecard_B.rgba16")
    ,
    get_texture_info("custom_titlecard_L.rgba16")
    ,
    get_texture_info("custom_titlecard_K.rgba16")
    ,
    get_texture_info("custom_titlecard_E.rgba16")
    ,
    get_texture_info("custom_titlecard_F.rgba16")
    ,
    get_texture_info("custom_titlecard_J.rgba16")
    ,
    get_texture_info("custom_titlecard_D.rgba16")
    ,
    get_texture_info("custom_titlecard_O.rgba16")
    ,
    get_texture_info("custom_titlecard_N.rgba16")
    ,
    get_texture_info("custom_titlecard_M.rgba16")
};

ability_images                           = {
    [0] = { --[[Default]]
        get_texture_info("custom_ability_default.rgba16")
    },
    { --[[Ability G]]
        get_texture_info("custom_ability_g.rgba16")
    },
    { --[[Ability A]]
        get_texture_info("custom_ability_a.rgba16")
    },
    { --[[Ability C]]
        get_texture_info("custom_ability_c.rgba16")
    },
    { --[[Ability I]]
        get_texture_info("custom_ability_i.rgba16")
    },
    { --[[Ability H]]
        get_texture_info("custom_ability_h.rgba16")
    },
    { --[[Ability B]]
        get_texture_info("custom_ability_b.rgba16")
    },
    { --[[Ability L]]
        get_texture_info("custom_ability_l.rgba16")
    },
    { --[[Ability K]]
        get_texture_info("custom_ability_k.rgba16")
    },
    { --[[Ability E]]
        get_texture_info("custom_ability_e.rgba16")
    },
    { --[[Ability F]]
        get_texture_info("custom_ability_f.rgba16")
    },
    { --[[Ability J]]
        get_texture_info("custom_ability_j.rgba16")
    },
    { --[[Ability D]]
        get_texture_info("custom_ability_d.rgba16")
    },
    { --[[Ability O]]
        get_texture_info("custom_ability_o.rgba16")
    },
    { --[[Ability N]]
        get_texture_info("custom_ability_n.rgba16")
    },
    { --[[Ability M]]
        get_texture_info("custom_ability_m.rgba16")
    },
    { --[[Utility 1]]
        get_texture_info("custom_ability_u1.rgba16")
    },
    { --[[Utility 2]]
        get_texture_info("custom_ability_u2.rgba16")
    },
    { --[[Utility 3]]
        get_texture_info("custom_ability_u3.rgba16")
    },
    { --[[None]]
        get_texture_info("custom_ability_default.rgba16")
    },
    { --[[Locked]]
        get_texture_info("custom_ability_locked.rgba16")
    },
    { --[[Utility 2 Used]]
        get_texture_info("custom_ability_u2_used.rgba16")
    }
};

METER_STYLE_GENERIC                      = 0
METER_STYLE_HP                           = 1
METER_STYLE_BREATH                       = 2
METER_STYLE_AKU                          = 3
METER_STYLE_PHASEWALK                    = 4
METER_STYLE_PHASEWALK_SUPERJUMP          = 5
METER_STYLE_PHASEWALK_RECHARGE           = 6
METER_STYLE_ROCKET                       = 7
METER_STYLE_CHRONOS                      = 8
METER_STYLE_DASH_BOOSTER                 = 9
METER_STYLE_AKU_RECHARGE                 = 10
METER_STYLE_COUNT                        = 11

meter_wedges_dl_table                    = {
    TEX_METER1,
    TEX_METER2,
    TEX_METER3,
    TEX_METER4,
    TEX_METER5,
    TEX_METER6,
    TEX_METER7,
    TEX_METER8,
}

meter_style_color_table                  = {
    { -- Generic
        { 255, 0,   0 }, { 255, 0, 0 }, { 255, 50, 0 }, { 255, 255, 0 },
        { 255, 255, 0 }, { 0, 255, 0 }, { 0, 255, 0 }, { 0, 200, 255 }
    },
    { -- HP
        { 255, 0,   0 }, { 255, 0, 0 }, { 255, 50, 0 }, { 255, 255, 0 },
        { 255, 255, 0 }, { 0, 255, 0 }, { 0, 255, 0 }, { 0, 200, 255 }
    },
    { -- Breath
        { 255, 0,   0 }, { 255, 0, 0 }, { 255, 50, 0 }, { 255, 255, 0 },
        { 255, 255, 0 }, { 0, 255, 0 }, { 0, 255, 0 }, { 0, 200, 255 }
    },
    { -- Aku Aku Mask
        { 255, 255, 0 }, { 255, 255, 0 }, { 255, 255, 0 }, { 255, 255, 0 },
        { 255, 255, 0 }, { 255, 255, 0 }, { 255, 255, 0 }, { 255, 255, 0 }
    },
    { -- Phasewalk
        { 0, 200, 255 }, { 0, 200, 255 }, { 0, 200, 255 }, { 0, 200, 255 },
        { 0, 200, 255 }, { 0, 200, 255 }, { 0, 200, 255 }, { 0, 200, 255 }
    },
    { -- Phasewalk (Superjump)
        { 255, 255, 0 }, { 255, 255, 0 }, { 255, 255, 0 }, { 255, 255, 0 },
        { 255, 255, 0 }, { 255, 255, 0 }, { 255, 255, 0 }, { 255, 255, 0 }
    },
    { -- Phasewalk (Recharge)
        { 0, 100, 127 }, { 0, 100, 127 }, { 0, 100, 127 }, { 0, 100, 127 },
        { 0, 100, 127 }, { 0, 100, 127 }, { 0, 100, 127 }, { 0, 100, 127 }
    },
    { -- Rocket
        { 255, 156, 0 }, { 255, 156, 0 }, { 255, 156, 0 }, { 255, 156, 0 },
        { 255, 156, 0 }, { 255, 156, 0 }, { 255, 156, 0 }, { 255, 156, 0 }
    },
    { -- Chronos
        { 240, 19,  226 }, { 208, 47, 230 }, { 176, 74, 234 }, { 144, 102, 237 },
        { 111, 130, 241 }, { 80, 158, 245 }, { 48, 185, 249 }, { 0, 200, 255 }
    },
    { -- Dash Booster
        { 255, 74,  32 }, { 255, 74, 32 }, { 255, 74, 32 }, { 255, 159, 76 },
        { 255, 159, 76 }, { 255, 255, 255 }, { 255, 255, 255 }, { 255, 255, 255 }
    },
    { -- Aku Aku Mask Recharge
        { 100, 100, 0 }, { 100, 100, 0 }, { 100, 100, 0 }, { 100, 100, 0 },
        { 100, 100, 0 }, { 100, 100, 0 }, { 100, 100, 0 }, { 100, 100, 0 }
    }
}

meter_style_icon_dl_table                = {
    TEX_HEART_METER,
    meter_breath_meter_breath_mesh,
    TEX_AKU_METER,
    meter_phase_meter_phase_mesh,
    meter_phase_meter_phase_mesh,
    meter_phase_meter_phase_mesh,
    meter_rocket_meter_rocket_mesh,
    meter_chronos_meter_chronos_mesh,
    meter_booster_meter_booster_mesh,
    TEX_AKU_METER
}


-- Variables

queued_pipe_cutscene           = false
dream_comet_enabled            = false

hub_level_current_index        = 0
hub_level_index                = -1
hub_titlecard_alpha            = 0
hub_returnback_box_alpha       = 0
ability_get_alpha              = 0
ability_get_box_alpha          = 0
hub_dma_index                  = -1
hub_star_string                = {}

sCutsceneSplineSegment         = 0
sCutsceneSplineSegmentProgress = 0

milk_drunk                     = false

ability_y_offset               = { [0] = 0, 0, 0, 0 };
ability_gravity                = { [0] = 0, 0, 0, 0 };
ability_dpad_locked            = false

fb_bowser_phase                = 0

for i = 0, (MAX_PLAYERS - 1) do
    -- PlayerSyncTable --

    gPlayerSyncTable[i].abilityId = 0

    gPlayerSyncTable[i].rotAngle = 0

    gPlayerSyncTable[i].sqwall_normalx = 0
    gPlayerSyncTable[i].sqwall_normalz = 0
    gPlayerSyncTable[i].squid_x_vel = 0.0
    gPlayerSyncTable[i].squid_y_vel = 0.0
    gPlayerSyncTable[i].squid_z_vel = 0.0
    gPlayerSyncTable[i].squid_goop_timer = 0.0

    gPlayerSyncTable[i].aku_invincibility = 0
    gPlayerSyncTable[i].aku_recharge = 300

    gPlayerSyncTable[i].numCheckpointFlag = 0
    gPlayerSyncTable[i].areaCheckpointFlag = 0
    gPlayerSyncTable[i].vecCheckpointFlagv1 = 0
    gPlayerSyncTable[i].vecCheckpointFlagv2 = 0
    gPlayerSyncTable[i].vecCheckpointFlagv3 = 0
end

local courseToLevel = {
    [COURSE_NONE] = LEVEL_NONE,
    [COURSE_BOB] = LEVEL_BOB,
    [COURSE_WF] = LEVEL_WF,
    [COURSE_JRB] = LEVEL_JRB,
    [COURSE_CCM] = LEVEL_CCM,
    [COURSE_BBH] = LEVEL_BBH,
    [COURSE_HMC] = LEVEL_HMC,
    [COURSE_LLL] = LEVEL_LLL,
    [COURSE_SSL] = LEVEL_SSL,
    [COURSE_DDD] = LEVEL_DDD,
    [COURSE_SL] = LEVEL_SL,
    [COURSE_WDW] = LEVEL_WDW,
    [COURSE_TTM] = LEVEL_TTM,
    [COURSE_THI] = LEVEL_THI,
    [COURSE_TTC] = LEVEL_TTC,
    [COURSE_RR] = LEVEL_RR,
    [COURSE_BITDW] = LEVEL_BITDW,
    [COURSE_BITFS] = LEVEL_BITFS,
    [COURSE_BITS] = LEVEL_BITS,
    [COURSE_PSS] = LEVEL_PSS,
    [COURSE_COTMC] = LEVEL_COTMC,
    [COURSE_TOTWC] = LEVEL_TOTWC,
    [COURSE_VCUTM] = LEVEL_VCUTM,
    [COURSE_WMOTR] = LEVEL_WMOTR,
    [COURSE_SA] = LEVEL_SA,
    [COURSE_CAKE_END] = LEVEL_ENDING,
}

---@param id integer
---@return integer|nil
function get_hub_level(id)
    return courseToLevel[mitm_levels[id].course]
end

---@param id integer
---@return integer
function get_hub_area(id)
    return mitm_levels[id].start_area
end

---@param id integer
---@return integer
function get_hub_return_id(id)
    return mitm_levels[id].return_id
end

---@return boolean
function dream_comet_unlocked()
    return false
end

ability_cooldown_flags = 0

function ability_is_cooling_down(ability_id)
    return (ability_cooldown_flags & (1 << ability_id)) ~= 0
end

function cool_down_ability(ability_id)
    ability_cooldown_flags = ability_cooldown_flags | (1 << ability_id)
end

function ability_ready(ability_id)
    ability_cooldown_flags = ability_cooldown_flags & ~(1 << ability_id)
end

---@return boolean
function check_if_swap_ability_allowed(m)
    local marble_floor
    local marble_floor_y = find_floor_height(m.pos.x, m.pos.y, m.pos.z)
    --[[local force_marble = (not level_in_dream_comet_mode())
                        and marble_floor
                        and (marble_floor.type == SURFACE_FORCE_MARBLE)
                        and (gMarioState.pos[2] < marble_floor_y + 120.0)
                        and ((gMarioState.action & ACT_GROUP_MASK) ~= ACT_GROUP_CUTSCENE)]]

    --[[if gWarpTransition.isActive then
        return false
    end
    if force_marble then
        return false
    end]]
    if m.action == ACT_BUBBLE_HAT_JUMP then
        return false
    end

    if isPaused then
        return false
    end
    --[[if cur_obj_nearest_object_with_behavior(bhvShockRocket) ~= nil then
        return false
    end
    if gMarioState.action == ACT_HM_FLY then
        return false
    end]]

    return true
end

function set_ability_slot(index, ability_id)
    local ability_already_on_dpad = false
    local old_index = 0
    for i = 0, 3 do
        if ability_slot[i] == ability_id then
            ability_already_on_dpad = true
            old_index = i
        end
    end

    if ability_already_on_dpad then
        -- swap
        ability_slot[old_index] = ability_slot[index]

        ability_slot[index] = ability_id
    else
        -- replace
        ability_slot[index] = menuScroll2wayX
    end

    save_file_set_ability_dpad()
end

function using_ability(gMarioState, ability_id)
    return (gPlayerSyncTable[gMarioState.playerIndex].abilityId == ability_id);
end

function change_ability(picked_ability)
    if (picked_ability == ABILITY_NONE) then return end;

    -- Set Mario's Ability Variable
    gPlayerSyncTable[0].abilityId = picked_ability;
    local gMarioState = gMarioStates[0]

    -- Hand Display List
    --gSPDisplayList(&gfx_ability_hand[0], ability_struct[gPlayerSyncTable[0].abilityId].hand);
    --gSPEndDisplayList(&gfx_ability_hand[1]);

    --Hat Display List
    local hat_dl_head = 0;
    if (ability_struct[gPlayerSyncTable[0].abilityId].hat ~= NULL) then
        --gSPDisplayList(&gfx_ability_hat[hat_dl_head++], ability_struct[gPlayerSyncTable[0].abilityId].hat);
    end
    if ((gNetworkPlayers[0].currLevelNum == LEVEL_F) and (gPlayerSyncTable[0].abilityId ~= ABILITY_GADGET_WATCH)) then
        --  gSPDisplayList(&gfx_ability_hat[hat_dl_head++], &hat_f_hat_mesh);
    end
    --gSPEndDisplayList(&gfx_ability_hat[hat_dl_head++]);

    --Mario Model
    gPlayerSyncTable[0].modelId = ability_struct[gPlayerSyncTable[0].abilityId].model_id
end

-- Saving
gGlobalSyncTable.coins           = 0

--levels_unlocked = 1 means first course is open

gGlobalSyncTable.levels_unlocked = 1 ---default

ability_slot                     = { [0] = ABILITY_NONE, ABILITY_NONE, ABILITY_NONE, ABILITY_NONE };
gGlobalSyncTable.abilities       = 0

function save_unlocked_levels()
    mod_storage_save_number("levels_unlocked_" .. (get_current_save_file_num() - 1), gGlobalSyncTable.levels_unlocked)
end

function load_unlocked_levels()
    gGlobalSyncTable.levels_unlocked = mod_storage_load_number("levels_unlocked_" .. (get_current_save_file_num() - 1)) or
        1
    return gGlobalSyncTable.levels_unlocked
end

function save_file_set_ability_dpad()
    local currSave = get_current_save_file_num() - 1
    mod_storage_save_number("ability_slot0" .. (currSave), ability_slot[0])
    mod_storage_save_number("ability_slot1" .. (currSave), ability_slot[1])
    mod_storage_save_number("ability_slot2" .. (currSave), ability_slot[2])
    mod_storage_save_number("ability_slot3" .. (currSave), ability_slot[3])
end

function save_file_check_ability_unlocked(ability_id)
    if not UNLOCK_ABILITIES_DEBUG then
        return gGlobalSyncTable.abilities & (1 << (ability_id - 1)) ~= 0;
    else
        return true;
    end
end

function save_file_unlock_ability(ability_id)
    gGlobalSyncTable.abilities = gGlobalSyncTable.abilities | (1 << (ability_id - 1));
end

function load_abilities()
    local currSave = get_current_save_file_num() - 1
    gGlobalSyncTable.abilities = mod_storage_load_number("abilities" .. (currSave))
end

function load_ability_slots()
    local currSave = get_current_save_file_num() - 1

    ability_slot[0] = mod_storage_load_number("ability_slot0" .. (currSave)) or ABILITY_NONE
    ability_slot[1] = mod_storage_load_number("ability_slot1" .. (currSave)) or ABILITY_NONE
    ability_slot[2] = mod_storage_load_number("ability_slot2" .. (currSave)) or ABILITY_NONE
    ability_slot[3] = mod_storage_load_number("ability_slot3" .. (currSave)) or ABILITY_NONE
end

local function load_global_coins()
    local currSave = get_current_save_file_num() - 1
    if network_is_server() then
        gGlobalSyncTable.coins = mod_storage_load_number("coins" .. (currSave))
    end
end

function save_global_coins()
    local currSave = get_current_save_file_num() - 1
    if network_is_server() then
        mod_storage_save_number("coins" .. (currSave), gGlobalSyncTable.coins)
    end
end

if network_is_server() then
    local currSave = get_current_save_file_num() - 1
    load_unlocked_levels()
    load_ability_slots()
    load_abilities()
    load_global_coins()
    if save_file_get_flags() == 0 or gGlobalSyncTable.levels_unlocked == 0 then -- has nothing
        gGlobalSyncTable.levels_unlocked = 1
        save_unlocked_levels()
        ability_slot[0] = ABILITY_NONE
        ability_slot[1] = ABILITY_NONE
        ability_slot[2] = ABILITY_NONE
        ability_slot[3] = ABILITY_NONE
        save_file_set_ability_dpad()
        gGlobalSyncTable.abilities = 0
        mod_storage_save_number("abilities" .. (currSave), gGlobalSyncTable.abilities)
        gGlobalSyncTable.coins = 0
        save_global_coins()
    end
end
