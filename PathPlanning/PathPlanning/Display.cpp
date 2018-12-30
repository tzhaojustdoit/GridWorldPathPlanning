#include "Display.h"

void Display::DisplayMap(int row, int col, const std::vector<bool> &map, const std::vector<int> &path, int start, int goal)
{
	std::vector<char> output(map.size(), '_');
	// mark obstacles
	for (int i = 0; i < map.size(); i++)
	{
		if (map[i]) {
			output[i] = 'x';
		}
	}
	// mark path
	for (int var : path) {
		output[var] = 'o';
	}
	// mark start
	output[start] = 's';
	// mark goal
	output[goal] = 'g';
	// console output
	int counter = 0;
	for (int i = 0; i < map.size(); i++)
	{
		if (counter == col) {
			std::cout << std::endl;
			counter = 0;
		}
		std::cout << output[i] << ' ';
		counter++;
	}
}
