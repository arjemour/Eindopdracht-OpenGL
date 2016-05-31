#include "Player.h"
#include <GL/freeglut.h>
#include "Models.h"


Player::Player(float x, float y, float z): Entity(x, y, z) 
{
}


Player::~Player()
{
}

void Player::update()
{
}

void Player::draw(Models* model)
{
	glPushMatrix();
	glTranslatef(location.x, location.y, location.z);
	model->drawCube();
	glPopMatrix();
}
