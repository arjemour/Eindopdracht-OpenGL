#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(float x, float y, float z, b2World* world);
	~Player();
	
	void update();
	void draw(Models* model);
};

