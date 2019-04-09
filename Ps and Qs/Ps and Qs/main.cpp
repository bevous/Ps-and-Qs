#include <cstdlib>
#include <ctime>
#include <iostream>

#include "maxheap.h"
#include "pq.h"


int main()
{
	nwacc::max_heap<int> heap;
	const int range = 1000;
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	for (auto index = 0; index <= 5; index++)
	{
		 heap.insert(std::rand() % range);
	}
	heap.insert(9);
	heap.print();

	std::cout <<"removing" << std::endl;

	while (!heap.is_empty())
	{
		std::cout<< heap.remove()<<", ";
	}

	std::cout << std::endl <<"testing the PQ" << std::endl;

	nwacc::pq<int> my_pq;
	for (auto index = 0; index <= 5; index++)
	{
		my_pq.offer(std::rand() % range);
	}
	my_pq.offer(9);
	my_pq.print();

	std::cout << "removing" << std::endl;

	while (!my_pq.is_empty())
	{
		std::cout << my_pq.poll() << ", ";
	}


	system("pause");
	return 0;
}
