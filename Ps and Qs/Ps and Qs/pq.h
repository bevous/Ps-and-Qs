#ifndef PQ_H
#define PQ_H

namespace nwacc
{
#include "maxheap.h"
	template <typename T>
	class pq
	{
	private:
		nwacc::max_heap<T> my_max_heap;
	public:
		/*!
		 * sets the starting size of the priority que
		 * 
		 * \param size
		 */
		pq()
		{
			
		}
		/*!
		 * the default size of the pq
		 *
		 */
		static const int kdefaultsize = 50;
		/*!
		 * checks if the heap is empty
		 *
		 * \return bool
		 */
		bool is_empty() const
		{
			return this->my_max_heap.is_empty();
		}
		/*!
		 * prints the contents of the heap to the given ostream
		 *
		 * \param out
		 */
		void print(std::ostream & out = std::cout) const
		{

			this->my_max_heap.print(out);
		}

		/*!
		 * inserts an element into the heap
		 *
		 * \param value
		 */
		void offer(T &value)
		{
			this->my_max_heap.insert(value);
		}
		/*!
		 * inserts an element into the heap
		 *
		 * \param value
		 */
		void offer(T &&value)
		{
			this->my_max_heap.insert(value);
		}
		/*!
		 * gets the head of the heap without removing it
		 *
		 * \return T
		 */
		T peak() const
		{
			return this->my_max_heap.is_empty() ? NULL : this->my_max_heap.get_max();
		}
		/*!
		 * gets and removes the head of the heap
		 *
		 * \return T
		 */
		T poll()
		{
			return this->my_max_heap.is_empty() ? NULL : this->my_max_heap.remove();
		}
		/*!
		 * gets the number of elements in the heap
		 *
		 * \return int
		 */
		int size() const
		{
			return this->my_max_heap.my_size;
		}
		/*!
		 * removes all elements from the heap
		 *
		 */
		void clear()
		{
			this->my_max_heap.clear();
		}

	};
}

#endif PQ_H
