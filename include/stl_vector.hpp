#ifndef STL_VECTOR_HPP
#define STL_VECTOR_HPP
#include <stdexcept>
#include <alloca.h>
#include <iterator>
#include "stl_iterator.hpp"
#include "stl_iterator_base_types.hpp"
#include "type_traits.hpp"
#include <vector>
#include <iostream>

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

			explicit vector( const allocator_type& alloc = allocator_type() ): _alloc(alloc), _size(0),_capacity(0) {};

			explicit vector(  size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _size(n) {
				p = this->_alloc.allocate(n);
				while (n--) {
					this->_alloc.construct(&p[n], val);
				}
			};

			template <typename InputIterator>
			vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type()): _alloc(alloc) {
				size_type i = 0;
				for (InputIterator it = first; it != last; i++) {
					it++;
				}
				_size = i;
				_capacity = i;
				p= _alloc.allocate(i);
				for (size_type j = 0; first != last; j++) {
					_alloc.construct(&p[j], *first);
					first++;
				}
			}

			vector(const vector& x);
			~vector() {
				_alloc.destroy(p);
				_alloc.deallocate(p, _size);
			};
			// iterators
			iterator begin() {return (iterator(p));};
			const_iterator begin() const {return (const_iterator(p));};
			iterator end() {return (empty() ? begin() : iterator(p + _size));};
			const_iterator end() const {return (empty() ? begin() : iterator(p+ _size));};
			reverse_iterator rbegin() {return (reverse_iterator(iterator(p+ (_size - 1))));};
			const_reverse_iterator rbegin() const {return (const_reverse_iterator(p+ (_size - 1)));};
			reverse_iterator rend() {return (reverse_iterator(iterator(p)));};
			const_reverse_iterator rend() const {return const_reverse_iterator(iterator(p));};
			// capacity
			size_type size() const {return (_size);};
			size_type max_size() const {return (_alloc.max_size());};
			void resize(size_type n, value_type val = value_type()) {
				if (n < _size) {
				for (size_type i = 0; n + i < _size ; i++)
					_alloc.destroy(&p[n + i]);
				} else {
				for (size_type i = 0, j = _size; j + i < n; i++)
					push_back(val);
				}
				_size = n;
			};
			size_type capacity() const {return (_capacity);};
			bool empty() const {return (_size == 0);};
			void reserve (size_type n) {
				if (n > _capacity) {
					value_type *new_v;
					_capacity = n;
					new_v = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
					_alloc.construct(&new_v[i], p[i]);
					this->~vector();
					p = new_v;
				}
			};

			// element access
			reference operator[] (size_type n){return (p[n]);};
			const_reference operator[] (size_type n) const {{return (p[n]);}};
			reference at (size_type n) {
				if (n >= this->size()) {
					throw std::out_of_range("this->size() <= n");
				}
				return (p[n]);
			};
			const_reference at (size_type n) const {
				if (n >= this->size()) {
					throw std::out_of_range("this->size() <= n");
				}
				return (p[n]);
			};
			reference front() {
				return (*p);
			};
			const_reference front() const {
				return (*p);
			};
			reference back() { return (*(end() - 1));};
			const_reference back() const;

			template <typename InputIterator>
			void assign (InputIterator first,  typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
				size_type n = ft::distance(first, last);
				reserve(n);
				for (size_type i = 0; i < this->_size; i++) {
					this->_alloc.destroy(&p[i]);
					if (i < n) {
						this->_alloc.construct(&p[i], *first++);
					}
				}
				for (size_type i = 0; i + this->_size < n; i++) {
					this->_alloc.construct(&p[i + this->_size], *first++);
				}
				this->_size = n - 1;
			};

			void assign(size_type n, const value_type& val) {
				reserve(n);
				for (size_type i = 0; i < this->_size; i++) {
					this->_alloc.destroy(&p[i]);
					if (i < n) {
						this->_alloc.construct(&p[i], val);
					}
				}
				for (size_type i = 0; i + this->_size < n; i++) {
					this->_alloc.construct(&p[i + this->_size], val);
				}
				this->_size = n;
			};

			void push_back(const value_type& val) {
				if (this->_size == _capacity) {
					reserve(_capacity * 2);
					this->_alloc.construct(&p[this->_size], val);
				} else
					this->_alloc.construct(&p[this->_size], val);
				this->_size++;
			};
			void pop_back() {
				if (this->_size > 0) {
				this->_alloc.destroy(&p[this->_size]);
				this->_size--;
				}
			};

			iterator insert(iterator position, const value_type& val) {
				size_type i = 0;
				for (iterator it = begin(); it != position; it++)
				i++;
				if (this->_size == _capacity) {
				reserve(_capacity * 2);
				position = iterator(&p[i]);
				}
				for (iterator it = end(); position != it; it--)
				*it = *(it - 1);
				*position = val;
				this->_size++;
				return (position);
			}
			void insert(iterator position, size_type n, const value_type& val) {
				for(size_type i = 0; i < n; i++)
					position = insert(position, val);
			};
			template <class InputIterator>
			void insert (iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
				size_type first_position = 0, last_position = 0;
				for (iterator it = begin(); it != last; it++) {
					if (it == first)
						first_position = last_position;
					last_position++;
				}
				for (size_type gap = last_position - first_position; gap; gap--) {
					position = insert(position, *(begin() + first_position));
					first_position += 2;
				}
			}

			iterator erase(iterator position);
			iterator erase(iterator first, iterator last);
			void swap(vector& x);
			void clear();

			// allocator
			allocator_type get_allocator() const;
			private:
				T* p;
				allocator_type _alloc;
				size_type _size;
				size_type _capacity;
	};

}

#endif
