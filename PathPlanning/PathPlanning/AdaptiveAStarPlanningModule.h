#ifndef ADAPTIVE_ASTAR_PLANNING_MODULE_
#define ADAPTIVE_ASTAR_PLANNING_MODULE_

#include "PlanningModule.h"
#include "Node.h"
#include "PriorityQueue.h"
#include <vector>
#include <iostream>

class AdaptiveAStarPlanningModule : public PlanningModule
{
public:
	AdaptiveAStarPlanningModule(int rows, int cols);
	~AdaptiveAStarPlanningModule();
	void SetGoal(int goal) override;
	std::vector<int> FindPath(const std::vector<bool> &obsacles, int location) override;

private:
	int rows_;
	int cols_;
	int goal_location_;
	std::vector<Node> graph_;
	int num_of_searches_;
	int GetHeuristic(int a, int b);
};
#endif // !ADAPTIVE_ASTAR_PLANNING_MODULE_



