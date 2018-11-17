#pragma once
#include <vector>
#include "Node.h"
class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();
	void push(const Node &);
	void pop();
	const Node & top() const;
	bool empty() const;
	int size() const;
private:
	std::vector<Node> vec_ = std::vector<Node>();
	void perculate_up(int);
	void perculate_down(int);
};