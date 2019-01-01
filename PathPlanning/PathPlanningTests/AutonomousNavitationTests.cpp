#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PathPlanning/AutonomousNavigation.h"
#include "../PathPlanning/AutonomousNavigation.cpp"
#include "../PathPlanning/Planning.h"

#include "../PathPlanning/AdaptiveAStarPlanning.h"
#include "../PathPlanning/AStarPlanning.h"
#include "../PathPlanning/AStarPlanning.cpp"
#include "../PathPlanning/Read.h"

#include <vector>
#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PathPlanningTests
{
	TEST_CLASS(AutonomousNavigationTests)
	{
		TEST_METHOD(OutputTest)
		{
			std::vector<int> a;
			std::vector<int> aa;
			MapData data;
			for (int i = 1; i < 19; i++)
			{
				std::string filename = "../data/" + std::to_string(i) + ".txt";
				data = Read::ReadMapFile(filename);
				Planning* planning_unit = new AStarPlanning(data.rows, data.cols);
				MockPerception* perception_unit = new MockPerception(data.map, data.rows, data.cols);
				AutonomousNavigation an(data.rows, data.cols, perception_unit, planning_unit);
				an.SetDestination(data.goal);
				an.AutoNavigate();
				a.push_back(an.GetNumOfNodesExpanded());
				delete planning_unit;
				delete perception_unit;

				planning_unit = new AdaptiveAStarPlanning(data.rows, data.cols);
				perception_unit = new MockPerception(data.map, data.rows, data.cols);
				AutonomousNavigation an2(data.rows, data.cols, perception_unit, planning_unit);
				an2.SetDestination(data.goal);
				an2.AutoNavigate();
				aa.push_back(an2.GetNumOfNodesExpanded());
				delete planning_unit;
				delete perception_unit;
			}
		}
	};
}