#include <gtest/gtest.h> // googletest header file

#include "../app/doubleEndedQueue.h"

// ---------------------------------------------------------------------
// doubleEndedQueue<int> tests

TEST(DeqSuiteInt, pushPopBack5)
{
	doubleEndedQueue<int> deq;
	int inputArr[5] = { 10, 20, 30, 40, 50 };
	for (auto elem : inputArr)
	{
		deq.push_back(elem);
	}

	EXPECT_EQ(deq.size(), 5);
	for (auto elem : inputArr)
	{
		EXPECT_EQ(elem, deq.pop_front());
	}
	EXPECT_EQ(deq.size(), 0);
}

TEST(DeqSuiteInt, pushPopFront5)
{
	doubleEndedQueue<int> deq;
	int inputArr[5] = { 10, 20, 30, 40, 50 };
	for (auto elem : inputArr)
	{
		deq.push_front(elem);
	}

	EXPECT_EQ(deq.size(), 5);
	for (auto elem : inputArr)
	{
		EXPECT_EQ(elem, deq.pop_back());
	}
	EXPECT_EQ(deq.size(), 0);
}

TEST(DeqSuiteInt, at)
{
	doubleEndedQueue<int> deq;
	int inputArr[5] = { 10, 20, 30, 40, 50 };
	for (auto elem : inputArr)
	{
		deq.push_back(elem);
	}
	
	deq.at(2) = inputArr[2];
	deq.at(4) = inputArr[4];

	EXPECT_EQ(deq.size(), 5);
	for (auto elem : inputArr)
	{
		EXPECT_EQ(elem, deq.pop_front());
	}
	EXPECT_EQ(deq.size(), 0);
}
