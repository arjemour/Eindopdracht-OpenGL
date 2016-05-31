#include "World.h"
#include <gl/freeglut.h>
#include "MapLoader.h"
#include "Player.h"


World::World(std::string mapPath, Models* models) : models(models)
{
	MapLoader::loadMap(mapPath, map);
	entities.push_back(new Player(2, 2, 0));

	b2Vec2 gravity(0.0f, -9.81);
	world = new b2World(gravity);
	
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(entities[0]->getLocation().x, entities[0]->getLocation().x);
	bodyDef.fixedRotation = true;
	bodyDef.angle = 0;
	body = world->CreateBody(&bodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(0.1f, 0.1f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &boxShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	m_fixture = body->CreateFixture(&fixtureDef);
}

World::~World()
{
	map.clear();
	delete models;
	delete world;
	models = nullptr;
	world = nullptr;
}

void World::updateWorld()
{
	entities[0]->getLocation().x = body->GetPosition().x;
	entities[0]->getLocation().y = body->GetPosition().y;
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
	for (int i = 0; i < entities.size(); i++) entities[i]->draw(models);
}


