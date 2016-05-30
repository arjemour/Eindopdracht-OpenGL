#pragma once
#include "Vertex.h"
#include <vector>

class Cube
{
public:
	Cube();
	~Cube();
	
	void drawCube();

private:
	std::vector<Vertex> cubeVertices;
};

