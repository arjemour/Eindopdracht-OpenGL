#include "Cube.h"
#include <gl/freeglut.h>


Cube::Cube()
{
	cubeVertices.push_back(Vertex{ -0.2f, -0.2f, -0.2f, 0,0,0.2f, 0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ -0.2f,  0.2f, -0.2f, 0,0,0.2f, 0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ 0.2f,  0.2f, -0.2f, 0,0,0.2f, 0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ 0.2f, -0.2f, -0.2f, 0,0,0.2f, 0.2f,0.2f,0.2f,0.2f });

	cubeVertices.push_back(Vertex{ -0.2f, -0.2f,  0.2f, 0,0,-0.2f, 0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ -0.2f,  0.2f,  0.2f, 0,0,-0.2f, 0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ 0.2f,  0.2f,  0.2f, 0,0,-0.2f, 0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ 0.2f, -0.2f,  0.2f, 0,0,-0.2f, 0.2f,0.2f,0.2f,0.2f });

	cubeVertices.push_back(Vertex{ -0.2f,  -0.2f, -0.2f,		0,-0.2f,0,		0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ -0.2f,  -0.2f,  0.2f,		0,-0.2f,0,		0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ 0.2f,  -0.2f,  0.2f,		0,-0.2f,0,		0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ 0.2f,  -0.2f, -0.2f,		0,-0.2f,0,		0.2f,0.2f,0.2f,0.2f });

	cubeVertices.push_back(Vertex{ -0.2f,  0.2f, -0.2f,		0,0.2f,0,		0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ -0.2f,  0.2f,  0.2f,		0,0.2f,0,		0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ 0.2f,  0.2f,  0.2f,		0,0.2f,0,		0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ 0.2f,  0.2f, -0.2f,		0,0.2f,0,		0.2f,0.2f,0.2f,0.2f });

	cubeVertices.push_back(Vertex{ -0.2f, -0.2f, -0.2f,		-0.2f,0,0,		0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ -0.2f, -0.2f,  0.2f,		-0.2f,0,0,		0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ -0.2f,  0.2f,  0.2f,		-0.2f,0,0,		0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ -0.2f,  0.2f, -0.2f,		-0.2f,0,0,		0.2f,0.2f,0.2f,0.2f });

	cubeVertices.push_back(Vertex{ 0.2f, -0.2f, -0.2f,		0.2f,0,0,		0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ 0.2f, -0.2f,  0.2f,		0.2f,0,0,		0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ 0.2f,  0.2f,  0.2f,		0.2f,0,0,		0.2f,0.2f,0.2f,0.2f });
	cubeVertices.push_back(Vertex{ 0.2f,  0.2f, -0.2f,		0.2f,0,0,		0.2f,0.2f,0.2f,0.2f });
}


Cube::~Cube()
{
}

void Cube::drawCube()
{
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), ((float*)cubeVertices.data()) + 0);
	glNormalPointer(GL_FLOAT, sizeof(Vertex), ((float*)cubeVertices.data()) + 3);
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), ((float*)cubeVertices.data()) + 6);
	glDrawArrays(GL_QUADS, 0, cubeVertices.size());

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
}
