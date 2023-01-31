#ifndef STL_TREE_HPP
#define STL_TREE_HPP
#include <cstddef>
#include <string>
#include <iostream>
#include <alloca.h>
#include "stl_utility.hpp"
#include "stl_iterator.hpp"
#define BLACK 'b'
#define RED 'r'

#define COR "\033[31m";
#define RES "\033[0m";


namespace ft {
	template <typename Key, typename value_type>
	struct Rb_tree_node {
			typedef Rb_tree_node	Rb_node;
			Key				_key;
			value_type		_data;
			Rb_node*		parent;
			Rb_node*		left;
			Rb_node*		right;
			char			color;
	
			Rb_tree_node( void ): parent(this), left(this), right(this), color(BLACK) {};
			Rb_tree_node(
				const value_type& data,
				Rb_node* parent,
				Rb_node* left,
				Rb_node* right,
				char color = RED ): _data(data), parent(parent), left(left), right(right), color(color) {};

			Rb_tree_node *minimum(Rb_tree_node *x, Rb_tree_node *Nil) {
				while (x->left != Nil) {
					x = x->left;
				}
				return (x);
			}

			Rb_tree_node *maxinum(Rb_tree_node *x, Rb_tree_node *Nil) {
				while (x->right != Nil) {
					x = x->right;
				}
				return (x);
			}

			Rb_node* nextNode(Rb_node* x, Rb_node* Nil) {
				if (x->right != Nil)
				return minimum(x->right, Nil);
				Rb_node *y = x->parent;
				while (y != y->right && x == y->right) {
					x = y;
					y = y->parent;
				}
				return y;
			}
	};

	template <typename Key, typename T>
	class tree_iterator: public ft::iterator<ft::bidirectional_iterator_tag, T> {
		private:
			Rb_tree_node<Key, T>* p;
			Rb_tree_node<Key, T>* Nil;
			Rb_tree_node<Key, T> *tmp;
		public:

			tree_iterator( void ): p(NULL) {}
			explicit tree_iterator(Rb_tree_node<Key, T>* x, Rb_tree_node<Key, T>* y): p(x), Nil(y) {}
			// tree_iterator(const tree_iterator& src): p(src.p) {}
			T& operator*() const { return p->_data; }

			T* operator->() const { return &(operator*()); }

			tree_iterator& operator++() {
				p = p->nextNode(p, Nil);
				return (*this);
			}

			tree_iterator operator++(int) {
				tmp = p;
				p = p->nextNode(p, Nil);
				return (tree_iterator(tmp, Nil));
			}

			~tree_iterator( void ) {}
	};

	template <typename Key, typename value_type, typename Compare = std::less<Key>, typename Alloc = std::allocator<value_type> >
	class Rb_tree {
	public:
		typedef Alloc	allocator_type;
		typedef typename allocator_type::size_type			size_type;

		typedef Rb_tree_node<Key, value_type>				Rb_node;
		typedef typename std::allocator<Rb_node>			_node_allocator_type;
		typedef ft::tree_iterator<Key, value_type>			iterator;

		Rb_node*	root;
		Rb_node*	Nil;
		size_type	_size;

	public:
		Rb_tree( void ): root(NULL) {
			Nil = new Rb_node;
			root = Nil;
			_size = 0;
		}

		iterator find( const Key& k ) {
			Rb_node* tmp = root;
			while (tmp != Nil) {
				if (Compare()(k, tmp->_data.first)) {
					tmp = tmp->left;
				
				} else if (Compare()(tmp->_data.first, k)) {
					tmp = tmp->right;
				} else {
					break;
				}
			}
			return iterator(tmp, Nil);
		}

		iterator begin( void ) {
			return (iterator(root->minimum(root, Nil), Nil));
		};

		iterator end( void ) {
			return (iterator(Nil, Nil));
		}

		size_type size( void ) {
			return (_size);
		}
		void insert(value_type data) {
			Rb_node *y = Nil;
			Rb_node *x = root;

			Rb_node *z = _node_allocator.allocate(1);
			_node_allocator.construct(z, Rb_node(data, Nil, Nil, Nil));
			while (x != Nil) {
				y = x;
				if (Compare()(z->_data.first, x->_data.first)) {
					x = x->left;
				} else { x = x->right; };
			}
			z->parent = y;
			if (y == Nil) {
				root = z;
			} else if(Compare()(z->_data.first, y->_data.first)) {
				y->left = z;
			} else {
				y->right = z;
			}
			insertFixup(z);
			_size++;
		}

		void leftRotate(Rb_node *node) {
			Rb_node *tmp = node->right;
			node->right = tmp->left;
			if (tmp->left != Nil)
				tmp->left->parent = node;
			tmp->parent = node->parent;
			if (node->parent == Nil)
				root = tmp;
			else if (node == node->parent->left)
				node->parent->left = tmp;
			else
				node->parent->right = tmp;
			tmp->left = node;
				node->parent = tmp;
		}

