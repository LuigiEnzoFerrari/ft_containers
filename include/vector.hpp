#ifndef VEC_HPP
#define VEC_HPP
#include <alloca.h>
#include <iterator>
#include <bits/c++config.h>
#include "random_access_iterator.hpp"
#include "iterator_traits.hpp"

namespace ft {
	template < typename T, typename Alloc = std::allocator<T>>
	class vector {

		public:
			typedef T		value_type;
			typedef Alloc	allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef ft::random_access_iterator<value_type> iterator;
			// typedef ft::random_access_iterator<value_type> iterator;
			// typedef ft::reverse_iterator reverse_iterator<iterator> reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef size_t	size_type;

			explicit vector( const allocator_type& alloc = allocator_type() ) {};

			explicit vector(  size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {};

			template <typename InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {};

			vector (const vector& x) {};
			
			~vector( void ) {};
			
			iterator begin() {
				iterator one(p);
				return(NULL);
			}
			
			int returnminustwo( int n ) {
				return n - 2;
			}
			private:
				pointer p;
	};

}

#endif
