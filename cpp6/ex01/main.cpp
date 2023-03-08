#include "Data.hpp"
#include "Serializer.hpp"
#include <stdint.h>

int main() {
	Data *me = new Data("Theo", 20);
	uintptr_t raw = Serializer::serialize(me);
	Data *me_ptr = Serializer::deserialize(raw);

	std::cout << "original" << std::endl;
	std::cout << *me << std::endl;
	std::cout << "serialize, deserialize" << std::endl;
	std::cout << *me_ptr << std::endl
			  << std::endl;
	delete me;

	Data luke("Luke", 42);
	uintptr_t luke_raw = Serializer::serialize(&luke);
	Data luke_copy(*Serializer::deserialize(luke_raw));

	std::cout << "original" << std::endl;
	std::cout << luke << std::endl;
	std::cout << "serialize, deserialize, to a direct copy" << std::endl;
	std::cout << luke_copy << std::endl;
}
