#include "src/game/envfx_snow.h"

const GeoLayout wf_area_7_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1822, 0, 1985, 0, -180, 0, wf_dl_chair_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1071, 0, 1689, 0, -180, 0, wf_dl_chair_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1216, 0, 1141, 0, -180, 0, wf_dl_chair_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1602, 0, 472, 0, -180, 0, wf_dl_chair_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1703, 0, -551, 0, -180, 0, wf_dl_chair_004_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1002, 0, -127, 0, -180, 0, wf_dl_chair_005_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 2867, 0, -1227, 0, -90, 0, wf_dl_door_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 4474, 622, -141, 0, -180, -90, wf_dl_order_station_mesh_layer_5),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_order_station_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_order_station_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_ASM(0, e__shotgun_effects),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -51556, -2494, 26809, 0, 90, 0),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1415, 206, 1589, 0, -180, 0, wf_dl_table_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1665, 206, 780, 0, 90, 0, wf_dl_table_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1344, 206, -622, 0, -180, 0, wf_dl_table_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 2886, 1539, -1253, -90, 0, -180, wf_dl_thing_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 4530, 1722, 653, -90, 0, 90, wf_dl_thing2_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1370, 1644, -1253, -90, 0, -180, wf_dl_vent_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 4199, 0, 1262, 0, 90, 0, wf_dl_vent_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 2612, 0, 653, 0, -180, 0, wf_dl_walls_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_area_7[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x0001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, -32977, 0, -100, -32977, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, wf_area_7_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
