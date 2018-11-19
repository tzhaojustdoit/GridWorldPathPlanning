#include "PathPlanner.h"




PathPlanner::PathPlanner(std::vector<std::vector<char>> map)
{
	input_map_ = map;
	int row = input_map_.size();
	int col = input_map_[0].size();
	for (int i = 0; i < row; i++)
	{
		std::vector<int> status_row_vec( (unsigned)col, 0 );
		std::vector<Node*> pointer_row_vec( (unsigned)col,nullptr );
		node_status_matrix_.push_back(status_row_vec);
		node_pointer_matrix_.push_back(pointer_row_vec);
	}
}

PathPlanner::~PathPlanner()
{
}

Point2D PathPlanner::get_start_pos() const
{
	int row = input_map_.size();
	int col = input_map_[0].size();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (input_map_[row][col] == 's') {
				return Point2D{ i,j };
			}
		}
	}
	throw std::invalid_argument("start position not found.");
}

Point2D PathPlanner::get_goal_pos() const
{
	int row = input_map_.size();
	int col = input_map_[0].size();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (input_map_[row][col] == 'g') {
				return Point2D{ i,j };
			}
		}
	}
	throw std::invalid_argument("goal position not found.");
}

void PathPlanner::a_star_search()
{
	//// start location
	//Point2D start = get_start_pos();
	//// goal location
	//Point2D goal = get_goal_pos();
	//// h value of start location
	//int h = start.get_manhattan_distance(goal);
	//// create start node
	//Node start_node(0, h, nullptr, start.x, start.y);
	//// add the start node to priority queue
	//pq_.push(start_node);

	//// a* search
	//while (!pq_.empty()) {
	//	Node cur = pq_.pop();
	//}
}

