#include <iostream>
#include <string>

#include "maxheap.h"

int main()
{
	nwacc::min_heap<int> heap;

	for (auto index = 0; index <= 5; index++)
	{
		heap.insert(index);
	}
	heap.insert(9);
	heap.print();

	std::cout <<"removing" << std::endl;

	auto temp = 1;
	while (!heap.is_empty())
	{
		std::cout << heap.get_min() << " ";
		heap.remove();
		if (temp % 10 == 0)
		{
			std::cout << std::endl;
		}
		temp++;
	}
	system("pause");
	return 0;
}
