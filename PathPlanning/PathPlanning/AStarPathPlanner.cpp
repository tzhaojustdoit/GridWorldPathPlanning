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
		std::vector<Node> row_vec;
		row_vec.reserve(col);
		for (unsigned j = 0; j < col; j++)
		{
			row_vec.emplace_back(i, j);
		}
		observed_world_.push_back(row_vec);
	}
}

void AStarPathPlanner::Go()
{
	// get the start location
	current_location_ = GetStartLocation();
	// get the goal location
	goal_location_ = GetGoalLocation();
	// get the cell;
	Node & my_node = observed_world_[current_location_.x][current_location_.y];
	// mark the start location as empty in the observed world map
	my_node.set_type(EMPTY);
	// sense adjacent cells
	SenseAdjacentCells();

	while (!(current_location_ == goal_location_))
	{
		// plan using the currently observed world map
		std::stack<Point2D> path_points = Plan();
		// if path is not found, break out of the loop
		if (path_points.empty()) {
			break;
		}
		current_location_ = path_points.top();
		path_points.pop();
		// move the car along the shortest path until it is blocked by an obstacle or reaches the goal
		while (!path_points.empty())
		{
			// sense adjacent cells
			SenseAdjacentCells();
			// get location of the next cell
			Point2D next = path_points.top();
			int x = next.x;
			int y = next.y;
			// if next cell is blocked, break out of the loop
			if (actual_world_[x][y] == 'x')
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
	PriorityQueue open;
	std::vector<Node*> closed;
	std::stack<Point2D> path_points;
	num_of_searches_++;
	Node* nptr = &observed_world_[current_location_.x][current_location_.y];
	nptr->set_g(0);
	// set h value
	int h = current_location_.get_manhattan_distance(goal_location_);
	nptr->set_h(h);
	nptr->set_parent(nullptr);
	open.push(nptr);
	while (!open.empty())
	{
		// move the top of the open list to the closed list
		nptr = open.top();
		open.pop();
		closed.push_back(nptr);
		Point2D location{ nptr->get_x(), nptr->get_y() };
		if (location == goal_location_) {
			Point2D curr;
			while (nptr->get_parent() != nullptr)
			{
				curr.x = nptr->get_x();
				curr.y = nptr->get_y();
				path_points.push(curr);
				nptr = nptr->get_parent();
			}
			break;
		}
		// expand the node
		Expand(location.x, location.y, open, closed);
	}
	return path_points;
}

void AStarPathPlanner::Expand(int x, int y, PriorityQueue &open, std::vector<Node*> &closed)
{
	num_of_expanded_nodes_++;
	Node* my_node = &observed_world_[x][y];
	// generate 4 adjacent nodes
	Generate(x - 1, y, my_node, open, closed);
	Generate(x, y - 1, my_node, open, closed);
	Generate(x + 1, y, my_node, open, closed);
	Generate(x, y + 1, my_node, open, closed);
}

void AStarPathPlanner::Generate(int x, int y, Node* parent, PriorityQueue &open, std::vector<Node*> &closed)
{
	try {
		Node& my_node = observed_world_.at(x).at(y);
		if (my_node.get_type() != BLOCKED) {
			bool closedcontains = (std::find(closed.begin(), closed.end(), &my_node) != closed.end());
			if (!open.contains(&my_node) && !closedcontains) {
				Point2D location{ x,y };
				int h = location.get_manhattan_distance(goal_location_);
				my_node.set_h(h);
				int g = parent->get_g() + 1;
				my_node.set_g(g);
				my_node.set_parent(parent);
				open.push(&my_node);
			}
			else if (open.contains(&my_node)) {
				int g = parent->get_g() + 1;
				my_node.set_g(g);
				my_node.set_parent(parent);
			}
		}
	}
	catch (const std::out_of_range&) {
	}
}


