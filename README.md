# Standard Containers
> A container is a holder object that stores a collection of other objects (its elements). They are implemented as class templates, which allows a great flexibility in the types supported as elements.

> The container manages the storage space for its elements and provides member functions to access them, either directly or through iterators (reference objects with similar properties to pointers).

## Vector
> Vectors are sequence containers representing arrays that can change in size.

> Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.

> Internally, vectors use a dynamically allocated array to store their elements. This array may need to be reallocated in order to grow in size when new elements are inserted, which implies allocating a new array and moving all elements to it. This is a relatively expensive task in terms of processing time, and thus, vectors do not reallocate each time an element is added to the container.

> Instead, vector containers may allocate some extra storage to accommodate for possible growth, and thus the container may have an actual capacity greater than the storage strictly needed to contain its elements (i.e., its size). Libraries can implement different strategies for growth to balance between memory usage and reallocations, but in any case, reallocations should only happen at logarithmically growing intervals of size so that the insertion of individual elements at the end of the vector can be provided with amortized constant time complexity (see push_back).

# Iterator

> An iterator is any object that, pointing to some element in a range of elements (such as an array or a container)

> The most obvious form of iterator is a pointer, But other kinds of iterators are possible.

> Not all iterators have the same functionality, Depending on the properties supported by iterators, they are classified into five different categories:

> Input and output iterators are the most limited types of iterators: they can perform sequential single-pass input or output operations.

> Forward iterators have all the functionality of input iterators and -if they are not constant iterators- also the functionality of output iterators, although they are limited to one direction in which to iterate through a range (forward). All standard containers support at least forward iterator types.

> Bidirectional iterators are like forward iterators but can also be iterated through backwards.

> Random-access iterators implement all the functionality of bidirectional iterators, and also have the ability to access ranges non-sequentially: distant elements can be accessed directly by applying an offset value to an iterator without iterating through all the elements in between. These iterators have a similar functionality to standard pointers (pointers are iterators of this category).

# STL Iterator Categories

> A precise classification of iterators into five categories is the basis for determining which algorithms can be used with which containers  
> Iterators are classified into five categories:

|iterator tag	Category | of iterators |
|--|--|
|input_iterator_tag |	Input Iterator |
|output_iterator_tag |	Output Iterator |
|forward_iterator_tag |	Forward Iterator |
|bidirectional_iterator_tag |	Bidirectional Iterator |
|random_access_iterator_tag |	Random-access Iterator |

# Iterator base class  

> This is a base class template that can be used to derive iterator classes from it

> This base class only provides some member types, which in fact are not required to be present in any iterator type

```c++
template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
};
```
# Iterator traits

> Traits class defining properties of iterators.

```c++
template <typename Iterator>
struct iterator_traits {
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
	typedef typename Iterator::iterator_category iterator_category;
};

template <typename T>
struct iterator_traits<T*> {
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef random_access_iterator_tag iterator_category;
};

template <typename T>
struct iterator_traits<const T*> {
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef const T* pointer;
	typedef const T& reference;
	typedef random_access_iterator_tag iterator_category;
};
```
