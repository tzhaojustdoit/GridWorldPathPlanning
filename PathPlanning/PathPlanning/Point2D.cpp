#include "Point2D.h"


int Point2D::get_manhattan_distance(const Point2D &other) const
{
	return std::abs(x - other.x) + std::abs(y -other.y);
}

bool Point2D::operator==(const Point2D & other) const
{
	return x == other.x && y == other.y;
}
