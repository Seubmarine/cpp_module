#include "Span.hpp"
#include <iostream>

#define array_sizeof(x) (sizeof(x) / sizeof(x[0]))

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

void test_negative() {
	int tmp[] = {-5, -10, -25, -18, 1};
	Span sp = Span(array_sizeof(tmp));
	sp.addNumbers(tmp, tmp + array_sizeof(tmp));
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test_exception() {
	try
	{
		Span sp(4);
		for (size_t i = 0; i < 10; i++)
		{
			sp.addNumber(0);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span sp(4);
		sp.addNumber(42);
		sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span sp(4);
		sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	std::cout << "test original" << std::endl;
	test_original();
	std::cout << "test iter" << std::endl;
	test_addnumber_iterator();
	std::cout << "test negative" << std::endl;
	test_negative();
	std::cout << "test exception" << std::endl;
	test_exception();
	return 0;
}