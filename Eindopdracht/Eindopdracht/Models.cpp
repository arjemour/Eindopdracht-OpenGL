#include "Models.h"

Models::Models()
{
	cube = new Cube;
}


Models::~Models()
{
	delete cube;
	cube = nullptr;
}

void Models::drawCube()
{
	cube->drawCube();
}
