#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PathPlanning/MockPerception.h"
#include "../PathPlanning/MockPerception.cpp"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PathPlanningTests
{
	TEST_CLASS(MockPerceptionTests)
	{
	public:
		TEST_METHOD(ConstructorTest) {
			std::vector<char> actual_map{ 's', '_', 'x', 'g' };
			MockPerception p(actual_map, 2, 2);
		}

		TEST_METHOD(PerceiveSurroundingsTest) {
			std::vector<char> actual_map{ 's', '_', 'x', 'g' };
			MockPerception p(actual_map, 2, 2);
			std::vector<bool> map{ 0,0,0,0 };
			p.PerceiveSurroundings(map, 1);
		}

		TEST_METHOD(LocalizeTest) {
			std::vector<char> actual_map{ 's', '_', 'x', 'g' };
			MockPerception p(actual_map, 2, 2);
			int result = p.Localize();
			Assert::AreEqual(result, 0);
		}
	};
}