#ifndef DISPLAY_
#define DISPLAY_

#include <vector>
#include <iostream>

#include "Point2D.h"
#include "Node.h"
#include "Marker.h"

namespace Display {
	void DisplayMap(int row, int col, const std::vector<bool> &map, const std::vector<int> &path, int start, int goal);
}
#endif // !DISPLAY_



