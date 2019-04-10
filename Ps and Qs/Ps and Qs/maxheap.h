#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <stdexcept>
#include <vector>

namespace nwacc
{
	template <typename E>
	class max_heap
	{
	public:
		/*!
		 * sets the capacity of the array
		 * 
		 * \param capacity
		 */
		max_heap(int capacity = kDefaultSize) : array(capacity + 1), size{ 0 } {}
		/*!
		 * the default size of the array
		 * 
		 */
		static const int kDefaultSize = 50;
		/*!
		 * checks if the heap is empty
		 * 
		 * \return bool
		 */
		bool is_empty() const
		{
			return this->size == 0;
		}
		/*!
		 * gets the element at the root of the heap
		 * 
		 * \return E&
		 */
		const E & get_max() const
		{
			if (this->is_empty())
			{
				throw std::out_of_range("Heap is empty");
			}
			else
			{
				return this->array[0];
			}
		}
		/*!
		 * inserts the given value
		 * 
		 * \param value
		 */
		void insert(const E & value)
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

		/*!
		 * inserts the given value.
		 * 
		 * \param value
		 */
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
		/*!
		 * removes the element at the root of the heap
		 * 
		 */
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
		/*!
		 * prints the heap to the given out stream
		 * 
		 * \param out
		 */
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
		/*!
		 * the array used to store values in the heap
		 * 
		 */
		std::vector<E> array;
		/*!
		 * the current number of elements in the heap
		 * 
		 */
		int size;
		/*!
		 * shifts elements in the tree after an element is removed
		 * 
		 * \param spot
		 */
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


#endif // MAXHEAP_H
