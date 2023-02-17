#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>
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
    return 0;
}
