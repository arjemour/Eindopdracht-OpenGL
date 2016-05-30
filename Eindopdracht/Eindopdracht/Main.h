#pragma once
#include "Cube.h"

struct Camera
{
	float posX = 0;
	float posZ = -2;
	float rotX = 0;
	float rotZ = 0;
} camera;

int width, height;
float lastFrameTime = 0;

bool justMoved = false;
bool keys[255];

Map* map;