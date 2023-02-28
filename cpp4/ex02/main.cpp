#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

void ex01()
{
    const Animal *i = new Dog();
    const Animal *j = new Cat();

    delete j;
    delete i;

    Dog dog1;
    {
        Dog dog2(dog1);
    }

    Cat cat1;
    {
        Cat cat2(cat1);
    }


    Animal *animals[] = {new Dog(dog1), new Cat(cat1), new Dog(Dog()), new Cat()};
    for (size_t i = 0; i < sizeof(animals) / sizeof(animals[0]); i++) {
        delete animals[i];
    }
}

int main()
{
    Dog dog1;
    {
        Dog dog2(dog1);
    }

    Cat cat1;
    {
        Cat cat2(cat1);
    }

    //uncomment the line below this line to see that test can't be instanced by itself now
    //Animal test0;
    
    Animal *test1 = new Cat;
    test1->makeSound();
    delete test1;
	ex01();
    
	return 0;
}
