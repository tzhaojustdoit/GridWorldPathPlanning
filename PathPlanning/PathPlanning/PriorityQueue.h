/**
 * @file PriorityQueue.h
 * @brief Defines the PriorityQueue class.
 * @authur: Tianhua Zhao
 */

#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_

#include <vector>

#include "Node.h"

/*
 *@class PriorityQueue
 *
 *@brief A priority queue of node pointers. Min element is always on top and poped first.
 * Smaller f value is favored; if f values are the same, node with larger g value is favored.
 */
class PriorityQueue
{
public:
	/**
	 * @brief insert a node pointer
	 */
	void push(Node*);

	/**
	 * @brief remove top node pointer
	 */
	Node* pop();

	/**
	 * @brief access top node pointer
	 */
	Node* top() const;

	/**
	 * @brief test whether container is empty
	 */
	bool empty() const;

	/**
	 * @brief return size
	 */
	int size() const;

	/**
	 * @brief test whether a node pointer is in the priority queue
	 */
	bool contains(Node*) const;

private:
	/**
	 * @brief the underlying container
	 */
	std::vector<Node*> vec_;

	/**
	 * @brief perculate a node* up to the correct location
	 */
	void perculate_up(int);

	/**
	 * @brief perculate a node* down to the correct location
	 */
	void perculate_down(int);
};
#endif // !PRIORITY_QUEUE_

