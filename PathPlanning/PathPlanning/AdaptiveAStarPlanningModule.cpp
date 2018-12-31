#include "AdaptiveAStarPlanningModule.h"



AdaptiveAStarPlanningModule::AdaptiveAStarPlanningModule(int rows, int cols) : rows_(rows), cols_(cols)
{
	graph_.reserve(rows * cols);
}


AdaptiveAStarPlanningModule::~AdaptiveAStarPlanningModule()
{
}

void AdaptiveAStarPlanningModule::SetGoal(int goal)
{
	goal_location_ = goal;
	// pre-compute heuristics for each node
	for (int i = 0; i < graph_.size(); i++)
	{
		int h = GetHeuristic(i, goal);
		graph_[i].SetH(h);
	}
}

std::vector<int> AdaptiveAStarPlanningModule::FindPath(const std::vector<bool>& obsacles, int location)
{
	num_of_searches_++;
	std::cout << std::endl << "[planning] id: " << num_of_searches_ <<std::endl;
	// open list, contains generated nodes
	PriorityQueue open;
	// closed list, contains expanded nodes
	std::vector<Node*> closed;

	// path points from the current location(exclusive) to the goal location(exclusive)
	std::vector<int> path;

	Node & current_node = graph_[location];
	// set g value
	current_node.SetG(0);
	// add to the open list
	std::pair<int, int> p(location, current_node.GetH());
	open.push(p);
	current_node.SetType(OPEN);
	while (!open.empty())
	{
		// get the node with the min f value.
		current_node = open.top().first;
		// get the current location
		Point2D location = current_node->get_location();
		// if goal has been reached
		if (location == goal_location_) {
			// update h values for nodes in the closed list
			int g_goal = current_node->GetG();
			for (Node* var : closed)
			{
				var->SetH(g_goal - var->GetG());
			}
			// reset type for each node in open and closed list
			for (Node* var : closed)
			{
				var->SetType(DEFAULT);
			}
			open.reSetType();
			// make path points from the current location(exclusive) to the goal location(exclusive)
			while (current_node->GetParentId() != 0)
			{
				path_points.push_back(current_node);
				current_node = current_node->GetParentId();
			}
			break;
		}
		// remove from the open list
		open.pop();
		// add the node to the closed list
		closed.push_back(current_node);
		current_node->SetType(CLOSED);
		// expand the node
		Expand(location.x, location.y, open, closed);
	}
	// print the navigation map
	PrintNavigationMap(path_points);
	return path;
}

int AdaptiveAStarPlanningModule::GetHeuristic(int a, int b)
{
	int ax = a / cols_;
	int ay = a % cols_;
	int bx = b / cols_;
	int by = b / cols_;
	// manhattan distance
	return std::abs(ax - bx) + std::abs(ay - by);
}
