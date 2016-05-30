#pragma once
#include <string>
#include <vector>
#include "Cube.h"

static class MapLoader
{
public:
	static void loadMap(std::string mapPath, std::vector<std::vector<int>>& map);
};

