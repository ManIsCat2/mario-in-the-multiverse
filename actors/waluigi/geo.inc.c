#include "geo_header.h"
// Normal Mario Geo

// 0x170002E0
const GeoLayout waluigi_geo_face_and_wings[] = {
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
            GEO_DISPLAY_LIST(LAYER_ALPHA, waluigi_r_logo_decal),
            GEO_DISPLAY_LIST(LAYER_ALPHA, waluigi_hair_sideburn_decal_cap_on),
		    GEO_OPEN_NODE(),
               GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
               GEO_OPEN_NODE(),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_on_eyes_front),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_on_eyes_half_closed),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_on_eyes_closed),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_on_eyes_right), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_on_eyes_left), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_on_eyes_up), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_on_eyes_down), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_on_eyes_dead),
               GEO_CLOSE_NODE(),
		    GEO_CLOSE_NODE(),
		 GEO_CLOSE_NODE(),
         GEO_NODE_START(),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, waluigi_hair_sideburn_decal_cap_off),
		    GEO_OPEN_NODE(),
               GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
               GEO_OPEN_NODE(),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_off_eyes_front),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_off_eyes_half_closed),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_off_eyes_closed),
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_off_eyes_right), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_off_eyes_left), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_off_eyes_up), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_off_eyes_down), // unused
                  GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_cap_off_eyes_dead),
               GEO_CLOSE_NODE(),
		    GEO_CLOSE_NODE(),
		 GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 123, -44, -106, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, waluigi_cap_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 123, -44, 106, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, waluigi_cap_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x1700041C
const GeoLayout waluigi_geo_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_left_hand_open),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17000494
const GeoLayout waluigi_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
          GEO_ASM(0, geo_override_handscale),
         GEO_OPEN_NODE(),
         GEO_ASM(0, geo_ability_hand),
            GEO_DISPLAY_LIST(4, waluigi_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_right_hand_cap),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, waluigi_right_hand_cap_decal),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_right_hand_cap),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, waluigi_right_hand_cap_decal),
         GEO_DISPLAY_LIST(LAYER_ALPHA, waluigi_right_hand_cap_wings),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// The body loads all the parts with some shared dls to apply the solid color of the dl that has it, the same rule applies to the medium and low poly geos

// 0x1700053C
const GeoLayout waluigi_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 32768),
      GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, waluigi_butt), // starts sharing solid color with mario_torso (blue)
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 88, 0, 0, waluigi_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 120, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, waluigi_geo_face_and_wings), // stops sharing because faces has its own dl
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 111, -10, 59, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, waluigi_left_arm), // starts sharing solid color with mario_left_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 140, 0, 0, waluigi_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, waluigi_geo_left_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 112, -10, -59, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, waluigi_right_arm), // starts sharing solid color of his dl with mario_right_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 140, 0, 0, waluigi_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, waluigi_geo_right_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, 13, -8, 36, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, waluigi_left_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 175, 0, 0, waluigi_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 175, 0, 0, waluigi_left_foot), // stops sharing because foot has its solid color (brown)
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, 13, -8, -36, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, waluigi_right_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 175, 0, 0, waluigi_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 175, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_right_foot), // stops sharing because foot has its solid color (brown)
                     GEO_CLOSE_NODE(),
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

// 0x17000DEC
const GeoLayout waluigi_vanish_geo_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_NODE_START(),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_r_logo_decal),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_hair_sideburn_decal_cap_on),
		    GEO_OPEN_NODE(),
               GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
               GEO_OPEN_NODE(),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_on_eyes_front),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_on_eyes_half_closed),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_on_eyes_closed),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_on_eyes_right), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_on_eyes_left), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_on_eyes_up), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_on_eyes_down), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_on_eyes_dead),
               GEO_CLOSE_NODE(),
		    GEO_CLOSE_NODE(),
		 GEO_CLOSE_NODE(),
         GEO_NODE_START(),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_hair_sideburn_decal_cap_off),
		    GEO_OPEN_NODE(),
               GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
               GEO_OPEN_NODE(),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_off_eyes_front),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_off_eyes_half_closed),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_off_eyes_closed),
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_off_eyes_right), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_off_eyes_left), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_off_eyes_up), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_off_eyes_down), // unused
                  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_off_eyes_dead),
               GEO_CLOSE_NODE(),
		    GEO_CLOSE_NODE(),
		 GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 123, -44, -106, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_wings_transparent),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 123, -44, 106, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_cap_wings_transparent),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17000F28
