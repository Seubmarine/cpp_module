#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>


template<typename T> void iter(T *array, std::size_t array_size, void (*f)(T &element)) {
	for (size_t i = 0; i < array_size; i++)
	{
		f(array[i]);
	}
}

#endif