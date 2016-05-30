#pragma once
#include "Models.h"
#include "World.h"

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

Models* models;
World* world;

void render();
void move(float angle, float fac);
void timerFunc(int time);
void keyboard(unsigned char key, int, int);
void keyboardUp(unsigned char key, int, int);
void initFreeGlut(int argc, char* argv[]);
