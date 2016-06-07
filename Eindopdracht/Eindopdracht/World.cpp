#include "World.h"
#include <gl/freeglut.h>
#include "MapLoader.h"
#include "Player.h"


World::World(std::string mapPath, Models* models) : models(models)
{
	MapLoader::loadMap(mapPath, map);
	player = new Player(2, 2, 0, world);
	setupBox2D();
}

void World::setupBox2D()
{
	b2Vec2 gravity(0.0f, -9.81);
	world = new b2World(gravity);
}

World::~World()
{
	map.clear();
	delete models;
	delete world;
}

void World::updateWorld()
{
	player->getLocation().x = player->getBody()->GetPosition().x;
	player->getLocation().y = player->getBody()->GetPosition().y;
	world->Step(1.0f / 60.0f, 6, 2);
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
	player->draw(models);
	//for (int i = 0; i < entities.size(); i++) entities[i]->draw(models);
}


