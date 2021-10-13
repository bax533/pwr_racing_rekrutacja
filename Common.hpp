#pragma once

#include <vector>
#include <map>

enum Path
{
	RED = 0,
	GREEN = 1,
	BLUE = 2
};

class Common
{
public:
	static float lengths[3];
	const static int nVertices;
	const static int nHangars;
	const static int inf;

	static void setLengths(float RED_L, float GREEN_L, float BLUE_L);

	static std::vector<std::vector<int> > graph;
	static std::map<std::pair<int, int>, float> lengths_between;

	static std::vector<std::pair<int, int> > red_paths, green_paths, blue_paths;

	static std::map<char, int> hangarMap;
};
