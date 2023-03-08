#include <vector>
#include <iostream>
#include "easyfind.hpp"

#define sizeof_array(x) (sizeof(x) / sizeof(x[0]))

template<typename T>
void print_if_found(T vec, int to_found) {
	try
	{
		std::cout << "found: " << easyfind(vec, to_found) << std::endl;
	}
	catch(const NotFoundException& e)
	{
		std::cout << "couldn't find: " << to_found << std::endl;
		
	}
}

void test_vec() {
	int tmp[] = {42, 26, 7, 8, 9, 1, 56, 7, 5};
	std::vector<int> vec(tmp, &tmp[sizeof_array(tmp)]);

	print_if_found(vec, 3);//error
	print_if_found(vec, 2);//error
	print_if_found(vec, 7);//okay
	print_if_found(vec, 5);//okay
	print_if_found(vec, 42);//okay
	
}

#include <list>
void test_list() {
	int tmp[] = {42, 26, 7, 8, 9, 1, 56, 7, 5};
	std::list<int> list(tmp, &tmp[sizeof_array(tmp)]);

	print_if_found(list, 3);//error
	print_if_found(list, 2);//error
	print_if_found(list, 7);//okay
	print_if_found(list, 5);//okay
	print_if_found(list, 42);//okay
	
}

int main()
{
	std::cout << "vector" <<std::endl;
	test_vec();
	std::cout << std::endl;
	std::cout << "list" <<std::endl;
	test_list();
	return 0;
}
