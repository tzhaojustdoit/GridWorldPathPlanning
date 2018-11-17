#pragma once
#include <vector>
class Node
{

public:

	//accessors
	int GetG() const;
	int GetH() const;
	int GetF() const;
	Node* GetParent() const;
	int GetNumOfNeighbors() const;
	Node* GetNeighbor(int) const;

	//mutators
	void SetG(int);
	void SetH(int);
	void SetParent(Node*);
	void AddNeightbor(Node*);

	//comparators
	bool operator< (const Node &);

private:

	int g_ = 0;
	int h_ = 0;
	int f_ = 0;
	Node* parent_ = nullptr;
	int numOfNeighbors_ = 0;
	Node* neighbors_[4];

};
