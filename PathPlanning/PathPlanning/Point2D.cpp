#include "Point2D.h"


int Point2D::get_manhattan_distance(const Point2D &other) const
{
	return abs(x - other.x) + abs(y -other.y);
}

bool Point2D::operator==(const Point2D & other) const
{
	return x == other.x && y == other.y;
}
