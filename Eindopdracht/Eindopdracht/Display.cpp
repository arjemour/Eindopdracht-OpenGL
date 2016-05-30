#include <GL/freeglut.h>
#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>
#include "Display.h"
#include "Map.h"
#include "Display2.h"

Display::Display(int argc, char* argv[])
{
	width = 800;
	height = 600;

	map = new Map("resources/maps/map.txt");
	initFreeGlut(argc, argv);
}

void initFreeGlut(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutInit(&argc, argv);
	glutCreateWindow("Hello World");
	memset(keys, 0, sizeof(keys));
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glutTimerFunc(16, timerFunc, 1);
	glutDisplayFunc(render);
	glutReshapeFunc([](int w, int h) { width = w; height = h; glViewport(0, 0, w, h); });
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);

	glutWarpPointer(width / 2, height / 2);
	glutMainLoop();
}

void timerFunc(int time)
{
	float frameTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	float deltaTime = frameTime - lastFrameTime;
	lastFrameTime = frameTime;

	const float speed = 3;
	if (keys['a']) move(0, deltaTime*speed);
	if (keys['d']) move(180, deltaTime*speed);
	/*	if (keys['w']) move(90, deltaTime*speed);
	if (keys['s']) move(270, deltaTime*speed);*/

	glutPostRedisplay();
	glutTimerFunc(16, timerFunc, 1);
}

void render()
{
	glClearColor(0.6f, 0.6f, 1, 1);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0f, (float)width / height, 0.1, 30);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(camera.rotX, 1, 0, 0);
	glRotatef(camera.rotZ, 0, 1, 0);
	glTranslatef(camera.posX, -1.5, camera.posZ);

	float pos[4] = { 0.5, 1, -1, 0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pos);

	map->draw();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int, int)
{
	switch (key)
	{
	case 27:
		exit(0);
	}
	keys[key] = true;
}

void keyboardUp(unsigned char key, int, int)
{
	keys[key] = false;
}

void move(float angle, float fac)
{
	camera.posX += (float)cos((camera.rotZ + angle) / 180 * M_PI) * fac;
	camera.posZ += (float)sin((camera.rotZ + angle) / 180 * M_PI) * fac;
}


