/**
 * @file PathPlanner.h
 * @brief Defines the PathPlanner interface.
 * @authur: Tianhua Zhao
 */

#ifndef PATH_PLANNER
#define PATH_PLANNER

#include <vector>

/**
 * @class PathPlanner
 *
 * @brief a planning system for a self driving car.
 */
class PathPlanner
{
public:
	virtual ~PathPlanner() = default;

	/**
	 * @brief Load the map. The self driving car navigates on this map.
	 *  The car initially only knows the start and goal position, and assumes
	 *  the map is empty.
	 */
	virtual void Load(const std::vector<std::vector<char>> &map) = 0;

	/**
	 * @brief Start navigating until the car reaches the goal oris unable to reach the goal.
	 */
	virtual void Go() = 0;

	/**
	 * @brief number of searches
	 */
	virtual int GetNumOfSearches() = 0;

	/**
	 * @brief number of nodes expanded
	 */
	virtual int GetNumOfNodesExpanded() = 0;
};
#endif // !PATH_PLANNER

