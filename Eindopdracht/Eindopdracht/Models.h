#pragma once
#include "Cube.h"

class Models
{
public:
	Models();
	~Models();

	void drawCube();

private:
	Cube* cube;
};

