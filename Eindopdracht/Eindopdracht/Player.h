#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(float x, float y, float z);
	~Player();
	
	void update();
	void draw(Models* model);
};

