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
	PathPlanner();
	virtual ~PathPlanner();
	virtual void load_grid_world(std::vector<std::vector<int>> map);
	virtual void go();
	virtual int get_num_of_searches();
	virtual int get_num_of_explored_nodes();
protected:
	Point2D get_start_pos() const;
	Point2D get_goal_pos() const;
	std::vector<std::vector<int>> input_matrix_;
	std::vector<std::vector<int>> observed_matrix_;
	std::vector<std::vector<int>> node_status_matrix_;
	std::vector<std::vector<Node*>> node_pointer_matrix_;
	Point2D start_;
	Point2D goal_;
	PriorityQueue pq_;
	void generate(int, int, Node *);
	void construct_matrices(std::vector<std::vector<int>>);
};

