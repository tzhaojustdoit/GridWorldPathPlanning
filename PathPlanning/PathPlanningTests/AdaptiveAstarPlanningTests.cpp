#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PathPlanning/AdaptiveAStarPlanning.h"
#include "../PathPlanning/AdaptiveAStarPlanning.cpp"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PathPlanningTests
{
	TEST_CLASS(AdaptiveAStarPlanningTests)
	{
	public:
		TEST_METHOD(FindPathTest) {
			AdaptiveAStarPlanning p(2, 2);
			p.SetGoal(3);
			std::vector<bool> obstacles{ 0,0,1,0 };
			std::vector<int> result =p.FindPath(obstacles, 0);
		}
	};
}