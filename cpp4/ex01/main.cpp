#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>
int main()
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
    
    return 0;
}
