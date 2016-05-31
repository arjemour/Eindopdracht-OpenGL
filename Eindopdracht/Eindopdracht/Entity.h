#pragma once
#include "Models.h"

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

protected:
	Location location;
};

