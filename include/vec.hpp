#ifndef VEC_HPP
#define VEC_HPP
#include <vector>

class Vec {
	public:
		Vec( void ) {};

		~Vec( void ) {};

		std::vector<int> addSequence( int n ) {
			std::vector<int> vec;
			for (int i = 0; i < n; i++) {
				vec.push_back(i);
			}
			return vec;
	}
};

#endif
