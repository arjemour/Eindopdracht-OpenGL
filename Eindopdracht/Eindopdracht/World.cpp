#include "World.h"
#include <gl/freeglut.h>
#include "MapLoader.h"


World::World(std::string mapPath, Models* models) : models(models)
{
	MapLoader::loadMap(mapPath, map);
}

World::~World()
{
	map.clear();
	delete models;
	models = nullptr;
}

void World::renderWorld()
{
	float x = 0, y = 0;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			switch (map[i][j])
			{
			case 0:
				break;
			case 1:
				glPushMatrix();
				glTranslatef(x, y, 0.0f);
				models->drawCube();
				glPopMatrix();
				break;
			}
			x += 0.4f;
		}
		y += 0.4f;
		x = 0;
	}
}
