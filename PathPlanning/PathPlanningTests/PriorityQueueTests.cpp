#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PathPlanning/PriorityQueue.h"
#include "../PathPlanning/PriorityQueue.cpp"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PathPlanningTests
{
	TEST_CLASS(PriorityQueueUnitTests)
	{

	public:
		TEST_METHOD_INITIALIZE(Initializer)
		{
			n1.set_g(1);
			n2.set_g(2);
			n3.set_g(3);
			n4_1.set_g(1);
			n4_1.set_h(3);
			n4_2.set_g(2);
			n4_2.set_h(2);
			n4_3.set_g(3);
			n4_3.set_h(1);
			pq.push(n4_1);
			pq.push(n4_2);
			pq.push(n4_3);
			pq.push(n3);
			pq.push(n2);
			pq.push(n1);
			pq.push(n0);

		}
		TEST_METHOD(CopyAssignmentPopTopSizeEmptyTest)
		{
			PriorityQueue pqCopy{};
			pqCopy = pq;
			Assert::AreEqual(pqCopy.top().get_f(), 0);
			Assert::AreEqual(pqCopy.size(), 7);
			pqCopy.pop();
			Assert::AreEqual(pqCopy.top().get_f(), 1);
			pqCopy.pop();
			Assert::AreEqual(pqCopy.top().get_f(), 2);
			pqCopy.pop();
			Assert::AreEqual(pqCopy.top().get_f(), 3);
			pqCopy.pop();
			Assert::AreEqual(pqCopy.top().get_h(), 1);
			pqCopy.pop();
			Assert::AreEqual(pqCopy.top().get_h(), 2);
			pqCopy.pop();
			Assert::AreEqual(pqCopy.top().get_h(), 3);
			pqCopy.pop();
			Assert::AreEqual(pqCopy.size(), 0);
			Assert::IsTrue(pqCopy.empty());
			Assert::AreEqual(pq.top().get_f(), 0);
			Assert::AreEqual(pq.size(), 7);
			Assert::IsFalse(pq.empty());
			pqCopy = pq;
			Node n3_1;
			n3_1.set_g(2);
			n3_1.set_h(1);
			pqCopy.push(n3_1);
			Assert::AreEqual(pqCopy.top().get_f(), 0);
			Assert::AreEqual(pqCopy.size(), 8);
			pqCopy.pop();
			Assert::AreEqual(pqCopy.top().get_f(), 1);
			pqCopy.pop();
			Assert::AreEqual(pqCopy.top().get_f(), 2);
			pqCopy.pop();
			Assert::AreEqual(pqCopy.top().get_f(), 3);
			Assert::AreEqual(pqCopy.top().get_h(), 0);
			pqCopy.pop();
			Assert::AreEqual(pqCopy.top().get_f(), 3);
			Assert::AreEqual(pqCopy.top().get_h(), 1);
			pqCopy.pop();
			Assert::AreEqual(pqCopy.top().get_h(), 1);
			pqCopy.pop();
			Assert::AreEqual(pqCopy.top().get_h(), 2);
			pqCopy.pop();
			Assert::AreEqual(pqCopy.top().get_h(), 3);
			pqCopy.pop();
		}
	private:
		Node n0{};
		Node n1{};
		Node n2{};
		Node n3{};
		Node n4_1{};
		Node n4_2{};
		Node n4_3{};
		PriorityQueue pq{};
		std::vector<int> toVector(PriorityQueue pq) {
			std::vector<int> res;
			for (int i = 0; i < pq.size(); i++)
			{
				res.push_back(pq.top().get_h());
			}
			return res;
		}
	};
}