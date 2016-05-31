#include "Player.h"
#include <GL/freeglut.h>
#include "Models.h"
#include <Box2D/Box2D.h>


Player::Player(float x, float y, float z): Entity(x, y, z) 
{
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(location.x, location.x);
	bodyDef.fixedRotation = true;
	bodyDef.angle = 0;
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
