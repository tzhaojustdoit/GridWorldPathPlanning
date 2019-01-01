/**
 * @file Driver.cpp
 * @brief Defines the main.
 * @authur: Tianhua Zhao
 */

#include <vector>
#include <fstream>
#include <string>
#include <iostream>

#include "AutonomousNavigation.h"
#include "Planning.h"
#include "AdaptiveAStarPlanning.h"
#include "Read.h"
/*
 *@brief Reads input map from a txt file and runs AdaptiveAstarPathPlanner or AstarPathPlanner on the map.
 *Accepts two command line input: 1. file name. 2. a* or adaptive a*.
 *Sample command line input : 1.txt a*
 *						      10.txt aa*
 */
int main(int argc, char *argv[]) {
	if (argc < 3) {
		std::cout << "Invalid argument count." << std::endl;
		return 0;
	}
	std::string filename = "../data/" + std::string(argv[1]);
	MapData data = Read::ReadMapFile(filename);
	Planning* planning_unit =  new AdaptiveAStarPlanning(data.rows, data.cols);
	MockPerception* perception_unit = new MockPerception(data.map, data.rows, data.cols);
	AutonomousNavigation an(data.rows, data.cols, perception_unit, planning_unit);
	an.SetDestination(data.goal);
	an.AutoNavigate();
	return 0;
}