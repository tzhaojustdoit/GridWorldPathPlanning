#include "Node.h"


Node::Node()
{
}

int Node::GetId() const
{
	return id_;
}

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

int Node::GetParentId() const
{
	return parent_id_;
}

CellType Node::GetType() const
{
	return type_;
}

void Node::SetId(int id)
{
	id_ = id;
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

void Node::SetParentId(int id)
{
	parent_id_ = id;
}

void Node::SetType(CellType type)
{
	type_ = type;
}

