#include "Node.h"

Node::Node(int g, int h, Node * parent, int x, int y)
{
	g_ = g;
	h_ = h;
	parent_ = parent;
	x_ = x;
	y_ = y;
}

int Node::get_g() const
{
	return g_;
}

int Node::get_h() const
{
	return h_;
}

int Node::get_f() const
{
	return f_;
}

Node * Node::get_parent() const
{
	return parent_;
}

int Node::get_num_of_neighbors() const
{
	return num_of_neighbors_;
}

Node * Node::get_neighbor(int num) const
{
	if (num < num_of_neighbors_) {
		return neighbors_[num];
	}
	return nullptr;
}

int Node::get_x()
{
	return x_;
}

int Node::get_y()
{
	return y_;
}



void Node::set_g(int g)
{
	g_ = g;
	f_ = g_ + h_;
}

void Node::set_h(int h)
{
	h_ = h;
	f_ = g_ + h_;
}

void Node::set_parent(Node * n)
{
	parent_ = n;
}

void Node::add_neightbor(Node * n)
{
	neighbors_[num_of_neighbors_] = n;
	++num_of_neighbors_;
}

void Node::set_location(int x, int y)
{
	x_ = x;
	y_ = y;
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

