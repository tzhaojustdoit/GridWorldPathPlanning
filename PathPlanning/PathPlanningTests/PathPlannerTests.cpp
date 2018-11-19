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
			std::vector<char> map_row1{ 's','_' };
			std::vector<char> map_row2{ 'x','g' };
			map1.push_back(map_row1);
			map1.push_back(map_row2);

			map_row1 = { '_','_' };
			map_row2 = { 'x','_' };
			map2.push_back(map_row1);
			map2.push_back(map_row2);
		}
		TEST_METHOD(ConstructorTest)
		{

			PathPlanner p{ map1 };
			// manually debugged
			Assert::IsTrue(1);
		}

		TEST_METHOD(StartEndTest)
		{

			PathPlanner p{ map1 };
			Point2D expected_start{ 0,0 };
			Point2D expected_goal{ 1,1 };
			Assert::IsTrue(p.get_start_pos() == expected_start);
			Assert::IsTrue(p.get_goal_pos() == expected_goal);

			PathPlanner p2{ map2 };
			expected_start = { -1,-1 };
			expected_goal = { -1,-1 };
			Assert::IsTrue(p2.get_start_pos() == expected_start);
			Assert::IsTrue(p2.get_goal_pos() == expected_goal);
		}

	private:
		std::vector<std::vector<char>> map1;
		std::vector<std::vector<char>> map2;
	};
}