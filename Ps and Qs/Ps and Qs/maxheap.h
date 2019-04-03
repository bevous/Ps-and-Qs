#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_

#include <iostream>
#include <stdexcept>
#include <vector>

namespace nwacc
{
	template <typename E>
	class min_heap
	{
	public:
		min_heap(int capacity = kDefaultSize) : array(capacity + 1), size{ 0 } {}

		static const int kDefaultSize = 50;

		bool is_empty() const
		{
			return this->size == 0;
		}

		const E & get_min() const
		{
			if (this->is_empty())
			{
				throw std::out_of_range("Heap is empty");
			}
			else
			{
				return this->array[1];
			}
		}
		void insert(const E & x)
		{
			if (this->size == this->array.size() - 1)
			{
				this->array.resize(this->array.size() * 2);
			}

			// Percolate up
			int hole = ++this->size;
			E copy = x;

			this->array[0] = std::move(copy);
			for (; x < this->array[hole / 2]; hole /= 2 )
			{
				this->array[hole] = std::move(this->array[hole / 2]);
			}
			this->array[hole] = std::move(copy);
		}


		void insert(E && value)
		{
			// we want to see if I have room. 
			if (this->size == this->array.size() - 1)
			{
				this->array.resize(this->array.size() * 2);
			} // else, we have space, do_nothing();

			// unlike a BST or AVL we allow duplicates!
			// we have to find the spot for the element (heap we call this the hole)
			// we have to decide if it needs to move up (percolate)
			auto spot = ++this->size; // most of the time auto hole = ++this->size;
			while (spot > 1 && value < this->array[spot / 2])
			{
				this->array[spot] = std::move(this->array[spot / 2]);
				spot /= 2;
			}
			this->array[spot] = std::move(value);
		}

		void remove()
		{
			if (this->is_empty())
			{
				throw std::out_of_range("Heap is empty");
			}
			else
			{
				this->array[1] = std::move(this->array[this->size--]);
				this->percolate_down(1);
			}
		}

		void print(std::ostream & out = std::cout)
		{
			auto index = 1;
			while (index <= this->size)
			{
				out << this->array[index] << " ";
				index++;
			}
			out << std::endl;
		}

	private:
		std::vector<E> array;

		int size;

		void percolate_down(int spot)
		{
			auto temp = std::move(this->array[spot]);
			auto child = 0;
			auto is_done = false;

			while (!is_done && spot * 2 <= this->size)
			{
				child = spot * 2;
				if (child != this->size && this->array[child + 1] < this->array[child])
				{
					child++;
				}

				if (this->array[child] < temp)
				{ // we found a place!
					this->array[spot] = std::move(this->array[child]);
					spot = child;
				}
				else
				{
					is_done = true;
				}
			}
			this->array[spot] = std::move(temp);
		}
	};
}

#endif // MIN_HEAP_H_