#ifndef STL_VECTOR_HPP
#define STL_VECTOR_HPP
#include <alloca.h>
#include <iterator>
#include "stl_iterator.hpp"
#include "stl_iterator_base_types.hpp"
#include "type_tratis.hpp"
#include <vector>

namespace ft {
	template < typename T, typename Alloc = std::allocator<T> >
	class vector {

		public:
			typedef T		value_type;
			typedef Alloc	allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef ft::normal_iterator<value_type> iterator;
			typedef ft::normal_iterator<const value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef size_t	size_type;

			explicit vector( const allocator_type& alloc = allocator_type() ): _size(0), _capacity(0), _alloc(alloc) {};

			explicit vector(  size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
			_size(n), _alloc(alloc) {
				p = this->_alloc.allocate(n);
				while (n--) {
					this->_alloc.construct(&p[n], val);
				}
			};

			template <typename InputIterator>
			vector (
				InputIterator first,
				typename ft::enable_if<!(ft::is_integral<InputIterator>::value), T>::type last,
				const allocator_type& alloc = allocator_type()) {
			};

			vector (const vector& x) {};
			
			~vector( void ) {
				this->_alloc.destroy(p);
        		this->_alloc.deallocate(p, _size);
			};

			vector& operator= (const vector& x) { return (*this); };

			reference operator[] (size_type n) {
				return (p[n]);
			};
			// const_reference operator[] (size_type n) const;
			//Iterators:
			iterator begin() { return (iterator(p)); };
			const_iterator begin() const {};

			iterator end() { return (iterator(p + (this->_size - 1)));};
			const_iterator end() const {};

			reverse_iterator rbegin() {};
			const_reverse_iterator rbegin() const {};

			reverse_iterator rend() {};
			const_reverse_iterator rend() const {};

			// Capacity
			size_type size() const { return (this->_size); };
			size_type max_size() const { return (this->_alloc.max_size()); };
			void resize (size_type n, value_type val = value_type()) {};
			size_type capacity() const { return (this->_capacity); };
			bool empty() const { return (this->_size == 0);};
			void reserve (size_type n) {};

			private:
				T* p;
				allocator_type _alloc;
				size_type _size;
				size_type _capacity;
	};

}

#endif
