#ifndef STL_ITERATOR_HPP
#define STL_ITERATOR_HPP
#include <iterator>
#include "stl_iterator_base_types.hpp"
#include <iostream>

namespace ft {
	template <typename Iterator>
	class reverse_iterator {
		protected:
			Iterator it;
			typedef std::iterator_traits<Iterator>				traits_type;

		public:
			typedef Iterator									iterator_type;
			typedef typename traits_type::value_type			value_type;
			typedef typename traits_type::difference_type		difference_type;
			typedef typename traits_type::pointer				pointer;
			typedef typename traits_type::reference				reference;
			typedef typename traits_type::iterator_category		iterator_category;

			reverse_iterator(void) : it(NULL) {};
			explicit reverse_iterator(iterator_type x) : it(x) {};
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> &x) : it(x.it) {}

			reverse_iterator operator+( difference_type n ) const {
				return (reverse_iterator(*this - n));
			}

			reverse_iterator operator-( difference_type n ) const {
				return (reverse_iterator(*this + n));
			}

			reverse_iterator& operator++() {
				--it;
				return (*this);
			}

			reverse_iterator operator++(int) {
				reverse_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			reverse_iterator &operator+=(difference_type n) {
				it -= n;
				return (*this);
			};

			reverse_iterator &operator-=(difference_type n) {
				it += n;
				return (*this);
			};

			reverse_iterator& operator--() {
				++it;
				return (*this);
			}

			reverse_iterator operator--(int) {
				reverse_iterator tmp(*this);
				operator--();
				return (tmp);
			}	

			reference operator*() const {
				Iterator tmp = it;
				return (*--tmp);
			}

			pointer operator->() const {
				return (&(operator*()));
			}

			reference operator[]( difference_type n ) const {
				return (*operator+(n));
			}

			iterator_type base() const {
				return (it);
			}
	};

	template <typename T>
	class normal_iterator: public ft::iterator<ft::random_access_iterator_tag, T> {
		protected:
			typedef ft::iterator_traits<T*>		traits_type;

		public:
			typedef typename traits_type::value_type			value_type;
			typedef typename traits_type::difference_type		difference_type;
			typedef typename traits_type::pointer				pointer;
			typedef typename traits_type::reference				reference;
			typedef typename traits_type::iterator_category		iterator_category;
		
			normal_iterator( void ): p(NULL) {}
			explicit normal_iterator(T* x): p(x) {}
			normal_iterator(const normal_iterator& src): p(src.p) {}
			~normal_iterator( void ) {}

			bool operator==(const normal_iterator& rhs) const {
				return (this->p == rhs.p);
			}

			bool operator!=(const normal_iterator& rhs) const {
				return (this->p != rhs.p);
			}

			bool operator<(const normal_iterator& rhs) const {
				return (this->p < rhs.p);
			}

			bool operator>(const normal_iterator& rhs) const {
				return (this->p > rhs.p);
			}

			bool operator>=(const normal_iterator& rhs) const {
				return (this->p >= rhs.p);
			}

			bool operator<=(const normal_iterator& rhs) const {
				return (this->p <= rhs.p);
			}
			normal_iterator &operator+=(int const rhs) {
			this->p += rhs;
			return (*this);
			};
			normal_iterator &operator-=(int const rhs) {
			this->p -= rhs;
			return (*this);
			};
			normal_iterator& operator=( const T& rhs ) {
				if (this != rhs) {
					this->p = rhs.p;
				}
				return (*this);
			}

			normal_iterator operator+( difference_type n ) const {
				return (normal_iterator(this->p + n));
			}

			normal_iterator operator-( difference_type n ) const {
				return (normal_iterator(this->p - n));
			}

			normal_iterator& operator++() {
				++p;
				return (*this);
			}

			normal_iterator operator++(int) {
				normal_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			normal_iterator& operator--() {
				--p;
				return (*this);
			}

			normal_iterator operator--(int) {
				normal_iterator tmp(*this);
				operator--();
				return (tmp);
			}	

			reference operator*() const {
				return (*p);
			}

			pointer operator->() const {
				return (p);
			}

			reference operator[]( difference_type n ) const {
				return (p[n]);
			}

		private:
			pointer p;
	};
	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last) {
		typename std::iterator_traits<InputIterator>::difference_type i = 0;
		for (; first != last; i++, first++) {};
		return (i); 
	}
}


#endif