		void rightRotate(Rb_node *node) {
			Rb_node *tmp = node->left;
			node->left = tmp->right;
			if (tmp->right != Nil)
				tmp->right->parent = node;
			tmp->parent = node->parent;
			if (node->parent == Nil)
				root = tmp;
			else if (node == node->parent->right)
				node->parent->right = tmp;
			else
				node->parent->left = tmp;
			tmp->right = node;
			node->parent = tmp;
		}

		void insertFixup(Rb_node *node) {
			while (node->parent->color == RED) {
				if (node->parent == node->parent->parent->left) {
					Rb_node *tmp = node->parent->parent->right;
					if (tmp->color == RED) {
						node->parent->color = BLACK;
						tmp->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					} else {
						if (node == node->parent->right) {
							node = node->parent;
							leftRotate(node);
						}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						rightRotate(node->parent->parent);
					}
				} else {
					Rb_node *tmp = node->parent->parent->left;
					if (tmp->color == RED) {
						node->parent->color = BLACK;
						tmp->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					} else {
						if (node == node->parent->left) {
							node = node->parent;
							rightRotate(node);
						}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						leftRotate(node->parent->parent);
					}
				}
			}
			root->color = BLACK;
		}

		// Rb_node *minimum(Rb_node *x) {
		// 	while (x->left != Nil) {
		// 		x = x->left;
		// 	}
		// 	return (x);
		// }

		void nodeDelete(Rb_node *node) {
			Rb_node *y = node;
			Rb_node *x;
			char y_originalcolor = y->color;
			if (node->left == Nil) {
				x = node->right;
				transplant(node, node->right);
			} else if (node->right == Nil) {
				x = node->left;
				transplant(node, node->left);
			} else {
				y = root->minimum(node->right, Nil);
				y_originalcolor = y->color;
				x = y->right;
				if (y->parent == node) {
					x->parent = y;
				} else {
					transplant(y, y->right);
					y->right = node->right;
					y->right->parent = y;
				}
				transplant(node, y);
				y->left = node->left;
				y->left->parent = y;
				y->color = node->color;
			}
			if (y_originalcolor == BLACK) {
				deleteFixUp(x);
			}
			_size--;
		}

		void transplant(Rb_node *u, Rb_node *v) {
			if (u->parent == Nil) {
				root = v;
			} else if (u == u->parent->left) {
				u->parent->left = v;
			} else {
				u->parent->right = v;
			}
			v->parent = u->parent;
		}

		void deleteFixUp(Rb_node *x) {
			Rb_node *w;
			while (x != root && x->color == BLACK) {
				if (x == x->parent->left) {
					w = x->parent->right;
					if (w->color == RED) {
						w->color = BLACK;
						x->parent->color = RED;
						leftRotate(x->parent);
						w = x->parent->right;
					}
					if (w->left->color == BLACK && w->right->color == BLACK) {
						w->color = RED;
						x = x->parent;
					} else {
						if (w->right->color == BLACK) {
							w->left->color = BLACK;
							w->color = RED;
							rightRotate(w);
							w = x->parent->right;
						}
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->right->color = BLACK;
						leftRotate(x->parent);
						x = root;
					}
				}
				else {
					w = x->parent->left;
					if (w->color == RED) {
						w->color = BLACK;
						x->parent->color = RED;
						rightRotate(x->parent);
						w = x->parent->left;
					}
					if (w->right->color == BLACK && w->left->color == BLACK) {
						w->color = RED;
						x = x->parent;
					} else {
						if (w->left->color == BLACK) {
							w->right->color = BLACK;
							w->color = RED;
							leftRotate(w);
							w = x->parent->left;
						}
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->left->color = BLACK;
						rightRotate(x->parent);
						x = root;
					}
				}
			}
			x->color = BLACK;
		}

		void printTree(Rb_node *root, int level, std::string side) {

			if (root == Nil)
				return;
			printTree(root->right, level + 1, "R");
			for (int i = 0; i < level; i++) {
				std::cout << "      ";
			}
			if (root->color == RED) {
				std::cout << COR;
			}
			std::cout << side << " " << root->_data.first << RES;
			std::cout << std::endl;
			printTree(root->left, level + 1, "L");
		}

		void printBT(void) {
			printTree(root, 0, "ROOT");
		}

		void nodeDestroy(Rb_node *node) {
			_node_allocator.destroy(node);
			_node_allocator.deallocate(node, 1);
		}

		void clear(Rb_node *node) {
			if (node == Nil)
				return ;
			clear(node->left);
			clear(node->right);
			nodeDestroy(node);
		}

		void printInOrder(Rb_node *node) {
			if (node == Nil)
				return;
			printInOrder(node->left);
			std::cout << node->_data.first << " ";
			printInOrder(node->right);
		}

		void clearTest(Rb_node *node) {
			while(root != root->parent) {
				nodeDelete(root);
			}
		}
		private:
			_node_allocator_type _node_allocator;

	};


}



#endif
