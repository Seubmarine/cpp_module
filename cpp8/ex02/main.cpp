#include "MutantStack.hpp"
#include <iostream>
#include <stack>

void test_original() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.pop();
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.push(21);
	mstack.push(3);
	mstack.pop();
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "top: " << mstack.top() << std::endl;
	std::stack<int> s(mstack);
	MutantStack<int> c(mstack);
	mstack.pop();
	mstack.pop();

	std::cout << "print copy after two pop or original" << std::endl;
	it = c.begin();
	ite = c.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "size: " << c.size() << std::endl;
	std::cout << "isempty: " << c.empty() << std::endl;
	std::cout << "isempty after " << c.size() << " pop: " << std::endl;
	size_t c_size = c.size();
	for (size_t i = 0; i < c_size; i++)
	{
		c.pop();
	}
	std::cout << c.empty() << std::endl;
	

}

int main() {
	test_original();
	return 0;
}