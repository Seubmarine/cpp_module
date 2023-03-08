#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <stdlib.h> /* srand, rand*/
#include <time.h> /* time */
#include <iostream>

Base *generate(void) {
	switch (rand() % 3) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return (NULL);
}

void identify(Base *p) {
	std::cout << "identified class *: ";
	A *a = dynamic_cast<A *>(p);
	if (a != NULL) {
		std::cout << "A" << std::endl;
		return;
	}

	B *b = dynamic_cast<B *>(p);
	if (b != NULL) {
		std::cout << "B" << std::endl;
		return;
	}

	C *c = dynamic_cast<C *>(p);
	if (c != NULL) {
		std::cout << "C" << std::endl;
		return;
	}
	std::cout << "ERROR" << std::endl;
}

void identify(Base &p) {
	std::cout << "identified class &: ";
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	} catch (const std::exception &e) {
	}

	try {
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	} catch (const std::exception &e) {
	}

	try {
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	} catch (const std::exception &e) {
	}
	std::cout << "ERROR" << std::endl;
}

int main() {
	srand(time(NULL));

	for (size_t i = 0; i < 10; i++) {
		Base *tmp = generate();
		identify(tmp);
		identify(*tmp);
		std::cout << std::endl;
		delete tmp;
	}

	return 0;
}
