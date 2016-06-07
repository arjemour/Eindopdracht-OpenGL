#pragma once
#include "Models.h"
#include <Box2D/Box2D.h>

struct Location
{
	float x, y, z;

	Location() { x = y = z = 0; };

	void setXY(float xPos, float yPos)
	{
		x = xPos;
		y = yPos;
	}
};

class Entity
{
public:
	Entity(float x, float y, float z);
	virtual ~Entity() = 0;

	virtual void update() = 0;
	virtual void draw(Models* model) = 0;

	Location& getLocation() { return location; };
	b2BodyDef* getBodyDef() { return bodyDef; };
	b2Body* getBody() { return  body; }

protected:
	Location location;
	b2BodyDef* bodyDef = nullptr;
	b2Body* body = nullptr;
	b2Fixture* m_fixture = nullptr;
};

