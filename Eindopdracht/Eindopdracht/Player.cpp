#include "Player.h"
#include <GL/freeglut.h>
#include "Models.h"
#include <Box2D/Box2D.h>

Player::Player(float x, float y, float z, b2World* world): Entity(x, y, z) 
{
	bodyDef = new b2BodyDef;
	bodyDef->type = b2_dynamicBody;
	bodyDef->position.Set(location.x, location.x);
	bodyDef->fixedRotation = true;
	bodyDef->angle = 0;

	b2Body* body = world->CreateBody(bodyDef);
	b2PolygonShape* boxShape = new b2PolygonShape;
	boxShape->SetAsBox(0.1f, 0.1f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = boxShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	m_fixture = body->CreateFixture(&fixtureDef);
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
