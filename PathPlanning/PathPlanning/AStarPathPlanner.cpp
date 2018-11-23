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
	// intialize the currently observed map, all nodes are marked as unexplored initially.
	observed_world_.reserve(row);
	for (unsigned i = 0; i < col; i++)
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
	// mark the current node as empty in the observed map
	current_node.set_type(EMPTY);
	// sense adjacent cells, update observed map
	SenseAdjacentCells();
	while (!(current_location_ == goal_location_))
	{
		// plan using the currently observed map
		std::stack<Point2D> path_points = Plan();
		// if path is not found, break out of the loop
		if (path_points.empty()) {
			std::cout << "No route found" << std::endl;
			break;
		}
		// if path is found, output the navigation map
		PrintNavigationMap(path_points);
		// move the car from the start cell to the next cell
		// since start cell is already sensed, it is safe to move one step
		current_location_ = path_points.top();
		path_points.pop();
		// move the car along the shortest path until it is blocked by an obstacle or reaches the goal
		while (!path_points.empty())
		{
			// sense adjacent cells
			SenseAdjacentCells();
			// get the next path point
			Point2D next = path_points.top();
			int x = next.x;
			int y = next.y;
			// if next cell is blocked, break out of the loop
			if (actual_world_[x][y] == 'x')
			{
				std::cout << "Obstacle detected, start replanning" << std::endl;
				break;
			}
			// move to the next cell
			current_location_ = path_points.top();
			path_points.pop();
		}
	}
	// print number of nodes expanded
	std::cout << "Total number of nodes expanded is: " << num_of_expanded_nodes_ << std::endl;
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
			observed_world_[x][y].set_type(BLOCKED);
			break;
		default:
			observed_world_[x][y].set_type(EMPTY);
			break;
		}
	}
	catch (const std::out_of_range&) {
	}
}

std::stack<Point2D> AStarPathPlanner::Plan()
{
	num_of_searches_++;
	std::cout << "Planning with A* (#" << num_of_searches_ << ")" << std::endl;
	// open list, contains generated nodes
	PriorityQueue open;
	// closed list, contains expanded nodes
	std::vector<Node*> closed;
	// path points from the current location(exclusive) to the goal location(incluseive)
	std::stack<Point2D> path_points;

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
		// move the top of the open list to the closed list
		current_node = open.top();
		open.pop();
		// get the current location
		Point2D location{ current_node->get_x(), current_node->get_y() };
		// if goal has been reached
		if (location == goal_location_) {
			// update h values for nodes in the closed list
			int g_goal = current_node->get_g();
			for (Node* var : closed)
			{
				var->set_h(g_goal - var->get_g());
			}
			// make path points, push them to the stack
			Point2D curr;
			while (current_node->get_parent() != nullptr)
			{
				curr.x = current_node->get_x();
				curr.y = current_node->get_y();
				path_points.push(curr);
				current_node = current_node->get_parent();
			}
			break;
		}
		// add the node to the closed list
		closed.push_back(current_node);
		// expand the node
		Expand(location.x, location.y, open, closed);
	}
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
		if (current_node.get_type() != BLOCKED) {
			bool closedcontains = (std::find(closed.begin(), closed.end(), &current_node) != closed.end());
			if (!open.contains(&current_node) && !closedcontains) {
				Point2D location{ x,y };
				int g = parent->get_g() + 1;
				current_node.set_g(g);
				if (current_node.get_h() == 0) {
					int h = location.get_manhattan_distance(goal_location_);
					current_node.set_h(h);
				}
				current_node.set_parent(parent);
				open.push(&current_node);
			}
			else if (open.contains(&current_node)) {
				int g = parent->get_g() + 1;
				current_node.set_g(g);
				current_node.set_parent(parent);
			}
		}
	}
	catch (const std::out_of_range&) {
	}
}

void AStarPathPlanner::PrintNavigationMap(std::stack<Point2D>& path_points)
{

}


