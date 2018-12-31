#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PathPlanning/Read.h"
#include "../PathPlanning/Read.cpp"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PathPlanningTests
{
	TEST_CLASS(ReadTests)
	{
	public:
		TEST_METHOD(ReadFileTest) {
			std::string filename = "1.txt";
			MapData result = Read::ReadMapFile("../data/" + filename);
			Assert::AreEqual(result.cols, 2);
		}
	};
}