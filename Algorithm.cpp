#include "Algorithm.hpp"

void Algorithm::input()
{
	float r, g, b;
	scanf("%f %f %f", &r, &g, &b);
	Common::setLengths(r, g, b);

	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		char h;
		scanf(" %c", &h);
		this->path.push_back(Common::hangarMap[h]);
	}
}

void Algorithm::prepare()
{
	for(unsigned int i=0; i<Common::red_paths.size(); i++)
	{
		Common::lengths_between[Common::red_paths[i]] = Common::lengths[RED];
	}

	for(unsigned int i=0; i<Common::green_paths.size(); i++)
	{
		Common::lengths_between[Common::green_paths[i]] = Common::lengths[GREEN];
	}

	for(unsigned int i=0; i<Common::blue_paths.size(); i++)
	{
		Common::lengths_between[Common::blue_paths[i]] = Common::lengths[BLUE];
	}
}

void Algorithm::init()
{
	this->input();
	this->prepare();

	if(this->path.size() < 2)
	{
		printf("0\n");
		return;
	}
}

void Algorithm::run()
{
	for(int i=0; i<Common::nHangars; i++)
	{
		dijkstra(i);
	}
	
	float distSum = 0.f;
	for(unsigned int i=1; i<this->path.size(); i++)
	{
		distSum += dist[path[i-1]][path[i]];
	}

	printf("%f\n", distSum);
}


void Algorithm::dijkstra(int source)
{
	int hangar = source;
	this->dist[hangar][source] = 0.f;

	std::priority_queue<std::pair<float, int>, std::vector<std::pair<float, int> >, std::greater<std::pair<float, int> > > Q;

	for(int v = 0; v<Common::nVertices; v++)
	{
		if(v != source)
			dist[hangar][v] = Common::inf;
	}

	Q.push({0.f, source});
	while(!Q.empty())
	{
		std::pair<float, int> top = Q.top();
		Q.pop();

		float curDist = top.first;
		int curV = top.second;

		for(unsigned int i=0; i<Common::graph[curV].size(); i++)
		{
			int neighV = Common::graph[curV][i];
			float alt = curDist + Common::lengths_between[{curV, neighV}];
			if(alt < dist[hangar][neighV])
			{
				dist[hangar][neighV] = alt;
				Q.push({alt, neighV});
			}
		}
	}
}
