#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PathPlanning/PathPlanner.h"
#include "../PathPlanning/PathPlanner.cpp"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PathPlanningTests
{
	TEST_CLASS(PathPlannerTests)
	{
	public:
		TEST_METHOD_INITIALIZE(Initializer) 
		{
			std::vector<int> map_row1{ 1,-1 };
			std::vector<int> map_row2{ 0,2 };
			map1.push_back(map_row1);
			map1.push_back(map_row2);

			map_row1 = { 0,0 };
			map_row2 = { -1,0 };
			map2.push_back(map_row1);
			map2.push_back(map_row2);

			map_row1 = { -1,0,-1,-1,0 };
			map_row2 = { 1,0,0,-1,0 };
			std::vector<int>map_row3 = { -1,-1,0,0,2 };
			map3.push_back(map_row1);
			map3.push_back(map_row2);
			map3.push_back(map_row3);

			map_row1 = { -1,0,0,0,0 };
			map_row2 = { 1,0,-1,-1,0 };
			map_row3 = { -1,0,-1,0,2 };
			map4.push_back(map_row1);
			map4.push_back(map_row2);
			map4.push_back(map_row3);
		}
		TEST_METHOD(ConstructorTest)
		{

			PathPlanner p{ map1 };
			// manually debugged
		}

		TEST_METHOD(StartEndTest)
		{

			PathPlanner p{ map1 };
			Point2D expected_start{ 1,1 };
			Point2D expected_goal{ 2,2 };
			Assert::IsTrue(p.get_start_pos() == expected_start);
			Assert::IsTrue(p.get_goal_pos() == expected_goal);

			PathPlanner p2{ map2 };
			expected_start = { -1,-1 };
			expected_goal = { -1,-1 };
			Assert::IsTrue(p2.get_start_pos() == expected_start);
			Assert::IsTrue(p2.get_goal_pos() == expected_goal);
		}

		TEST_METHOD(AStarTest)
		{

			PathPlanner p{ map4 };
			p.a_star_go();
			std::string res = p.toString();
			// manualy debugged
		}

	private:
		std::vector<std::vector<int>> map1;
		std::vector<std::vector<int>> map2;
		std::vector<std::vector<int>> map3;
		std::vector<std::vector<int>> map4;
	};
}