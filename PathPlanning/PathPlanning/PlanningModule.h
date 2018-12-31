#ifndef PLANNING_MODULE_
#define PLANNING_MODULE_

#include <vector>

class PlanningModule {
public:
	PlanningModule() {};
	virtual ~PlanningModule() {};
	virtual std::vector<int> GetPath(const std::vector<int> &map, int row, int col, int start, int goal) = 0;
};
#endif // !PLANNING_MODULE_

