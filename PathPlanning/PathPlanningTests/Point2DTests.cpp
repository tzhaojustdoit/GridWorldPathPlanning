#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PathPlanning/Point2D.h"
#include "../PathPlanning/Point2D.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PathPlanningTests
{
	TEST_CLASS(Point2DTests)
	{
	public:

		TEST_METHOD(GetManhattanDistanceTest)
		{
			Point2D p1{ 1,2 };
			Point2D p2{ 0,4 };
			Assert::AreEqual(3, p1.get_manhattan_distance(p2));
		}

		TEST_METHOD(EqualityTest)
		{
			Point2D p1{ 1,2 };
			Point2D p2{ 1,2 };
			Assert::IsTrue(p1 == p2);
		}

	};
}