#include <iostream>
#include <string>

#include "maxheap.h"

int main()
{
	nwacc::min_heap<int> heap;

	for (auto index = 99; index >= 0; index--)
	{
		heap.insert(index);
	}
	heap.insert(5);
	heap.insert(4);
	heap.insert(3);


	heap.print();

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
