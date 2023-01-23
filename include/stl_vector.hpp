#ifndef STL_pECTOR_HPP
#define STL_pECTOR_HPP
#include <stdexcept>
#include <alloca.h>
#include "stl_iterator.hpp"
#include "stl_iterator_base_types.hpp"
#include "type_traits.hpp"
#include "stl_algorithm.hpp"
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

			explicit vector(
				const allocator_type& alloc = allocator_type() ):
					p(NULL), _alloc(alloc), _size(0),_capacity(0) {};

			explicit vector(
				size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
					_alloc(alloc), _size(n), _capacity(n) {
				p = this->_alloc.allocate(n);
				while (n--) {
					this->_alloc.construct(&p[n], val);
				}
			};

			vector(const vector& x): _size(x._size), _capacity(x._capacity) {
				p = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i)
					_alloc.construct(&p[i], x.p[i]);
			};

			template <typename InputIterator>
			vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type()): _alloc(alloc) {
				size_type i = 0;

				for (InputIterator it = first; it != last; i++) {
					it++;
				}
				_size = i;
				_capacity = i;
				p = _alloc.allocate(i);
				for (size_type j = 0; first != last; j++) {
					_alloc.construct(&p[j], *first);
					first++;
				}
			}

			vector& operator=(const vector& x) {
				p = _alloc.allocate(x._capacity);
				for (size_type i = 0; i < x._size; ++i) {
					_alloc.construct(&x.p[i], x.p[i]);
				}
			};

			~vector( void ) {
				this->clear();
				_alloc.deallocate(p, this->capacity());
			};

			iterator begin() {return (iterator(p));};
			const_iterator begin() const {return (const_iterator(p));};
	
			iterator end() {return (empty() ? begin() : iterator(p + _size));};
			const_iterator end() const {return (empty() ? begin() : const_iterator(p + _size));};
	
			reverse_iterator rbegin() {return (reverse_iterator(this->end()));};
			const_reverse_iterator rbegin() const {return (const_reverse_iterator(this->end()));};

			reverse_iterator rend() {return (reverse_iterator(this->begin()));};
			const_reverse_iterator rend() const {return const_reverse_iterator(this->begin());};

			size_type size() const {return (_size);};
			size_type max_size() const {return (_alloc.max_size());};
			void resize(size_type n, value_type val = value_type()) {
				if (n < _size) {
					for (size_type i = 0; n + i < _size ; i++) {
						_alloc.destroy(&p[n + i]);
					}
				}
				else {
					for (size_type i = 0, j = _size; j + i < n; i++) {
						push_back(val);
					}
				}
				_size = n;
			};
			size_type capacity() const {return (_capacity);};
			bool empty() const {return (_size == 0);};
		
			void reserve (size_type n) {
				if (n <= _capacity) {
					return ;
				}
				value_type *tmp;

				_capacity = n;
				tmp = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(&tmp[i], p[i]);
					_alloc.destroy(&p[i]);
				}
				_alloc.deallocate(p, this->capacity());
				p = tmp;
			};

			reference operator[] (size_type n){return (p[n]);};
			const_reference operator[] (size_type n) const {
				return (p[n]);
			};
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
			const_reference back() const { return (*(end() - 1));};

		template <class InputIterator>
		void assign (
			InputIterator first,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, 
			InputIterator>::type last) {
			size_type n = ft::distance(first, last);

			reserve(n);
			for (size_type i = 0; i < _size; i++) {
				_alloc.destroy(&p[i]);
				if (i < n)
					_alloc.construct(&p[i], *first++);
			}
			for (size_type i = 0; i + _size < n; i++)
				_alloc.construct(&p[i + _size], *first++);
			_size = n;
		};
	
		void assign(size_type n, const value_type& val) {
			reserve(n);
			for (size_type i = 0; i < _size; i++) {
				_alloc.destroy(&p[i]);
				if (i < n)
					_alloc.construct(&p[i], val);
			}
			for (size_type i = 0; i + _size < n; i++)
				_alloc.construct(&p[i + _size], val);
			_size = n;
		};

		void push_back(const value_type& val) {
			if (_size == this->_capacity) {
				reserve(this->_capacity > 0 ? this->_capacity << 1 : 1);
			}
			_alloc.construct(&p[_size], val);
			_size++;
		};

		void pop_back() {
			if (_size > 0) {
				_alloc.destroy(&p[_size - 1]);
				_size--;
			}
		};

		iterator insert(iterator position, const value_type& val) {
			size_type distance = ft::distance(begin(), position);
			if (_capacity == 0) {
				push_back(val);
				return (begin());
			}
			value_type *tmp;

			if (_capacity <= _size) {
				_capacity = _capacity << 1;
			}
			tmp = _alloc.allocate(_capacity);
			for (size_type i = 0; i < distance; i++) {
				_alloc.construct(&tmp[i], p[i]);
				_alloc.destroy(&p[i]);
			}
			_alloc.construct(&tmp[distance], val);
			for (size_type i = distance + 1; i < _size + 1 ; i++) {
				_alloc.construct(&tmp[i], p[i - 1]);
				_alloc.destroy(&p[i - 1]);
			}
			_alloc.deallocate(p, _size);
			_size++;
			p = tmp;
			return(iterator(p + distance));
		}

		void insert(iterator position, size_type n, const value_type& val) {
			if (_capacity  == 0 && n != 1) {
				reserve(n);
				position = begin();
			}
			for(size_type i = 0; i < n; i++)
				position = insert(position, val);
		};

		template <class InputIterator>
		void insert(iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
				difference_type n = ft::distance(first, last);
				if (_capacity  == 0 && n != 1) {
					reserve(n);
					position = begin();
				}
				for (; first != last; first++) {
					position = insert(position, *first);
					position++;
			   }
		}
		iterator erase(iterator position) {
			if (position == end() && !empty()) {
				position--;
			}
			_alloc.destroy(&*position);
			for (iterator it = position; it != end() - 1; it++) {
				*it = *(it + 1);
			}
			_size--;
			return (position);
		};

		iterator erase(iterator first, iterator last) {
			;
			for (difference_type i = ft::distance(first, last); i > 0; i--) {
				first = erase(first);
			}
			return (first);
		};

		void swap(vector& x) {
			value_type *tmp = p;
			size_type tmp_size = _size;
			size_type tmp_capacity = _capacity;

			p = x.p;
			_size = x._size;
			_capacity = x._capacity;
			x.p = tmp;
			x._size = tmp_size;
			x._capacity = tmp_capacity;
		};

		void clear() {
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&p[i]);
			_size = 0;
		};
		allocator_type get_allocator() const {return (_alloc);};
	private:
		T *p;
		allocator_type _alloc;
		size_type _size;
		size_type _capacity;
	};

	template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));}
	template <class T, class Alloc> bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {return (!(lhs == rhs));}

	template <class T, class Alloc> bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}
	template <class T, class Alloc> bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {return (rhs < lhs);}
	template <class T, class Alloc> bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {return (!(rhs < lhs));}
	template <class T, class Alloc> bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {return (!(lhs < rhs));}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {x.swap(y);}
}


#endif
