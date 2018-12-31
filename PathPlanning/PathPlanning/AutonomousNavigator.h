/**
 * @file AutomomousNavigator.h
 * @brief Defines the AutomomousNavigator class.
 * @authur: Tianhua Zhao
 */

#ifndef AUTONOMOUS_NAVIGATOR_
#define AUTONOMOUS_NAVIGATOR_

#include <vector>

#include "MockPerceptionModule.h"
#include "PlanningModule.h"
#include "Display.h"
/**
 * @class AutomomousNavigator
 *
 * @brief an autonomous navigating system
 */
class AutomomousNavigator
{
public:
	AutomomousNavigator(int rows, int cols, MockPerceptionModule & percepttion_unit, PlanningModule & planning_unit);
	~AutomomousNavigator();

	void Initialize();

	/**
	 * @brief Load the map. The self driving car navigates on this map.
	 *  The car initially only knows the start and goal position, and assumes
	 *  the map is empty.
	 * @assumption Input map has one and only one start location and one and only one goal location.
	 */
	void SetDestination(int goal);

	/**
	 * @brief Start navigating until the car reaches the goal.
	 */
	void AutoNavigate();

	/**
	 * @brief number of searches by the planning module
	 */
	int GetNumOfSearches();

	/**
	 * @brief number of nodes expanded by the planning module
	 */
	int GetNumOfNodesExpanded();

private:
	MockPerceptionModule &perception_unit_;
	PlanningModule &planning_unit_;
	int rows_;
	int cols_;
	std::vector<int> path_;
	std::vector<bool> obstacles_;
	int current_location_;
	int goal_location_;
	int num_of_searches_ = 0;
	int num_of_expanded_nodes_ = 0;

	bool Navigate();
};
#endif // !AUTONOMOUS_NAVIGATOR_

