#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PathPlanning/Node.h"
#include "../PathPlanning/Node.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PathPlanningTests
{
	TEST_CLASS(NodeTests)
	{
	public:

		TEST_METHOD(NodeSetGetTest)
		{
			Node* n = new Node{};
			n->SetG(0);
			n->SetH(1);
			Assert::AreEqual(0, n->GetG());
			Assert::AreEqual(1, n->GetH());
			Assert::AreEqual(1, n->GetF());
			n->SetG(1);
			Assert::AreEqual(1, n->GetG());
			Assert::AreEqual(1, n->GetH());
			Assert::AreEqual(2, n->GetF());
			n->SetH(3);
			Assert::AreEqual(1, n->GetG());
			Assert::AreEqual(3, n->GetH());
			Assert::AreEqual(4, n->GetF());
		}

	};
}