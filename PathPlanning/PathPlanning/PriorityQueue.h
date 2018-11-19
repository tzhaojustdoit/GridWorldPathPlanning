#pragma once
#include <vector>
#include "Node.h"
// A priority queue implementation, min element is alway on top.
// @author: Tianhua Zhao
class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();
	// push a node to priority queue.
	void push(Node*);
	// pop the min node.
	Node* pop();
	// peek the min node.
	const Node* top() const;
	// is the priority queue empty?
	bool empty() const;
	// the size of the priority queue
	int size() const;
private:
	std::vector<Node*> vec_ = std::vector<Node*>();
	void perculate_up(int);
	void perculate_down(int);
};