const GeoLayout waluigi_vanish_geo_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_left_hand_open),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17000FA0
const GeoLayout waluigi_vanish_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_right_hand_cap),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_right_hand_cap_decal),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_right_hand_cap),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_right_hand_cap_decal),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_right_hand_cap_wings_transparent),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Same rule body as Normal Mario

// 0x17001048
const GeoLayout waluigi_vanish_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 32768),
      GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, waluigi_butt),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 88, 0, 0, waluigi_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 120, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, waluigi_vanish_geo_face_and_wings),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 111, -10, 59, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, waluigi_left_arm),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_TRANSPARENT, 140, 0, 0, waluigi_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, waluigi_vanish_geo_left_hand),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 112, -10, -59, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, waluigi_right_arm),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_TRANSPARENT, 140, 0, 0, waluigi_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, waluigi_vanish_geo_right_hand),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_TRANSPARENT, 13, -8, 36, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, waluigi_left_thigh),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 175, 0, 0, waluigi_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 175, 0, 0, waluigi_left_foot),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_TRANSPARENT, 13, -8, -42, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, waluigi_right_thigh),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 175, 0, 0, waluigi_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 175, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_right_foot),
                     GEO_CLOSE_NODE(),
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

// 0x170018F8
const GeoLayout waluigi_metal_geo_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_metal_cap_on_shared_dl),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_metal_cap_off_shared_dl),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 123, -44, -106, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, waluigi_metal_cap_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 123, -44, 106, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, waluigi_metal_cap_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x170019A4
const GeoLayout waluigi_metal_geo_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_left_hand_closed_shared_dl),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_left_hand_open_shared_dl),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_left_hand_closed_shared_dl),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_left_hand_closed_shared_dl),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_left_hand_closed_shared_dl),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17001A1C
const GeoLayout waluigi_metal_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_metal_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_metal_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_right_hand_peace_shared_dl), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_metal_right_hand_cap_shared_dl),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, waluigi_metal_right_hand_cap_shared_dl),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, waluigi_metal_right_hand_cap_shared_dl_wings),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// A difference from Normal Mario is that the dls after the butt and left thigh shares the metal texture of it, same rule applies to the medium and low poly geos

// 0x17001AC4
const GeoLayout waluigi_metal_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 32768),
      GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, waluigi_metal_butt), // starts sharing metal texture with the dls below
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 88, 0, 0, waluigi_metal_torso_shared_dl),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 120, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, waluigi_metal_geo_face_and_wings), // unlike normal mario geo, these dls still share the metal texture
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 111, -10, 59, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, waluigi_left_arm_shared_dl),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 140, 0, 0, waluigi_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, waluigi_metal_geo_left_hand),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 112, -10, -59, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, waluigi_right_arm_shared_dl),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 140, 0, 0, waluigi_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, waluigi_metal_geo_right_hand), // stop sharing because the wing metal cap of it
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, 13, -8, 36, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, waluigi_metal_left_thigh), // starts sharing metal texture with the dls below
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 175, 0, 0, waluigi_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 175, 0, 0, waluigi_left_foot_shared_dl),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, 13, -8, -42, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, waluigi_right_thigh_shared_dl),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 175, 0, 0, waluigi_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 175, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_metal_right_foot),
                     GEO_CLOSE_NODE(),
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

