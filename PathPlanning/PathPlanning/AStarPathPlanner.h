/**
 * @file PathPlanner.h
 * @brief Defines the AStarPathPlanner class.
 * @authur: Tianhua Zhao
 */

#ifndef A_STAR_PATH_PLANNER
#define A_STAR_PATH_PLANNER

#include "PathPlanner.h"
#include "PriorityQueue.h"
#include "Point2D.h"
#include <stdexcept>
#include <iostream>
#include <string>
class AStarPathPlanner : public PathPlanner
{
public:
	AStarPathPlanner() = default;
	~AStarPathPlanner();

	void Load(const std::vector<std::vector<char>> &map) override;
	void Go() override;
	int GetNumOfSearches() override;
	int GetNumOfNodesExpanded() override;

private:
	Point2D current_location_;
	Point2D goal_location_;
	std::vector<std::vector<char>> actual_world_;
	std::vector<std::vector<Node>> observed_world_;
	int num_of_searches_ = 0;
	int num_of_expanded_nodes_ = 0;
	Point2D GetStartLocation() const;
	Point2D GetGoalLocation() const;
	void SenseAdjacentCells();
	void ObserveLocation(int x, int y);
	std::vector<Node*> Plan();
	void Expand(int x, int y, PriorityQueue &open, std::vector<Node*> &closed);
	void Generate(int x, int y, Node* parent, PriorityQueue &open, std::vector<Node*> &closed);
	void PrintNavigationMap(const std::vector<Node*> &path_points);
};
#endif // !A_STAR_PATH_PLANNER



