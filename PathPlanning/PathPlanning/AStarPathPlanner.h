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
#include "CellType.h"
#include <stack>
#include <stdexcept>

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
	std::vector<std::vector<CellType>> observed_world_;
	PriorityQueue open_;
	std::vector<Node*> closed_;
	int num_of_searches_ = 0;
	int num_of_explored_nodes_ = 0;
	Point2D GetStartLocation() const;
	Point2D GetGoalLocation() const;
	void SenseAdjacentCells();
	void ObserveLocation(int x, int y);
	std::stack<Point2D> Plan();
};
#endif // !A_STAR_PATH_PLANNER


