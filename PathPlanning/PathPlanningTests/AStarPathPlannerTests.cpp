#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PathPlanning/AStarPathPlanner.h"
#include "../PathPlanning/AStarPathPlanner.cpp"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PathPlanningTests
{
	TEST_CLASS(AStarPathPlannerTests)
	{
	public:
		TEST_METHOD_INITIALIZE(Initializer)
		{
			std::vector<char> map_row1{ 's','x' };
			std::vector<char> map_row2{ '_','g' };
			map1.push_back(map_row1);
			map1.push_back(map_row2);

			map_row1 = { '_','g' };
			map_row2 = { 's','_' };
			map2.push_back(map_row1);
			map2.push_back(map_row2);

			map_row1 = { 'x', '_','x','x','_' };
			map_row2 = { 's', '_', '_','x','_' };
			std::vector<char>map_row3 = { 'x','x', '_', '_','g' };
			map3.push_back(map_row1);
			map3.push_back(map_row2);
			map3.push_back(map_row3);
		}
		TEST_METHOD(ConstructorTest)
		{
			AStarPathPlanner p;
			p.Load(map1);
			p.Load(map3);
			p.Load(map2);
			// manually debugged
		}

	private:
		std::vector<std::vector<char>> map1;
		std::vector<std::vector<char>> map2;
		std::vector<std::vector<char>> map3;
	};
}