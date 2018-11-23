#include <vector>
#include <fstream>
#include <string>
#include "PathPlanner.h"
#include "AdaptiveAStarPathPlanner.h"
#include "AStarPathPlanner.h"
#include <iostream>
int main() {
	std::string filename = "15.txt";
	std::vector<std::vector<char>> map;
	std::ifstream input_file_stream(filename);
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
	}
	PathPlanner* p = new AdaptiveAStarPathPlanner();
	p->Load(map);
	p->Go();
	return 0;
}