#include "PathPlanner.h"
#include <stack>

PathPlanner::PathPlanner(std::vector<std::vector<int>> map)
{
	construct_matrices(map);
	start_ = get_start_pos();
	goal_ = get_goal_pos();
}

PathPlanner::~PathPlanner()
{
	int row = input_matrix_.size();
	int col = input_matrix_[0].size();
	for (int i = 1; i < row - 1; i++)
	{
		for (int j = 1; j < col - 1; j++)
		{
			if (node_pointer_matrix_[i][j] != nullptr) {
				delete node_pointer_matrix_[i][j];
			}
		}
	}
}

Point2D PathPlanner::get_start_pos() const
{
	int row = input_matrix_.size();
	int col = input_matrix_[0].size();
	for (int i = 1; i < row - 1; i++)
	{
		for (int j = 1; j < col - 1; j++)
		{
			if (input_matrix_[i][j] == 1) {
				return Point2D{ j,i };
			}
		}
	}
	return Point2D{ -1,-1 };
}

Point2D PathPlanner::get_goal_pos() const
{
	int row = input_matrix_.size();
	int col = input_matrix_[0].size();
	for (int i = 1; i < row -1; i++)
	{
		for (int j = 1; j < col -1; j++)
		{
			if (input_matrix_[i][j] == 2) {
				return Point2D{ j,i };
			}
		}
	}
	return Point2D{ -1,-1 };
}

std::string PathPlanner::toString()
{
	std::string res = "";
	Node* cur = node_pointer_matrix_[goal_.y][goal_.x];
	while (cur != nullptr) {
		res = std::to_string(cur->get_x()) + ", " + std::to_string(cur->get_y()) + " -> " + res;
		cur = cur->get_parent();
	}
	return res;
}

void PathPlanner::generate(int x, int y, Node* parent)
{
	int myint = input_matrix_[y][x];
	if (myint == 0 || myint == 2) {
		int status = node_status_matrix_[y][x];
		if (status == 0) {
			Point2D cur{ x, y };
			int h = cur.get_manhattan_distance(goal_);
			int g = parent->get_g() + 1;
			Node* myNode = new Node( g, h, parent, x, y );
			// push to priority queue
			pq_.push(myNode);
			// update status matrix
			node_status_matrix_[y][x] = 1;
			// update pointer matrix
			node_pointer_matrix_[y][x] = myNode;
		}
		if (status == 1) {
			Node* myNode = node_pointer_matrix_[y][x];
			myNode->set_g(parent->get_g() + 1);
		}
	}
}

void PathPlanner::construct_matrices(std::vector<std::vector<int>> map)
{
	int row = map.size();
	int col = map[0].size();

	// construct the top row
	std::vector<int> top_and_bottom_input_row_vec((unsigned)col + 2, -1);
	std::vector<int> top_and_bottom_node_status_row_vec((unsigned)col + 2, 0);
	std::vector<Node*> top_and_bottom_node_pointer_row_vec((unsigned)col + 2, nullptr);

	input_matrix_.push_back(top_and_bottom_input_row_vec);
	observed_matrix_.push_back(top_and_bottom_input_row_vec);
	node_status_matrix_.push_back(top_and_bottom_node_status_row_vec);
	node_pointer_matrix_.push_back(top_and_bottom_node_pointer_row_vec);

	// construct middle rows
	for (int i = 0; i < row; i++)
	{
		std::vector<int> input_row_vec = map[i];
		input_row_vec.push_back(-1);
		input_row_vec.push_back(-1);
		std::rotate(input_row_vec.begin(), input_row_vec.begin() + col, input_row_vec.begin() + col + 1);
		std::vector<int> observed_row_vec((unsigned)col + 2, 0);
		observed_row_vec.front() = -1;
		observed_row_vec.back() = -1;
		std::vector<int> status_row_vec((unsigned)col + 2, 0);
		std::vector<Node*> pointer_row_vec((unsigned)col + 2, nullptr);

		input_matrix_.push_back(input_row_vec);
		observed_matrix_.push_back(observed_row_vec);
		node_status_matrix_.push_back(status_row_vec);
		node_pointer_matrix_.push_back(pointer_row_vec);
	}

	// construct the bottom row
	input_matrix_.push_back(top_and_bottom_input_row_vec);
	observed_matrix_.push_back(top_and_bottom_input_row_vec);
	node_status_matrix_.push_back(top_and_bottom_node_status_row_vec);
	node_pointer_matrix_.push_back(top_and_bottom_node_pointer_row_vec);
}

void PathPlanner::a_star_go()
{
	int h = start_.get_manhattan_distance(goal_);
	// create start node
	Node* start_node = new Node(0 /*g*/, h /*h*/, nullptr/*parent pointer*/, start_.x, start_.y);
	// add the start node to priority queue
	pq_.push(start_node);
	// update pointer matrix
	node_pointer_matrix_[start_.y][start_.x] = start_node;

	while (!pq_.empty()) {
		Node* cur = pq_.pop();
		int cur_x = cur->get_x();
		int cur_y = cur->get_y();
		if (input_matrix_[cur_y][cur_x] == 2) {
			return;
		}
		// mark as expanded
		node_status_matrix_[cur_y][cur_x] = 2;
		// try to generate up neighbor
		generate(cur_x, cur_y + 1, cur);
		// try to generate right neighbor
		generate(cur_x + 1, cur_y, cur);
		// try to generate down neighbor
		generate(cur_x, cur_y - 1, cur);
		// try to generate left neighbor
		generate(cur_x - 1, cur_y, cur);
	}
}

