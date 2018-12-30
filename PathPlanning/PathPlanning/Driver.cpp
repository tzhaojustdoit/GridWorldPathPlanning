/**
 * @file Driver.cpp
 * @brief Defines the main.
 * @authur: Tianhua Zhao
 */

#include <vector>
#include <fstream>
#include <string>
#include <iostream>

#include "PathPlanner.h"
#include "AdaptiveAStarPathPlanner.h"
#include "AStarPathPlanner.h"
#include "Display.h"

/*
 *@brief Reads input map from a txt file and runs AdaptiveAstarPathPlanner or AstarPathPlanner on the map.
 *Accepts two command line input: 1. file name. 2. a* or adaptive a*.
 *Sample command line input : 1.txt a*
 *						      10.txt aa*
 */
int main(int argc, char *argv[]) {
	std::vector<bool> map2{ 0,0,1,0 };
	std::vector<int> path{ 1,3 };
	Display::DisplayMap(2, 2, map2, path, 0, 3);
	if (argc < 3) {
		std::cout << "Invalid argument count." << std::endl;
		return 0;
	}
	std::string filename = "../data/" + std::string(argv[1]);
	std::vector<std::vector<char> > map;
	std::ifstream input_file_stream(filename.c_str());
	std::string line;
	if (input_file_stream.good()) {
		int row; // number of rows
		input_file_stream >> row;
		int col; // number of columns
		input_file_stream >> col;
		map.reserve(row);
		char cur;
		// construct a 2d vector of char
		for (int i = 0; i < row; i++)
		{
			std::vector<char> row_vec;
			row_vec.reserve(col);
			for (int i = 0; i < col; i++)
			{
				input_file_stream >> cur;
				row_vec.push_back(cur);
			}
			map.push_back(row_vec);
		}
		input_file_stream.close();
		// construct PathPlanner
		PathPlanner* p;
		if (strcmp(argv[2], "a*") == 0) {
			p = new AdaptiveAStarPathPlanner();
		} 
		else if (strcmp(argv[2], "aa*") == 0) {
			p = new AStarPathPlanner();
		}
		else {
			std::cout << "Invalid argument." << std::endl;
			return 0;
		}
		// load the map
		std::cout << "Loading into the world..." << std::endl;
		p->Load(map);
		// go
		std::cout << "Navigation starts:" << std::endl;
		p->Go();
	}
	else {
		std::cout << "Error openning file." << std::endl;
	}
	return 0;
}