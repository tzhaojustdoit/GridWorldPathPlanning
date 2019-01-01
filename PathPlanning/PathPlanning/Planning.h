#ifndef PLANNING_
#define PLANNING_

#include <vector>

class Planning {
public:
	Planning() {};
	virtual ~Planning() {};
	virtual void SetGoal(int) = 0;
	virtual std::vector<int> FindPath(const std::vector<bool> &map, int location) = 0;
	virtual int GetNumOfSearches() const = 0;
	virtual int GetNumOfNodesExpanded() const = 0;
};
#endif // !PLANNING_

