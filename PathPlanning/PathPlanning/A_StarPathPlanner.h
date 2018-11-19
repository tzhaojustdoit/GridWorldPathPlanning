#pragma once
#include "PathPlanner.h"
class AStarPathPlanner : public PathPlanner
{
public:
	AStarPathPlanner();
	~AStarPathPlanner();
	void load_map()
};

