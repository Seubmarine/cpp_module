#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

class NotFoundException : public std::exception {
	virtual const char* what() const throw() {return "NotFound";};
};

template<typename T>
int easyfind(T container, int to_find) {
	// for (size_t i = 0; i < container.size(); i++) {
	// 	if (container[i] == to_find)
	// 		return container[i];
	// }
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it != container.end())
		return *it;
	throw NotFoundException();
}

#endif