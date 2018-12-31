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
/**
 * @class AutomomousNavigator
 *
 * @brief an autonomous navigating system
 */
class AutomomousNavigator
{
public:
	AutomomousNavigator(MockPerceptionModule percepter, PlanningModule planner);
	~AutomomousNavigator();

	/**
	 * @brief Load the map. The self driving car navigates on this map.
	 *  The car initially only knows the start and goal position, and assumes
	 *  the map is empty.
	 * @assumption Input map has one and only one start location and one and only one goal location.
	 */
	void Init();

	/**
	 * @brief Start navigating until the car reaches the goal.
	 */
	void Navigate();

	/**
	 * @brief number of searches by the planning module
	 */
	int GetNumOfSearches();

	/**
	 * @brief number of nodes expanded by the planning module
	 */
	virtual int GetNumOfNodesExpanded();
};
#endif // !AUTONOMOUS_NAVIGATOR_

