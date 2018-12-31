#ifndef ADAPTIVE_ASTAR_PLANNING_MODULE_
#define ADAPTIVE_ASTAR_PLANNING_MODULE_
#include "PlanningModule.h"
#include <vector>
class AdaptiveAStarPlanningModule : public PlanningModule
{
public:
	AdaptiveAStarPlanningModule();
	~AdaptiveAStarPlanningModule();
	std::vector<int> GetPath(const std::vector<int> &map, int row, int col, int start, int goal) override;

private:
};
#endif // !ADAPTIVE_ASTAR_PLANNING_MODULE_



