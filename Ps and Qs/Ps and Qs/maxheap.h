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
		 * sets the size of the heap
		 *
		 * \param capacity
		 */
		max_heap(int capacity = kDefaultSize) : array(capacity + 1), my_size{ 0 } {}
		/*!
		 * the default size of the heap
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
			return this->my_size == 0;
		}
		/*!
		 * prints the contents of the heap to the given ostream
		 *
		 * \param out
		 */
		void print(std::ostream & out = std::cout) const
		{

			for (auto value = 0; value < this->my_size; value++)
			{
				out << this->array[value] << ",";
				out << this->array[(2 * value) + 1] << ",";
				out << this->array[(2 * value) + 2] << std::endl;
			}

			/*auto index = 0;
			while (index < this->my_size)
			{
				out << this->array[index] << " ";
				index++;
			}
			out << std::endl;*/
		}

		/*!
		 * gets the largest element in the heap
		 *
		 * \return E
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
		 * inserts the given value into the heap
		 *
		 * \param value
		 */
		void insert(const E & value)
		{
			if (this->my_size == this->array.size() - 1)
			{
				this->array.resize(this->array.size() * 2);
			}

			// Percolate up
			++this->my_size;
			int hole = this->my_size - 1;
			this->array[hole] = std::move(value);

			for (; hole > 0 && this->array[(hole - 1) / 2] < this->array[hole]; hole = (hole - 1) / 2)
			{
				std::swap(this->array[hole], this->array[(hole - 1) / 2]);
			}

		}

		/*!
		 * inserts the given value into the heap
		 *
		 * \param value
		 */
		void insert(E && value)
		{
			// we want to see if I have room. 
			if (this->my_size == this->array.size() - 1)
			{
				this->array.resize(this->array.size() * 2);
			} // else, we have space, do_nothing();
			// Percolate up
			++this->my_size;
			int hole = this->my_size - 1;
			this->array[hole] = std::move(value);

			for (; hole > 0 && this->array[(hole - 1) / 2] < this->array[hole]; hole = (hole - 1) / 2)
			{
				std::swap(this->array[hole], this->array[(hole - 1) / 2]);
			}

		}
		/*!
		 * removes the element at the root
		 *
		 */
		E remove()
		{
			E temp = this->get_max();
			if (this->is_empty())
			{
				throw std::out_of_range("Heap is empty");
			}
			else
			{
				this->array[0] = std::move(this->array[this->my_size--]);
				this->percolate_down(0);
			}
			return temp;
		}
		/*!
		 * gets the number of elements in the heap
		 * 
		 * \return int
		 */
		int size() const
		{
			return this->my_size;
		}
		/*!
		 * removes all elements from the heap
		 * 
		 */
		void clear()
		{
			while (!this->is_empty())
			{
				this.remove();
			}
		}
	private:
		/*!
		 * the array used for the heap
		 * 
		 */
		std::vector<E> array;
		/*!
		 * the number of elements in the heap
		 * 
		 */
		unsigned int my_size;
		
		/*!
		 * moves elements in the heap to ensure the rules of the heap are followed
		 * 
		 * \param spot
		 */
		void percolate_down(int spot)
		{
			auto temp = std::move(this->array[spot]);
			auto child = 0;
			auto is_done = false;

			while (!is_done && spot * 2 <= this->my_size)
			{
				child = (spot *2) +1;
				if (child != this->my_size && this->array[child + 1] > this->array[child])
				{
					child++;
				}

				if (this->array[child] > temp)
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
