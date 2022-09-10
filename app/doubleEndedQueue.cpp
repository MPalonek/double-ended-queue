#include "doubleEndedQueue.h"

int main()
{
	doubleEndedQueue<int> deq;

	int s1 = deq.size();

	deq.push_back(10);
	deq.push_back(20);

	int s2 = deq.size();

	int item = deq.pop_back();

	int s3 = deq.size();

	

	std::cout << "s1: " << s1 << ", s2: " << s2 << ", item: " << item << ", s3: " << s3 << std::endl;

	deq.at(0) = 30;
	std::cout << "deq,at(0) " << deq.at(0);

	return 0;
}