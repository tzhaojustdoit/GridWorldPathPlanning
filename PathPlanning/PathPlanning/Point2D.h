#pragma once
#include <cmath>
struct Point2D
{
	int x;
	int y;
	int get_manhattan_distance(const Point2D &other) const;
};

