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

		TEST_METHOD(Nodeset_getTest)
		{
			Node* n = new Node{};
			n->set_g(0);
			n->set_h(1);
			Assert::AreEqual(0, n->get_g());
			Assert::AreEqual(1, n->get_h());
			Assert::AreEqual(1, n->get_f());
			n->set_g(1);
			Assert::AreEqual(1, n->get_g());
			Assert::AreEqual(1, n->get_h());
			Assert::AreEqual(2, n->get_f());
			n->set_h(3);
			Assert::AreEqual(1, n->get_g());
			Assert::AreEqual(3, n->get_h());
			Assert::AreEqual(4, n->get_f());
		}

		TEST_METHOD(Nodeset_get_parentTest)
		{
			Node* p = new Node{};
			p->set_g(0);
			p->set_h(1);
			Node* n = new Node{};
			n->set_parent(p);
			Assert::AreEqual(n->get_parent()->get_g(), 0);
			Assert::AreEqual(n->get_parent()->get_h(), 1);
		}

		TEST_METHOD(NodeNeighborTest)
		{
			Node* n = new Node{};
			Node* n1 = new Node{};
			n1->set_g(1);
			Node* n2 = new Node{};
			n2->set_g(2);
			n->add_neightbor(n1);
			Assert::AreEqual(n->get_num_of_neighbors(), 1);
			Assert::AreEqual(n->get_neighbor(0)->get_g(), 1);
			n->add_neightbor(n2);
			Assert::AreEqual(n->get_num_of_neighbors(), 2);
			Assert::AreEqual(n->get_neighbor(1)->get_g(), 2);
		}

		TEST_METHOD(NodeLessThanOperatorTest)
		{
			Node* n1 = new Node{};
			n1->set_g(0);
			n1->set_h(1);
			Node* n2 = new Node{};
			n2->set_g(0);
			n2->set_h(2);
			Assert::IsTrue(*n1 < *n2);
			Node* n3 = new Node{};
			n2->set_g(0);
			n2->set_h(0);
			Assert::IsFalse(*n1 < *n3);
			Node* n4 = new Node{};
			n2->set_g(1);
			n2->set_h(0);
			Assert::IsFalse(*n1 < *n4);
		}
	};
}