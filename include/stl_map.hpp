#ifndef STL_MAP_HPP
# define STL_MAP_HPP
#include "tests.hpp"
#include "stl_utility.hpp"
#include "stl_functional.hpp"
#include "stl_tree.hpp"

namespace ft {
	template <typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<ft::pair<const Key,T> > >
	class map {
		public:
			typedef Key	key_type;
			typedef T	mapped_type;
			typedef ft::pair<const Key, T>	value_type;
			typedef Compare					key_compare;
			typedef Alloc					allocator_type;
			typedef typename allocator_type::pointer		 pointer;
			typedef typename allocator_type::const_pointer	 const_pointer;
			typedef typename allocator_type::reference		 reference;
			typedef typename allocator_type::const_reference	 const_reference;
			
			typedef ft::Rb_tree<key_type, value_type, key_compare, allocator_type> Rb_tree_;



			explicit map (const key_compare& _comp = key_compare(),
			  const allocator_type& _alloc = allocator_type()) {
					
			};
			/*pair<iterator,bool>*/ void insert (const value_type& val) {
				_black.insert(val);
			}
			Rb_tree_ _black;
		private:
			key_compare _comp;
			allocator_type _alloc;
	};
}

#endif
