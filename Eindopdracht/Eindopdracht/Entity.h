#pragma once
#include "Models.h"

struct Location
{
	float x, y, z;
	Location() { x = y = z = 0; };
};

class Entity
{
public:
	Entity(float x, float y, float z);
	virtual ~Entity() = 0;

	virtual void update() = 0;
	virtual void draw(Models* model) = 0;

	Location& updateLocation() { return location; };

protected:
	Location location;
};

