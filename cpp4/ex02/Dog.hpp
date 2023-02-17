#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;
public:
	Dog(); //default constructor
	~Dog(); //destructor
	Dog& operator=(const Dog&); //copy assignement it replace the previous data
	Dog(const Dog&); //copy constructor
	void makeSound() const;
};

#endif