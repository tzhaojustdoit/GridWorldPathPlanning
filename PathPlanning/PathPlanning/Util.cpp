#include "Util.h"

std::vector<std::vector<char>> util::FileToMatrix(std::string filename)
{
	std::vector<std::vector<char>> res;
	std::ifstream input_file_stream(filename);
	std::string line;
	if (input_file_stream.good()) {
		int row;
		input_file_stream >> row;
		int col;
		input_file_stream >> col;
		res.reserve(row);
		while (std::getline(input_file_stream, line).good()) {
			std::vector<char> row_vec;
			row_vec.reserve(col);
			for (char var : line)
			{
				row_vec.push_back(var);
			}
			res.push_back(row_vec);
		}
	}
	return res;
}
