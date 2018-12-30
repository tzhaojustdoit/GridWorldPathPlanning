#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PathPlanning/Display.h"
#include "../PathPlanning/Display.cpp"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PathPlanningTests
{
	TEST_CLASS(DisplayTests)
	{
	public:
		TEST_METHOD(DisplayTest) {
			std::vector<bool> map{ 0,0,1,0 };
			std::vector<int> path{ 1,3 };
			Display::DisplayMap(2, 2, map, path, 0, 3);
		}
	};
}