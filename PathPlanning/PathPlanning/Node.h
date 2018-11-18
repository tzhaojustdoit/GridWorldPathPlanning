#pragma once
#include <vector>
// A node in a graph.
// @author Tianhua Zhao
class Node
{

public:

	// accessors
	// get the g value;
	int get_g() const;
	// get the h value;
	int get_h() const;
	// get the f value;
	int get_f() const;
	// get the parent node pointer;
	Node* get_parent() const;
	// get number of neighbors the node has
	int get_num_of_neighbors() const;
	// get the neighbor's node pointer
	Node* get_neighbor(int) const;

	// mutators
	// set the g value;
	void set_g(int);
	// set the h value;
	void set_h(int);
	// set the parent pointer
	void set_parent(Node*);
	// add a neighbor
	void add_neightbor(Node*);
	// set the location: x, y
	void set_location(int, int);

	// comparators
	bool operator< (const Node &);

private:

	int g_ = 0;
	int h_ = 0;
	int f_ = 0;
	Node* parent_ = nullptr;
	int num_of_neighbors_ = 0;
	Node* neighbors_[4];
	int x_;
	int y_;
};
