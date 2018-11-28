#include <vector>
#include <fstream>
#include <string>
#include "PathPlanner.h"
#include "AdaptiveAStarPathPlanner.h"
#include "AStarPathPlanner.h"
#include <iostream>
int main(int argc, char *argv[]) {
	if (argc < 3) {
		std::cout << "Invalid argument count." << std::endl;
		return 0;
	}
	std::string filename = "../data/" + std::string(argv[1]);
	std::vector<std::vector<char> > map;
	std::ifstream input_file_stream(filename.c_str());
	std::string line;
	if (input_file_stream.good()) {
		int row;
		input_file_stream >> row;
		int col;
		input_file_stream >> col;
		map.reserve(row);
		char cur;
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
		PathPlanner* p;
		if (strcmp(argv[2], "a*") == 0) {
			p = new AdaptiveAStarPathPlanner();
		} 
		if (strcmp(argv[2], "aa*") == 0) {
			p = new AStarPathPlanner();
		}
		else {
			std::cout << "Invalid argument." << std::endl;
			return 0;
		}
		std::cout << "Loading into the world..." << std::endl;
		p->Load(map);
		std::cout << "Navigation starts:" << std::endl;
		p->Go();
	}
	else {
		std::cout << "Error openning file." << std::endl;
	}
	return 0;
}