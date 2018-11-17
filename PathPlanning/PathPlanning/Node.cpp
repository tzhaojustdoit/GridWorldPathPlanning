#include "Node.h"

int Node::GetG() const
{
	return g_;
}

int Node::GetH() const
{
	return h_;
}

int Node::GetF() const
{
	return f_;
}

Node * Node::GetParent() const
{
	return parent_;
}

int Node::GetNumOfNeighbors() const
{
	return numOfNeighbors_;
}

Node * Node::GetNeighbor(int num) const
{
	if (num < numOfNeighbors_) {
		return neighbors_[num];
	}
	return nullptr;
}



void Node::SetG(int g)
{
	g_ = g;
	f_ = g_ + h_;
}

void Node::SetH(int h)
{
	h_ = h;
	f_ = g_ + h_;
}

void Node::SetParent(Node * n)
{
	parent_ = n;
}

void Node::AddNeightbor(Node * n)
{
	neighbors_[numOfNeighbors_] = n;
	++numOfNeighbors_;
}


bool Node::operator<(const Node &other)
{
	if (f_ < other.f_) {
		return true;
	}
	if (f_ > other.f_)
	{
		return false;
	}
	return g_ > other.g_;
}

