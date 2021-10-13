#include "Common.hpp"

float Common::lengths[3] = {0.f, 0.f, 0.f};
const int Common::nVertices = 15;
const int Common::nHangars = 4;
const int Common::inf = 2147483647;

std::map<char, int> Common::hangarMap = {
	{'A', 0},
	{'B', 1},
	{'C', 2},
	{'D', 3}
};

std::map<std::pair<int, int>, float> Common::lengths_between = {};

std::vector<std::vector<int> > Common::graph = {
	{4, 7},
	{8},
	{5, 12},
	{11, 14},
	{0, 5},
	{2,4,6},
	{5,7,9},
	{0,6,8,9},
	{1,7,10,11},
	{6,7,10,12,13},
	{8,9,14},
	{3,8},
	{2,9,13},
	{9,12,14},
	{3,10,13}
};

std::vector<std::pair<int, int> > Common::red_paths = {
	{4, 5},
	{5, 4},
	{2, 5},
	{5, 2},
	{7, 8},
	{8, 7},
	{9, 13},
	{13, 9},
	{13, 14},
	{14, 13},
	{3, 14},
	{14, 3},
	{3, 11},
	{11, 3}
};

std::vector<std::pair<int, int> > Common::green_paths = {
	{0, 7},
	{7, 0},
	{6, 7},
	{7, 6},
	{9, 12},
	{12, 9},
	{9, 10},
	{10, 9},
	{8, 11},
	{11, 8},
	{2, 12},
	{12, 2}
};

std::vector<std::pair<int, int> > Common::blue_paths = {
	{0, 4},
	{4, 0},
	{5, 6},
	{6, 5},
	{7, 9},
	{9, 7},
	{12, 13},
	{13, 12},
	{10, 14},
	{14, 10},
	{1, 8},
	{8, 1},
	{8, 10},
	{10, 8}
};

void Common::setLengths(float RED_L, float GREEN_L, float BLUE_L)
{
	Common::lengths[RED] = RED_L;
	Common::lengths[GREEN] = GREEN_L;
	Common::lengths[BLUE] = BLUE_L;
}
