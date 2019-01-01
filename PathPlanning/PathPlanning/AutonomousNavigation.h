/**
 * @file AutonomousNavigation.h
 * @brief Defines the AutonomousNavigation class.
 * @authur: Tianhua Zhao
 */

#ifndef AUTONOMOUS_NAVIGATION_
#define AUTONOMOUS_NAVIGATION_

#include <vector>

#include "MockPerception.h"
#include "Planning.h"
#include "Display.h"
/**
 * @class AutonomousNavigation
 *
 * @brief an autonomous navigating system
 */
class AutonomousNavigation
{
public:
	AutonomousNavigation(int rows, int cols, MockPerception* percepttion_unit, Planning* planning_unit);
	~AutonomousNavigation();



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
	void Initialize();
	MockPerception *perception_unit_;
	Planning *planning_unit_;
	int rows_;
	int cols_;
	std::vector<int> path_;
	std::vector<bool> obstacles_;
	int current_location_;
	int goal_location_;

	bool Navigate();
};
#endif // !AUTONOMOUS_NAVIGATION_

