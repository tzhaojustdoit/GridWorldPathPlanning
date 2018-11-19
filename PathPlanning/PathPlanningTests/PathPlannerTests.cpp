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
			std::vector<char> map_row1{ 's','x' };
			std::vector<char> map_row2{ '_','g' };
			map1.push_back(map_row1);
			map1.push_back(map_row2);

			map_row1 = { '_','_' };
			map_row2 = { 'x','_' };
			map2.push_back(map_row1);
			map2.push_back(map_row2);

			map_row1 = { 'x','_','x','x','_' };
			map_row2 = { 's','_','_','x','_' };
			std::vector<char>map_row3 = { 'x','x','_','_','g' };
			map3.push_back(map_row1);
			map3.push_back(map_row2);
			map3.push_back(map_row3);

			map_row1 = { 'x','_','_','_','_' };
			map_row2 = { 's','_','x','x','_' };
			map_row3 = { 'x','_','x','_','g' };
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
			p.a_star_search();
			std::string res = p.toString();
			// manualy debugged
		}

	private:
		std::vector<std::vector<char>> map1;
		std::vector<std::vector<char>> map2;
		std::vector<std::vector<char>> map3;
		std::vector<std::vector<char>> map4;
	};
}