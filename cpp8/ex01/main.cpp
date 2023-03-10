#include "Span.hpp"
#include <iostream>

void test_original() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test_addnumber_iterator() {
	Span sp = Span(5);
	int tmp[] = {6, 3, 17, 9, 11};
	sp.addNumbers(tmp, &tmp[5]);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main()
{
	test_original();
	test_addnumber_iterator();
	return 0;
}