#include "src/game/envfx_snow.h"

const GeoLayout sky_bob_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_FORCE, Custom_Skybox_Icosphere_Bone_mesh_layer_0),
		GEO_DISPLAY_LIST(LAYER_FORCE, Custom_Skybox_Icosphere_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
