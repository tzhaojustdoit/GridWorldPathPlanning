#ifndef PLANNING_MODULE_
#define PLANNING_MODULE_

#include <vector>

class PlanningModule {
public:
	PlanningModule() {};
	virtual ~PlanningModule() {};
	virtual void SetGoal(int) = 0;
	virtual std::vector<int> FindPath(const std::vector<bool> &map, int location) = 0;
	virtual int GetNumOfSearches() = 0;
	virtual int GetNumOfNodesExpanded() = 0;
};
#endif // !PLANNING_MODULE_

