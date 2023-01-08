#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP
#include <iterator>
#include "iterator_traits.hpp"

namespace ft {
	template <typename T>
	class random_access_iterator: public std::iterator<ft::random_access_iterator_tag, T> {
		public:
			random_access_iterator( void ): p(NULL) {}
			random_access_iterator(T* x): p(x) {}
			random_access_iterator(const random_access_iterator& mit): p(mit.p) {}
			~random_access_iterator( void ) {}

			bool operator==(const random_access_iterator& rhs) const {
				return (this->p == rhs.p);
			}

			bool operator!=(const random_access_iterator& rhs) const {
				return (this->p != rhs.p);
			}

			bool operator<(const random_access_iterator& rhs) const {
				return (this->p < rhs.p);
			}

			bool operator>(const random_access_iterator& rhs) const {
				return (this->p > rhs.p);
			}

			bool operator>=(const random_access_iterator& rhs) const {
				return (this->p >= rhs.p);
			}

			bool operator<=(const random_access_iterator& rhs) const {
				return (this->p <= rhs.p);
			}

			random_access_iterator& operator=( const T& rhs ) {
				if (this != rhs) {
					this->p = rhs.p;
				}
				return (*this);
			}

			random_access_iterator operator+( int n ) {
				return (*this + n);
			}

			random_access_iterator operator-( int n ) {
				return (*this - n);
			}

			random_access_iterator& operator++() {
				++p;
				return (*this);
			}

			random_access_iterator operator++(int) {
				random_access_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			random_access_iterator& operator--() {
				--p;
				return (*this);
			}

			random_access_iterator operator--(int) {
				random_access_iterator tmp(*this);
				operator--();
				return (tmp);
			}	

			T& operator*() {
				return (*p);
			}

			T* operator->() {
				return (p);
			}

			T& operator[]( size_t n ) {
				return (p[n]);
			}

		private:
			T* p;
	};
}


#endif