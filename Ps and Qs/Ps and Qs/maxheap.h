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
		void insert(const E & value)
		{
			if (this->size == this->array.size() - 1)
			{
				this->array.resize(this->array.size() * 2);
			}

			// Percolate up
			++this->size;
			int hole = this->size - 1;
			this->array[hole] = std::move(value);

			for (;hole > 0 && this->array[(hole -1) / 2] < this->array[hole] ; hole = (hole - 1) / 2)
			{
				std::swap(this->array[hole], this->array[(hole - 1) / 2]);
			}
			
		}


		void insert(E && value)
		{
			// we want to see if I have room. 
			if (this->size == this->array.size() - 1)
			{
				this->array.resize(this->array.size() * 2);
			} // else, we have space, do_nothing();
			// Percolate up
			++this->size;
			int hole = this->size - 1;
			this->array[hole] = std::move(value);

			for (; hole > 0 && this->array[(hole - 1) / 2] < this->array[hole]; hole = (hole - 1) / 2)
			{
				std::swap(this->array[hole], this->array[(hole - 1) / 2]);
			}

		}

		void remove()
		{
			if (this->is_empty())
			{
				throw std::out_of_range("Heap is empty");
			}
			else
			{
				this->array[0] = std::move(this->array[this->size--]);
				this->percolate_down(0);
			}
		}

		void print(std::ostream & out = std::cout)
		{
			
			for(auto value=0;value<this->size;value++)
			{
				out << this->array[value]<<",";
				out << this->array[(2 * value) + 1] << ",";
				out << this->array[(2 * value) + 2] << std::endl;
			}

			/*auto index = 1;
			while (index <= this->size)
			{
				out << this->array[index] << " ";
				index++;
			}
			out << std::endl;*/
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