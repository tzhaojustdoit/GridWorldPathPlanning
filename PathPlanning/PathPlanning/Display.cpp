#include "Display.h"

void Display::DisplayMap(int row, int col, const std::vector<bool> &obstacles, const std::vector<int> &path, int start, int goal)
{
	std::vector<char> output(obstacles.size(), '_');
	// mark obstacles
	for (unsigned i = 0; i < obstacles.size(); i++)
	{
		if (obstacles[i]) {
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
	for (unsigned i = 0; i < obstacles.size(); i++)
	{
		if (counter == col) {
			std::cout << std::endl;
			counter = 0;
		}
		std::cout << output[i] << ' ';
		counter++;
	}
}
