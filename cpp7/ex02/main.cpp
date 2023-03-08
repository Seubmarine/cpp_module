#include "Array.hpp"
#include <iostream>
#include <stdlib.h> // srand
void mytest() {
	Array<int> test(10);
	
	std::cout << "Show original array test" << std::endl;
	for (size_t i = 0; i < test.size(); i++)
	{
		std::cout << test[i] << ' ';
	}
	std::cout << std::endl;

	std::cout << "modify array member using i * i" << std::endl;
	for (size_t i = 0; i < test.size(); i++)
	{
		test[i] = i * i;
		std::cout << test[i] << ' ';
	}
	std::cout << std::endl;

	std::cout << "Copy test as test2" << std::endl;
	std::cout << "modify test2 array member using test2[i] * test2[i]" << std::endl;
	Array<int> testcopy(test);
	for (size_t i = 0; i < testcopy.size(); i++)
	{
		testcopy[i] = testcopy[i] * testcopy[i];
		std::cout << testcopy[i] << ' ';
	}
	std::cout << std::endl;
	
	std::cout << "Show original array test to verify if any member was changed by modifying test2" << std::endl;
	for (size_t i = 0; i < test.size(); i++)
	{
		std::cout << test[i] << ' ';
	}
	std::cout << std::endl;


	std::cout << "An array of float" << std::endl;
	Array<float> testf(10);
	for (size_t i = 0; i < testf.size(); i++)
	{
		testf[i] = i * 0.1f;
		std::cout << testf[i] << ' ';
	}
	std::cout << std::endl;
}

void test_assign_and_empty_array() {
	Array<int> empty;
	for (size_t i = 0; i < empty.size(); i++)
	{
		std::cerr << "ERROR: SIZE OF EMPTY ARRAY SHOULD BE ZERO" << std::endl;
	}
	Array<int> nonempty(4);
	nonempty = empty;
	nonempty = Array<int>(5);
	nonempty = Array<int>(7);
}

#define MAX_VAL 750
int test_original()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int main(void)
{
	mytest();
	test_assign_and_empty_array();
	return test_original();
}
