#include "MockPerceptionModule.h"

MockPerceptionModule::MockPerceptionModule(std::vector<char> actual_map, int row, int col): actual_map_(actual_map), row_(row), col_(col)
{
}

void MockPerceptionModule::PerceiveSurroundings(std::vector<bool>& map, int location)
{
	// perceive 4 adjacent cells in this order: right, down, left, up
	if ((location + 1) % col_ != 0) {  // boundary check (right boundary)
		PerceiveLocation(map, location + 1);
	}
	if ((location + 1) % col_ != 0) {  // boundary check (right boundary)
		PerceiveLocation(map, location + 1);
	}
	if ((location + 1) % col_ != 0) {  // boundary check (right boundary)
		PerceiveLocation(map, location + 1);
	}
	if ((location + 1) % col_ != 0) {  // boundary check (right boundary)
		PerceiveLocation(map, location + 1);
	}
}

void MockPerceptionModule::PerceiveLocation(std::vector<bool> &map, int location)
{
	if (actual_map_[location] == 'x') {
		map[location] = true;  // update map, mark the location as blocked
	}
}
