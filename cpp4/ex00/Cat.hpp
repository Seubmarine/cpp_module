#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(); //default constructor
	~Cat(); //destructor
	Cat& operator=(const Cat&); //copy assignement it replace the previous data
	Cat(const Cat&); //copy constructor
	void makeSound() const;
};

#endif