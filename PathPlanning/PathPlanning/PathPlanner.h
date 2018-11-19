#pragma once
#include <vector>
#include <string>
#include "PriorityQueue.h"
#include <stdexcept>
#include <cmath>
#include <unordered_map>
#include "Point2D.h"
class PathPlanner
{
public:
	// ctor
	// takes an input 2d matrix of chars
	PathPlanner(std::vector<std::vector<char>>);
	~PathPlanner();
	void a_star_search();

private:
	PriorityQueue pq_;
	std::vector<std::vector<char>> input_map_;
	std::vector<std::vector<int>> node_status_matrix_;
	std::vector<std::vector<Node*>> node_pointer_matrix_;
	Point2D get_start_pos() const;
	Point2D get_goal_pos() const;
};

