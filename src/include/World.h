#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Mesh.h"
#include "MeshFactory.h"

class World {
public:
	std::vector<Mesh *> meshes;

	World();
	~World();

	void update();
	bool auto_rotate;
};
#endif
