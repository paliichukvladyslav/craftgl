#ifndef MESH_FACTORY_H
#define MESH_FACTORY_H

#include "Mesh.h"

class MeshFactory {
public:
	static Mesh *create_block(float tex_top, float tex_side, float tex_bottom);
	static Mesh* create_grass_block(float tex_top, float tex_side, float tex_bottom);
};

#endif
