/**
 * @file PathPlanner.h
 * @brief Defines the PathPlanner interface.
 * @authur: Tianhua Zhao
 */

#ifndef PATH_PLANNER
#define PATH_PLANNER

#include <vector>

class PathPlanner
{
public:
	virtual ~PathPlanner() = 0;
	virtual void LoadGridWorld(std::vector<std::vector<char>> map) = 0;
	virtual void Go() = 0;
	virtual int GetNumOfSearches() = 0;
	virtual int GetNumOfNodesExpanded() = 0;
};
#endif // !PATH_PLANNER

