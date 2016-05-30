#pragma once
#include <vector>
#include "Models.h"

class World
{
public:
	World(std::string mapPath, Models* models);
	~World();

	void renderWorld();

private:
	std::vector<std::vector<int>> map;

	Models* models;
};

