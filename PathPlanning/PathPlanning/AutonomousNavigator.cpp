#include "AutonomousNavigator.h"

AutomomousNavigator::AutomomousNavigator(MockPerceptionModule & percepttion_unit, PlanningModule & planning_unit) : perception_unit_(percepttion_unit), planning_unit_(planning_unit)
{
}

AutomomousNavigator::~AutomomousNavigator()
{
}

void AutomomousNavigator::SetDestination(int goal)
{
	goal_location_ = goal;
	planning_unit_.SetGoal(goal);
	num_of_searches_ = 0;
	num_of_expanded_nodes_ = 0;

	//initial planning
	current_location_ = perception_unit_.Localize();
	path_ = planning_unit_.FindPath(obstacles_, current_location_);
}

void AutomomousNavigator::Navigate()
{
	// navigate, replan, repeat
}

int AutomomousNavigator::GetNumOfSearches()
{
	return num_of_searches_;
}

int AutomomousNavigator::GetNumOfNodesExpanded()
{
	return num_of_expanded_nodes_;
}
