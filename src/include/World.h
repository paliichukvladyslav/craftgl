#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Mesh.h"

class World {
public:
	std::vector<Mesh*> meshes;

	World();
	~World();

	void update();
};
#endif
