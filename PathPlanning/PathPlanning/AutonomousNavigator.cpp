#include "AutonomousNavigator.h"

AutomomousNavigator::AutomomousNavigator(int rows, int cols, MockPerceptionModule & percepttion_unit, PlanningModule & planning_unit) : rows_(rows), cols_(cols), perception_unit_(percepttion_unit), planning_unit_(planning_unit)
{
	Initialize();
}

AutomomousNavigator::~AutomomousNavigator()
{
}

void AutomomousNavigator::Initialize()
{
	obstacles_.resize(rows_ * cols_);
	current_location_ = perception_unit_.Localize();
	perception_unit_.PerceiveSurroundings(obstacles_, current_location_);
}

void AutomomousNavigator::SetDestination(int goal)
{
	goal_location_ = goal;
	planning_unit_.SetGoal(goal);
	num_of_searches_ = 0;
	num_of_expanded_nodes_ = 0;

	//initial planning
	path_ = planning_unit_.FindPath(obstacles_, current_location_);
	Display::DisplayMap(rows_, cols_, obstacles_, path_, current_location_, goal_location_);
}

void AutomomousNavigator::AutoNavigate()
{
	while (!Navigate()) {
		path_ = planning_unit_.FindPath(obstacles_, current_location_);
		if (path_.empty()) {
			std::cout << "No route found. Unable to navigate." << std::endl;
			break;
		}
		Display::DisplayMap(rows_, cols_, obstacles_, path_, current_location_, goal_location_);
	}
	// print number of nodes expanded
	std::cout << std::endl << "Auto-navigation ended." << std::endl << "Total number of nodes expanded is: " << num_of_expanded_nodes_ << "." << std::endl;
}

int AutomomousNavigator::GetNumOfSearches()
{
	return planning_unit_.GetNumOfSearches();
}

int AutomomousNavigator::GetNumOfNodesExpanded()
{
	return planning_unit_.GetNumOfNodesExpanded();
}

bool AutomomousNavigator::Navigate()
{
	std::cout << "Navigation started." << std::endl;
	// move the car from the start cell to the next cell
	// since start cell is already sensed, it is safe to move one step
	current_location_ = path_.back();
	// move the car along the shortest path until it is blocked by an obstacle or reaches the goal
	int counter = path_.size() - 1;
	while (counter > 0)
	{
		// sense adjacent cells
		perception_unit_.PerceiveSurroundings(obstacles_, current_location_);
		// get the next path point
		int next = path_[counter - 1];
		// if next cell is blocked, break out of the loop
		if (obstacles_[next])
		{
			std::cout << "Obstacle detected, start replanning..." << std::endl;

			return false;
		}
		// move to the next cell
		current_location_ = next;
		counter--;
	}
	std::cout << std::endl << "Arrived at the destination." << std::endl;
	return true;
}
