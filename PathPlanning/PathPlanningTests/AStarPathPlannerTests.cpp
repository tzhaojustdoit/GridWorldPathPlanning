#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PathPlanning/AdaptiveAStarPathPlanner.h"
#include "../PathPlanning/AdaptiveAStarPathPlanner.cpp"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PathPlanningTests
{
	TEST_CLASS(AdaptiveAStarPathPlannerTests)
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

			map_row1 = { '_', 's','_','_' };
			map_row2 = { 'x', 'x', '_','_', };
			std::vector<char>map_row3 = { '_','_', 'x', 'x' };
			std::vector<char>map_row4 = { '_','g', '_', '_' };
			map3.push_back(map_row1);
			map3.push_back(map_row2);
			map3.push_back(map_row3);
			map3.push_back(map_row4);
		}
		TEST_METHOD(LoadTest)
		{
			AdaptiveAStarPathPlanner p;
			p.Load(map1);
			p.Load(map3);
			p.Load(map2);
			// manually debugged
		}

		TEST_METHOD(GoTest)
		{
			AdaptiveAStarPathPlanner p;
			p.Load(map3);
			p.Go();
			// manually debugged
		}

	private:
		std::vector<std::vector<char> > map1;
		std::vector<std::vector<char> > map2;
		std::vector<std::vector<char> > map3;
	};
}