#ifndef ADAPTIVE_ASTAR_PLANNING_
#define ADAPTIVE_ASTAR_PLANNING_

#include "Planning.h"
#include "Node.h"
#include "PriorityQueue.h"
#include <vector>
#include <iostream>

class AdaptiveAStarPlanning : public Planning
{
public:
	AdaptiveAStarPlanning(int rows, int cols);
	~AdaptiveAStarPlanning();
	void SetGoal(int goal) override;
	std::vector<int> FindPath(const std::vector<bool> &obsacles, int location) override;
	int GetNumOfSearches() const override;
	int GetNumOfNodesExpanded() const override;

private:
	int rows_;
	int cols_;
	int goal_location_;
	std::vector<Node> graph_;
	int num_of_searches_ = 0;
	int num_of_expanded_nodes_ = 0;
	int GetHeuristic(int a, int b);
	void Expand(int id, const std::vector<bool> & obstacles, std::vector<Node*> & closed, PriorityQueue & open);
	void Generate(int id, int parent_id, std::vector<Node*> & closed, PriorityQueue & open);
};
#endif // !ADAPTIVE_ASTAR_PLANNING_



