/**
 * @file AStarPathPlanner.h
 * @brief Defines the AStarPathPlanner class.
 * @authur: Tianhua Zhao
 */

#ifndef A_STAR_PATH_PLANNER_
#define A_STAR_PATH_PLANNER_

#include <stdexcept>
#include <iostream>
#include <string>

#include "PathPlanner.h"
#include "PriorityQueue.h"
#include "Point2D.h"

 /**
  * @class AStarPathPlanner
  *
  * @brief a planning system for a self driving car using a* algorithm.
  */
class AStarPathPlanner : public PathPlanner
{
public:
	~AStarPathPlanner() = default;

	/**
	 * @brief Load the map. The self driving car navigates on this map.
	 *  The car initially only knows the start and goal position, and assumes
	 *  the map is empty.
	 * @assumption Input map has one and only one start location and one and only one goal location.
	 */
	void Load(const std::vector<std::vector<char>> &map) override;

	/**
	 * @brief Start navigating until the car reaches the goal oris unable to reach the goal.
	 */
	void Go() override;

	/**
	 * @brief number of searches
	 */
	int GetNumOfSearches() override;

	/**
	 * @brief number of nodes expanded
	 */
	int GetNumOfNodesExpanded() override;

private:
	/**
	 * @brief current location
	 */
	Point2D current_location_;

	/**
	 * @brief goal location
	 */
	Point2D goal_location_;

	/**
	 * @brief actual world map
	 */
	std::vector<std::vector<char>> actual_world_;

	/**
	 * @brief the map that the car has explored so far
	 */
	std::vector<std::vector<Node>> observed_world_;

	/**
	 * @brief number of searches
	 */
	int num_of_searches_ = 0;

	/**
	 * @brief number of expanded nodes
	 */
	int num_of_expanded_nodes_ = 0;

	/**
	 * @return the start location
	 */
	Point2D GetStartLocation() const;

	/**
	 * @return the goal location
	 */
	Point2D GetGoalLocation() const;

	/**
	 * @brief sense the adjacent cells of the current location, determine their traversability
	 */
	void SenseAdjacentCells();

	/**
	 * @brief determine the traversability of the location
	 */
	void ObserveLocation(int x, int y);

	/**
	 * @brief plan using a* from the current location to the goal location using the observed map
	 */
	std::vector<Node*> Plan();

	/**
	 * @brief expand the node at this location
	 */
	void Expand(int x, int y, PriorityQueue &open, std::vector<Node*> &closed);

	/**
	 * @brief generate the node at this location
	 */
	void Generate(int x, int y, Node* parent, PriorityQueue &open, std::vector<Node*> &closed);

	/**
	 * @brief print the navigation map
	 */
	void PrintNavigationMap(const std::vector<Node*> &path_points);
};
#endif // A_STAR_PATH_PLANNER_



