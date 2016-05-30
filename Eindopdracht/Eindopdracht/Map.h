#pragma once
#include <string>
#include <vector>
#include "Cube.h"

class Map
{
public:
	std::vector<std::vector<int>> map;

	Map(const std::string& filepath);
	~Map();

	void draw();

private:
	Cube* cube;

	void drawMapCube();
};

