#pragma once
#include <vector>
#include "Models.h"
#include "Entity.h"
#include "Player.h"
#include <Box2D/Box2D.h>

class World
{
public:
	World(std::string mapPath, Models* models);
	~World();

	void updateWorld();
	void renderWorld();
	Entity* getPlayer() { return entities[0]; };

private:
	std::vector<std::vector<int>> map;
	std::vector<Entity*> entities;

	Models* models;
	b2World* world;

	Player* player;

	void setupBox2D();
};

