#pragma once
#include <vector>
// A node in a graph.
// @author Tianhua Zhao
class Node
{

public:

	// accessors
	// get the g value;
	int GetG() const;
	// get the h value;
	int GetH() const;
	// get the f value;
	int GetF() const;
	// get the parent node pointer;
	Node* GetParent() const;
	// get number of neighbors the node has
	int GetNumOfNeighbors() const;
	// get the neighbor's node pointer
	Node* GetNeighbor(int) const;

	// mutators
	// set the g value;
	void SetG(int);
	// set the h value;
	void SetH(int);
	// set the parent pointer
	void SetParent(Node*);
	// add a neighbor
	void AddNeightbor(Node*);

	// comparators
	bool operator< (const Node &);

private:

	int g_ = 0;
	int h_ = 0;
	int f_ = 0;
	Node* parent_ = nullptr;
	int numOfNeighbors_ = 0;
	Node* neighbors_[4];

};
