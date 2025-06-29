void scroll_hmc_dl_Room_1_mesh_layer_7_vtx_1() {
	int i = 0;
	int count = 14;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Room_1_mesh_layer_7_vtx_1);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_hmc_dl_Room_1_mesh_layer_7_vtx_2() {
	int i = 0;
	int count = 167;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Room_1_mesh_layer_7_vtx_2);

	deltaY = (int)(-0.25 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_hmc_dl_Room_1_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 14;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Room_1_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.25 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_hmc_dl_Room_1_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 179;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Room_1_mesh_layer_5_vtx_1);

	deltaY = (int)(3.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_hmc_dl_Ocean_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 49;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Ocean_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.25 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_hmc_dl_Ocean_mesh_layer_7_vtx_0() {
	int i = 0;
	int count = 48;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Ocean_mesh_layer_7_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_hmc_dl_watertemple_collision_mesh_layer_7_vtx_0() {
	int i = 0;
	int count = 8;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_watertemple_collision_mesh_layer_7_vtx_0);

	deltaY = (int)(-0.25 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gfx_mat_hmc_dl_water_2_layer7() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_water_2_layer7);


	shift_t_down(mat, 14, PACK_TILESIZE(0, 1));
	shift_s(mat, 16, PACK_TILESIZE(0, 1));
	shift_t(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_hmc_dl_waterfall_layer5() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_waterfall_layer5);

	shift_t(mat, 19, PACK_TILESIZE(0, 4));

};

void scroll_hmc() {
	scroll_hmc_dl_Room_1_mesh_layer_7_vtx_1();
	scroll_hmc_dl_Room_1_mesh_layer_7_vtx_2();
	scroll_hmc_dl_Room_1_mesh_layer_5_vtx_0();
	scroll_hmc_dl_Room_1_mesh_layer_5_vtx_1();
	scroll_hmc_dl_Ocean_mesh_layer_5_vtx_0();
	scroll_hmc_dl_Ocean_mesh_layer_7_vtx_0();
	scroll_hmc_dl_watertemple_collision_mesh_layer_7_vtx_0();
	scroll_gfx_mat_hmc_dl_water_2_layer7();
	scroll_gfx_mat_hmc_dl_waterfall_layer5();
};
