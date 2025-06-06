#include "geo_header.h"
// Normal Mario Geo

const GeoLayout wario_geo_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
   GEO_OPEN_NODE(),
         GEO_ASM(0, geo_ability_hat),
         GEO_DISPLAY_LIST(4, GFXEMPTY),
      GEO_CLOSE_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_NODE_START(),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, wario_w_logo_decal),
            GEO_DISPLAY_LIST(LAYER_ALPHA, wario_hair_sideburn_decal_cap_on),
		    GEO_OPEN_NODE(),
               GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
               GEO_OPEN_NODE(),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_on_eyes_front),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_on_eyes_half_closed),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_on_eyes_closed),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_on_eyes_right), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_on_eyes_left), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_on_eyes_up), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_on_eyes_down), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_on_eyes_dead),
               GEO_CLOSE_NODE(),
		    GEO_CLOSE_NODE(),
		 GEO_CLOSE_NODE(),
         GEO_NODE_START(),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, wario_hair_sideburn_decal_cap_off),
		    GEO_OPEN_NODE(),
               GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
               GEO_OPEN_NODE(),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_off_eyes_front),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_off_eyes_half_closed),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_off_eyes_closed),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_off_eyes_right), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_off_eyes_left), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_off_eyes_up), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_off_eyes_down), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_cap_off_eyes_dead),
               GEO_CLOSE_NODE(),
		    GEO_CLOSE_NODE(),
		 GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 158, -62, -146, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, wario_cap_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 158, -62, 146, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, wario_cap_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

const GeoLayout wario_geo_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

const GeoLayout wario_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_ASM(0, geo_override_handscale),
         GEO_OPEN_NODE(),
            GEO_ASM(0, geo_ability_hand),
            GEO_DISPLAY_LIST(4, wario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_right_hand_cap),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, wario_right_hand_cap_decal),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_right_hand_cap),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, wario_right_hand_cap_decal),
         GEO_DISPLAY_LIST(LAYER_ALPHA, wario_right_hand_cap_wings),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// The body loads all the parts with some shared dls to apply the solid color of the dl that has it, the same rule applies to the medium and low poly geos

const GeoLayout wario_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, wario_butt), // starts sharing solid color with mario_torso (blue)
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 61, 0, 0, wario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 128, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, wario_geo_face_and_wings), // stops sharing because faces has its own dl
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 104, -10, 115, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, wario_left_arm), // starts sharing solid color with mario_left_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 101, 0, 0, wario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, wario_geo_left_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 105, -10, -116, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, wario_right_arm), // starts sharing solid color of his dl with mario_right_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 101, 0, 0, wario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, wario_geo_right_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -50, -8, 80, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, wario_left_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 52, 0, 0, wario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 45, 0, 0, wario_left_foot), // stops sharing because foot has its solid color (brown)
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -50, -8, -80, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, wario_right_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 52, 0, 0, wario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 45, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_right_foot), // stops sharing because foot has its solid color (brown)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Vanish Mario Geo

const GeoLayout wario_vanish_geo_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_NODE_START(),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_w_logo_decal),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_hair_sideburn_decal_cap_on),
		    GEO_OPEN_NODE(),
               GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
               GEO_OPEN_NODE(),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_on_eyes_front),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_on_eyes_half_closed),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_on_eyes_closed),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_on_eyes_right), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_on_eyes_left), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_on_eyes_up), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_on_eyes_down), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_on_eyes_dead),
               GEO_CLOSE_NODE(),
		    GEO_CLOSE_NODE(),
		 GEO_CLOSE_NODE(),
         GEO_NODE_START(),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_hair_sideburn_decal_cap_off),
		    GEO_OPEN_NODE(),
               GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
               GEO_OPEN_NODE(),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_off_eyes_front),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_off_eyes_half_closed),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_off_eyes_closed),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_off_eyes_right), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_off_eyes_left), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_off_eyes_up), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_off_eyes_down), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_off_eyes_dead),
               GEO_CLOSE_NODE(),
		    GEO_CLOSE_NODE(),
		 GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 158, -62, -146, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_wings_transparent),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 158, -62, 146, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_cap_wings_transparent),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

const GeoLayout wario_vanish_geo_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17000FA0
const GeoLayout wario_vanish_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_right_hand_cap),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_right_hand_cap_decal),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_right_hand_cap),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_right_hand_cap_wings_transparent),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_right_hand_cap_decal),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Same rule body as Normal Mario

const GeoLayout wario_vanish_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, wario_butt),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 61, 0, 0, wario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 128, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, wario_vanish_geo_face_and_wings),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 104, -10, 115, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, wario_left_arm),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_TRANSPARENT, 101, 0, 0, wario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, wario_vanish_geo_left_hand),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 105, -10, -116, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, wario_right_arm),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_TRANSPARENT, 101, 0, 0, wario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, wario_vanish_geo_right_hand),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_TRANSPARENT, -50, -8, 80, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, wario_left_thigh),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 52, 0, 0, wario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 45, 0, 0, wario_left_foot),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_TRANSPARENT, -50, -8, -80, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, wario_right_thigh),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 52, 0, 0, wario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 45, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_right_foot),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Metal Mario Geo

const GeoLayout wario_metal_geo_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_metal_cap_on_shared_dl),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_metal_cap_off_shared_dl),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 158, -62, -146, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, wario_metal_cap_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 158, -62, 146, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, wario_metal_cap_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

