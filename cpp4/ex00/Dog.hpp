#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
public:
	Dog(); //default constructor
	~Dog(); //destructor
	Dog& operator=(const Dog&); //copy assignement it replace the previous data
	Dog(const Dog&); //copy constructor
	void makeSound() const;
};

#endif