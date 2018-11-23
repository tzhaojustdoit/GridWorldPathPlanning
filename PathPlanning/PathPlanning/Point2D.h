/**
 * @file Point2D.h
 * @brief Defines the Point2D struct.
 * @authur: Tianhua Zhao
 */

#ifndef POINT_2D_
#define POINT_2D_

#include <cmath>

/**
 * @struct Point2D
 *
 * @brief a 2d point.
 */
struct Point2D
{
	/**
	 * @brief x coordinate
	 */
	int x;

	/**
	 * @brief y coordinate
	 */
	int y;

	/**
	 * @brief get the manhattan distance to another 2d point
	 */
	int get_manhattan_distance(const Point2D &other) const;

	/**
	 * @brief overloaded == operator
	 */
	bool operator==(const Point2D &other) const;
};

#endif // !POINT_2D_



