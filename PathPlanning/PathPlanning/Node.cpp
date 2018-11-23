#include "Node.h"

Node::Node() {}
Node::Node(int x, int y) : x_(x), y_(y)
{
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


int Node::get_x() const
{
	return x_;
}

int Node::get_y() const
{
	return y_;
}

bool Node::is_blocked() const
{
	return blocked;
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


void Node::set_location(int x, int y)
{
	x_ = x;
	y_ = y;
}

void Node::set_blocked()
{
	blocked = true;
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

