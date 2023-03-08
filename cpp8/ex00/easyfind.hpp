#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

class NotFoundException : public std::exception {};

template<typename T>
int easyfind(T container, int to_find) {
	// for (size_t i = 0; i < container.size(); i++) {
	// 	if (container[i] == to_find)
	// 		return container[i];
	// }
	for (typename T::iterator it=container.begin(); it != container.end(); ++it) {
		if (*it == to_find)
			return *it;
	}
	throw NotFoundException();
}

#endif