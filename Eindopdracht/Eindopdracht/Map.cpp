#include "Map.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <GL/freeglut.h>

void Map::drawMapCube()
{
	cube->drawCube();
}

Map::Map(const std::string& filepath)
{
	cube = new Cube;

	int y = 0;
	std::string line, value;
	std::ifstream file;
	file.open(filepath);
	while(!file.eof())
	{
		std::vector<int> column;
		map.push_back(column);
		getline(file, line);
		std::istringstream temp(line);
		while (getline(temp, value, ','))
		{
			map[y].push_back(atoi(value.c_str()));
		}
		y++;
	}
	file.close();
	reverse(map.begin(), map.end());
}

Map::~Map()
{
	free(cube);
	cube = nullptr;
}

void Map::draw()
{
	float x = 0, y = 0;
/*	for (int i = 0; i < map.size(); i++)
	{
		std::cout << "" << std::endl;
		for (int j = 0; j < map[i].size(); j++)
			std::cout << map[i][j];
	}*/

	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			switch(map[i][j])
			{
			case 0:
				break;
			case 1:
				glPushMatrix();
				glTranslatef(x, y, 0.0f);
				drawMapCube();
				glPopMatrix();
				break;
			}
			x += 0.4f;
		}
		y+=0.4f;
		x = 0;
	}
}


