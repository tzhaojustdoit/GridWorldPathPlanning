#include "AStarPathPlanner.h"

// assumption: input map has one and only one start location and one and only one goal location.
void AStarPathPlanner::Load(const std::vector<std::vector<char>> &map)
{
	// copy the map
	actual_world_ = map;
	// num of rows
	unsigned row = map.size();
	// num of columns
	unsigned col = map[0].size();
	// intialize the currently observed map, all nodes are marked as unexplored initially.
	observed_world_.reserve(row);
	for (unsigned i = 0; i < row; i++)
	{
		std::vector<Node> row_vec;
		row_vec.reserve(col);
		for (unsigned j = 0; j < col; j++)
		{
			row_vec.emplace_back(i, j);
		}
		observed_world_.push_back(row_vec);
	}
	// set the current location
	current_location_ = GetStartLocation();
	// set the goal location
	goal_location_ = GetGoalLocation();
}

void AStarPathPlanner::Go()
{
	// get the current node;
	Node & current_node = observed_world_[current_location_.x][current_location_.y];
	// sense adjacent cells, update observed map
	SenseAdjacentCells();
	while (!(current_location_ == goal_location_))
	{
		// plan using the currently observed map
		std::vector<Node*> path_points = Plan();
		// if path is not found, break out of the loop
		if (path_points.empty()) {
			std::cout << "No route found." << std::endl;
			break;
		}
		else {
			std::cout << "Moving along the path above..." << std::endl;
		}
		// move the car from the start cell to the next cell
		// since start cell is already sensed, it is safe to move one step
		current_location_ = path_points.back()->get_location();
		// move the car along the shortest path until it is blocked by an obstacle or reaches the goal
		int cur = path_points.size() - 1;
		while (cur > 0)
		{
			// sense adjacent cells
			SenseAdjacentCells();
			// get the next path point
			Point2D next = path_points[cur - 1]->get_location();
			int x = next.x;
			int y = next.y;
			// if next cell is blocked, break out of the loop
			if (actual_world_[x][y] == 'x')
			{
				std::cout << "Obstacle detected, start replanning..." << std::endl;
				break;
			}
			// move to the next cell
			current_location_ = next;
			cur--;
		}
	}
	// print number of nodes expanded
	std::cout << "Navigation ended." << std::endl << "Total number of nodes expanded is: " << num_of_expanded_nodes_ << "." << std::endl;
}



int AStarPathPlanner::GetNumOfSearches()
{
	return num_of_searches_;
}

int AStarPathPlanner::GetNumOfNodesExpanded()
{
	return num_of_expanded_nodes_;
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
	// observe 4 adjacent cells in this order: right, down, left, up
	ObserveLocation(x, y + 1);
	ObserveLocation(x + 1, y);
	ObserveLocation(x, y - 1);
	ObserveLocation(x - 1, y);
}

void AStarPathPlanner::ObserveLocation(int x, int y)
{
	try {
		char observed = actual_world_.at(x).at(y);
		switch (observed)
		{
		case 'x':
			observed_world_[x][y].set_blocked();
			break;
		default:
			break;
		}
	}
	catch (const std::out_of_range&) {
	}
}

std::vector<Node*> AStarPathPlanner::Plan()
{
	num_of_searches_++;
	std::cout << "Planning (" << num_of_searches_ << ")..." << std::endl;
	// open list, contains generated nodes
	PriorityQueue open;
	// closed list, contains expanded nodes
	std::vector<Node*> closed;
	// path points from the current location(exclusive) to the goal location(exclusive)
	std::vector<Node*> path_points;

	Node* current_node = &observed_world_[current_location_.x][current_location_.y];
	// set g value
	current_node->set_g(0);
	// set h value
	int h = current_location_.get_manhattan_distance(goal_location_);
	current_node->set_h(h);
	// set parent pointer
	current_node->set_parent(nullptr);
	// add to the open list
	open.push(current_node);
	while (!open.empty())
	{
		// get the node with the min f value
		current_node = open.top();
		// get the current location
		Point2D location = current_node->get_location();
		// if goal has been reached
		if (location == goal_location_) {
			// reset type for each node in open and closed list
			for (Node* var : closed)
			{
				var->set_type(DEFAULT);
			}
			open.reset_type();
			// make path points 
			while (current_node->get_parent() != nullptr)
			{
				path_points.push_back(current_node);
				current_node = current_node->get_parent();
			}

			break;
		}
		// remove from the open list
		open.pop();
		// add the node to the closed list
		closed.push_back(current_node);
		current_node->set_type(CLOSED);
		// expand the node
		Expand(location.x, location.y, open, closed);
	}
	// print the navigation map
	PrintNavigationMap(path_points);
	return path_points;
}

void AStarPathPlanner::Expand(int x, int y, PriorityQueue &open, std::vector<Node*> &closed)
{
	num_of_expanded_nodes_++;
	Node* current_node = &observed_world_[x][y];
	// generate 4 adjacent nodes
	Generate(x - 1, y, current_node, open, closed);
	Generate(x, y - 1, current_node, open, closed);
	Generate(x + 1, y, current_node, open, closed);
	Generate(x, y + 1, current_node, open, closed);
}

void AStarPathPlanner::Generate(int x, int y, Node* parent, PriorityQueue &open, std::vector<Node*> &closed)
{
	try {
		Node& current_node = observed_world_.at(x).at(y);
		if (!current_node.is_blocked()) {
			if (current_node.get_type() == DEFAULT) {
				Point2D location{ x,y };
				int g = parent->get_g() + 1;
				current_node.set_g(g);
				if (current_node.get_h() == 0) {
					int h = location.get_manhattan_distance(goal_location_);
					current_node.set_h(h);
				}
				current_node.set_parent(parent);
				open.push(&current_node);
				current_node.set_type(OPEN);
			}
			else if (current_node.get_type() == OPEN) {
				int g = parent->get_g() + 1;
				current_node.set_g(g);
				current_node.set_parent(parent);
			}
		}
	}
	catch (const std::out_of_range&) {
	}
}

void AStarPathPlanner::PrintNavigationMap(const std::vector<Node*> &path_points)
{
	std::vector<std::string> rows;
	rows.reserve(observed_world_.size());
	for (std::vector<Node> var : observed_world_)
	{
		std::string row;
		for (Node n : var) {
			if (n.is_blocked()) {
				row += "x ";
			}
			else {
				row += "_ ";
			}
		}
		rows.push_back(row);
	}
	// set path points to 'o'
	for (unsigned i = 1; i < path_points.size(); i++)
	{
		int x = path_points[i]->get_x();
		int y = path_points[i]->get_y();
		rows[x].replace(y * 2, 1, 1, 'o');
	}

	// set start to 's'
	int start_x = current_location_.x;
	int start_y = current_location_.y;
	rows[start_x].replace(start_y * 2, 1, 1, 's');
	// set goal to 'g'
	int goal_x = goal_location_.x;
	int goal_y = goal_location_.y;
	rows[goal_x].replace(goal_y * 2, 1, 1, 'g');

	// print
	for (std::string str : rows) {
		std::cout << str << std::endl;
	}

}

