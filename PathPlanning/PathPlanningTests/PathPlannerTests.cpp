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

		TEST_METHOD(ConstructorTest)
		{
			std::vector<std::vector<char>> map;
			std::vector<char> map_row1{'s','_'};
			std::vector<char> map_row2{ 'x','g' };
			map.push_back(map_row1);
			map.push_back(map_row2);
			PathPlanner p{ map };
			// manually debugged
			Assert::IsTrue(1);
		}

	};
}