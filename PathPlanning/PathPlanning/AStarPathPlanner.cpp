#include "AStarPathPlanner.h"


AStarPathPlanner::~AStarPathPlanner()
{
}

// assumption: input map has one and only one start location and one and only one goal location.
void AStarPathPlanner::Load(const std::vector<std::vector<char>> &map)
{
	// copy the map
	actual_world_ = map;
	// num of rows
	unsigned row = map.size();
	// num of columns
	unsigned col = map[0].size();
	// intialize the currently observed world
	observed_world_.reserve(row);
	for (unsigned i = 0; i < col; i++)
	{
		std::vector<CellType> row_vec(col, UNEXPLORED);
		observed_world_.push_back(row_vec);
	}
}

void AStarPathPlanner::Go()
{
	// get the start location
	current_location_ = GetStartLocation();
	// mark the start location as empty in the observed world map
	observed_world_[current_location_.x][current_location_.y] = EMPTY;
	// sense adjacent cells
	SenseAdjacentCells();
	// get the goal location
	goal_location_ = GetGoalLocation();

	while (!(current_location_ == goal_location_))
	{
		// plan using the currently observed world map
		std::stack<Point2D> path_points = Plan();
		// if path is not found, break out of the loop
		if (path_points.empty()) {
			break;
		}
		// move the car along the shortest path until it is blocked by an obstacle or reaches the goal
		while (!path_points.empty())
		{
			// sense adjacent cells
			SenseAdjacentCells();
			// get location of the next cell
			Point2D next = path_points.top();
			int x = current_location_.x;
			int y = current_location_.y;
			// if next cell is blocked, break out of the loop
			if (observed_world_[x][y] == BLOCKED)
			{
				break;
			}
			// move to the next cell
			current_location_ = path_points.top();
			path_points.pop();
		}
	}
	// print number of nodes expanded
}



int AStarPathPlanner::GetNumOfSearches()
{
	return num_of_searches_;
}

int AStarPathPlanner::GetNumOfNodesExpanded()
{
	return num_of_explored_nodes_;
}

Point2D AStarPathPlanner::GetStartLocation() const
{
	for (unsigned i = 0; i < actual_world_.size(); i++)
	{
		for (unsigned j = 0; j < actual_world_[0].size(); j++)
		{
			if (actual_world_[i][j] == 's') {
				return Point2D{ (int)i, (int)j };
			}
		}
	}
	return Point2D{ -1, -1 };
}

Point2D AStarPathPlanner::GetGoalLocation() const
{
	for (unsigned i = 0; i < actual_world_.size(); i++)
	{
		for (unsigned j = 0; j < actual_world_[0].size(); j++)
		{
			if (actual_world_[i][j] == 'g') {
				return Point2D{ (int)i, (int)j };
			}
		}
	}
	return Point2D{ -1, -1 };
}

void AStarPathPlanner::SenseAdjacentCells()
{
	int x = current_location_.x;
	int y = current_location_.y;
	// observe 4 adjacent cells
	ObserveLocation(x + 1, y);
	ObserveLocation(x, y + 1);
	ObserveLocation(x - 1, y);
	ObserveLocation(x, y - 1);
}

void AStarPathPlanner::ObserveLocation(int x, int y)
{
	try {
		char observed = actual_world_.at(x).at(y);
		switch (observed)
		{
		case 'x':
			observed_world_[x][y] = BLOCKED;
			break;
		default:
			observed_world_[x][y] = EMPTY;
			break;
		}
	}
	catch (const std::out_of_range&) {
	}
}

std::stack<Point2D> AStarPathPlanner::Plan()
{
	num_of_searches_++;
	return std::stack<Point2D>();
}


