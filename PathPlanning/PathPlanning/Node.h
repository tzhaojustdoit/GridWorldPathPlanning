/**
 * @file Node.h
 * @brief Defines the Node class.
 * @authur: Tianhua Zhao
 */

#ifndef NODE_
#define NODE_
#include <vector>
#include "Point2D.h"

/**
 * @class Node
 *
 * @brief A cell node in a grid world.
 * @invariants: f = g + h
 */
class Node
{
public:
	Node();

	/**
	 *@brief construct a node with given x, y coordinate
	 */
	Node(int x, int y);

	/**
	 *@brief get g value
	 */
	int get_g() const;

	/**
	 *@brief get h value
	 */
	int get_h() const;

	/**
	 *@brief get f value
	 */
	int get_f() const;

	/**
	 *@brief get parent pointer
	 */
	Node* get_parent() const;

	/**
	 *@brief get x coordinate
	 */
	int get_x() const;

	/**
	 *@brief get y coordinate
	 */
	int get_y() const;

	/**
	 *@brief if the cell is blocked
	 */
	bool is_blocked() const;
	
	/**
	 *@brief get the current location
	 */
	Point2D get_location() const;

	/**
	 *@brief set g value
	 */
	void set_g(int);

	/**
	 *@brief set h value
	 */
	void set_h(int);

	/**
	 *@brief set parent pointer
	 */
	void set_parent(Node*);

	/**
	 *@brief set location
	 */
	void set_location(int, int);

	/**
	 *@brief mark the cell as blocked
	 */
	void set_blocked();

	/**
	 *@brief overloaded < operator 
	 */
	bool operator< (const Node &);

private:

	int g_ = 0;
	int h_ = 0;
	int f_ = 0;
	Node* parent_ = nullptr;
	int x_ = 0;
	int y_ = 0;
	bool blocked = false;
};
#endif // !NODE_




