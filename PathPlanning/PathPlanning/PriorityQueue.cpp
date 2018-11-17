#include "PriorityQueue.h"



PriorityQueue::PriorityQueue()
{
}


PriorityQueue::~PriorityQueue()
{
}

void PriorityQueue::push(const Node &n)
{
	vec_.push_back(n);
	perculate_up(vec_.size() - 1);
}

void PriorityQueue::pop()
{
	std::swap(vec_.front(), vec_.back());
	vec_.pop_back();
	perculate_down(0);
}

const Node & PriorityQueue::top() const
{
	return vec_[0];
}

bool PriorityQueue::empty() const
{
	return vec_.size() == 0;
}

int PriorityQueue::size() const
{
	return vec_.size();
}

void PriorityQueue::perculate_up(int idx)
{
	while (idx > 0 && vec_[idx] < vec_[(idx - 1) / 2]) {
		std::swap(vec_[idx], vec_[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}

void PriorityQueue::perculate_down(int idx)
{
	while (idx * 2 + 1 < (int)vec_.size()) {
		int minChildIdx = idx * 2 + 1;
		if (idx * 2 + 2 < (int)vec_.size() && vec_[idx * 2 + 2] < vec_[idx * 2 + 1]) {
			minChildIdx = idx * 2 + 2;
		}
		if (vec_[minChildIdx] < vec_[idx]) {
			std::swap(vec_[idx], vec_[minChildIdx]);
		}
		idx = minChildIdx;
	}
}
