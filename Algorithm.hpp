#include <stdio.h>
#include <vector>
#include <string>
#include <queue>

#include "Common.hpp"

class Algorithm
{
private:
	std::vector<int> path;
	
	float dist[5][20];

	void input();
	void prepare();

	void dbg();

	void dijkstra(int source);

public:

	void init();
	void run();
};
