#include <iostream>
#include <string>

#include "min_heap.h"

int main()
{
	nwacc::min_heap<int> heap;

	for (auto index = 9; index >= 0; index--)
	{
		heap.insert(index);
	}
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
	return 0;
}