// 0x170022E4
const GeoLayout waluigi_metal_vanish_geo_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_metal_cap_on_shared_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_metal_cap_off_shared_dl),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 123, -44, -106, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_metal_cap_wings_transparent),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 123, -44, 106, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_metal_cap_wings_transparent),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002390
const GeoLayout waluigi_metal_vanish_geo_left_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_left_hand_closed_shared_dl),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_left_hand_open_shared_dl),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_left_hand_closed_shared_dl),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_left_hand_closed_shared_dl),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_left_hand_closed_shared_dl),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002408
const GeoLayout waluigi_metal_vanish_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_metal_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_metal_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_right_hand_peace_shared_dl), // here we go hand
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_metal_right_hand_cap_shared_dl),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 114, 0, 0, waluigi_metal_right_hand_cap_shared_dl),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_metal_right_hand_cap_shared_dl_wings_transparent),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Same rules as Metal Mario

// 0x170024B0
const GeoLayout waluigi_metal_vanish_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 32768),
      GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, waluigi_metal_butt),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ASM(0, geo_mario_tilt_torso),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 88, 0, 0, waluigi_metal_torso_shared_dl),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 120, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, waluigi_metal_vanish_geo_face_and_wings),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 111, -10, 59, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, waluigi_left_arm_shared_dl),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_TRANSPARENT, 140, 0, 0, waluigi_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, waluigi_metal_vanish_geo_left_hand),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 112, -10, -59, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, waluigi_right_arm_shared_dl),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_TRANSPARENT, 140, 0, 0, waluigi_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, waluigi_metal_vanish_geo_right_hand),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_TRANSPARENT, 13, -8, 36, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, waluigi_metal_left_thigh),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 175, 0, 0, waluigi_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 175, 0, 0, waluigi_left_foot_shared_dl),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_TRANSPARENT, 13, -8, -42, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, waluigi_right_thigh_shared_dl),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 175, 0, 0, waluigi_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 175, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_metal_right_foot),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002CE0
const GeoLayout waluigi_geo_load_body[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_cap_effect),
   GEO_OPEN_NODE(),
      GEO_BRANCH(1, waluigi_geo_body),
      GEO_BRANCH(1, waluigi_vanish_geo_body),
      GEO_BRANCH(1, waluigi_metal_geo_body),
      GEO_BRANCH(1, waluigi_metal_vanish_geo_body),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// This last geo is used to load all of Mario Geo in the Level Scripts

// 0x17002DD4
const GeoLayout waluigi_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_SHADOW(SHADOW_CIRCLE_PLAYER, 0xB4, 100),
         GEO_OPEN_NODE(),
            GEO_SCALE(0x00, 32768),
            GEO_OPEN_NODE(),
               GEO_ASM(LAYER_OPAQUE + 3, geo_mario_set_player_colors),
               GEO_ASM(LAYER_ALPHA + 3, geo_mario_set_player_colors),
               GEO_ASM(LAYER_TRANSPARENT + 3, geo_mario_set_player_colors),
               GEO_ASM(LAYER_OPAQUE << 2, geo_mirror_mario_backface_culling),
               GEO_ASM(LAYER_ALPHA << 2, geo_mirror_mario_backface_culling),
               GEO_ASM(LAYER_TRANSPARENT << 2, geo_mirror_mario_backface_culling),
               GEO_ASM(0, geo_mirror_mario_set_alpha),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, waluigi_geo_load_body),
               GEO_CLOSE_NODE(),
               GEO_ASM((LAYER_OPAQUE << 2) | 1, geo_mirror_mario_backface_culling),
               GEO_ASM((LAYER_ALPHA << 2) | 1, geo_mirror_mario_backface_culling),
               GEO_ASM((LAYER_TRANSPARENT << 2) | 1, geo_mirror_mario_backface_culling),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, waluigi_material_revert_render_settings),
         GEO_DISPLAY_LIST(LAYER_ALPHA, waluigi_material_revert_render_settings),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, waluigi_material_revert_render_settings),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