const GeoLayout wario_metal_geo_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_left_hand_closed_shared_dl),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_left_hand_open_shared_dl),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_left_hand_closed_shared_dl),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_left_hand_closed_shared_dl),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_left_hand_closed_shared_dl),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

const GeoLayout wario_metal_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_metal_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_metal_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_right_hand_peace_shared_dl), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_metal_right_hand_cap_shared_dl),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 82, 0, 0, wario_metal_right_hand_cap_shared_dl),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, wario_metal_right_hand_cap_shared_dl_wings),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// A difference from Normal Mario is that the dls after the butt and left thigh shares the metal texture of it, same rule applies to the medium and low poly geos

const GeoLayout wario_metal_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, wario_metal_butt), // starts sharing metal texture with the dls below
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 61, 0, 0, wario_metal_torso_shared_dl),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 128, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, wario_metal_geo_face_and_wings), // unlike normal mario geo, these dls still share the metal texture
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 104, -10, 115, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, wario_left_arm_shared_dl),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 101, 0, 0, wario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, wario_metal_geo_left_hand),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 105, -10, -116, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, wario_right_arm_shared_dl),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 101, 0, 0, wario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, wario_metal_geo_right_hand), // stop sharing because the wing metal cap of it
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -50, -8, 80, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, wario_metal_left_thigh), // starts sharing metal texture with the dls below
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 52, 0, 0, wario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 45, 0, 0, wario_left_foot_shared_dl),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -50, -8, -80, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, wario_right_thigh_shared_dl),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 52, 0, 0, wario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 45, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_metal_right_foot),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Metal Vanish Mario Geo

const GeoLayout wario_metal_vanish_geo_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_metal_cap_on_shared_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_metal_cap_off_shared_dl),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 158, -62, -146, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_metal_cap_wings_transparent),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 158, -62, 146, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_metal_cap_wings_transparent),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

const GeoLayout wario_metal_vanish_geo_left_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_left_hand_closed_shared_dl),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_left_hand_open_shared_dl),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_left_hand_closed_shared_dl),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_left_hand_closed_shared_dl),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_left_hand_closed_shared_dl),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

const GeoLayout wario_metal_vanish_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_metal_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_metal_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_right_hand_peace_shared_dl), // here we go hand
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_metal_right_hand_cap_shared_dl),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 82, 0, 0, wario_metal_right_hand_cap_shared_dl),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_metal_right_hand_cap_shared_dl_wings_transparent),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Same rules as Metal Mario

const GeoLayout wario_metal_vanish_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, wario_metal_butt),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 61, 0, 0, wario_metal_torso_shared_dl),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 128, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, wario_metal_vanish_geo_face_and_wings),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 104, -10, 115, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, wario_left_arm_shared_dl),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_TRANSPARENT, 101, 0, 0, wario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, wario_metal_vanish_geo_left_hand),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 105, -10, -116, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, wario_right_arm_shared_dl),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_TRANSPARENT, 101, 0, 0, wario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, wario_metal_vanish_geo_right_hand),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_TRANSPARENT, -50, -8, 80, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, wario_metal_left_thigh),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 52, 0, 0, wario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 45, 0, 0, wario_left_foot_shared_dl),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_TRANSPARENT, -50, -8, -80, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, wario_right_thigh_shared_dl),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 52, 0, 0, wario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 45, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_metal_right_foot),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// High Poly

const GeoLayout wario_geo_load_body[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_cap_effect),
   GEO_OPEN_NODE(),
      GEO_BRANCH(1, wario_geo_body),
      GEO_BRANCH(1, wario_vanish_geo_body),
      GEO_BRANCH(1, wario_metal_geo_body),
      GEO_BRANCH(1, wario_metal_vanish_geo_body),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// This last geo is used to load all of Mario Geo in the Level Scripts

const GeoLayout wario_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SHADOW(SHADOW_CIRCLE_PLAYER, 0xB4, 100),
         GEO_OPEN_NODE(),
            GEO_SCALE(0x00, 16384),
            GEO_OPEN_NODE(),
               GEO_ASM(LAYER_OPAQUE + 3, geo_mario_set_player_colors),
               GEO_ASM(LAYER_ALPHA + 3, geo_mario_set_player_colors),
               GEO_ASM(LAYER_TRANSPARENT + 3, geo_mario_set_player_colors),
               GEO_ASM(LAYER_OPAQUE << 2, geo_mirror_mario_backface_culling),
               GEO_ASM(LAYER_ALPHA << 2, geo_mirror_mario_backface_culling),
               GEO_ASM(LAYER_TRANSPARENT << 2, geo_mirror_mario_backface_culling),
               GEO_ASM(0, geo_mirror_mario_set_alpha),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, wario_geo_load_body),
               GEO_CLOSE_NODE(),
               GEO_ASM((LAYER_OPAQUE << 2) | 1, geo_mirror_mario_backface_culling),
               GEO_ASM((LAYER_ALPHA << 2) | 1, geo_mirror_mario_backface_culling),
               GEO_ASM((LAYER_TRANSPARENT << 2) | 1, geo_mirror_mario_backface_culling),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, wario_material_revert_render_settings),
         GEO_DISPLAY_LIST(LAYER_ALPHA, wario_material_revert_render_settings),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wario_material_revert_render_settings),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
