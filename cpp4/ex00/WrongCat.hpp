#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(); //default constructor
	~WrongCat(); //destructor
	WrongCat& operator=(const WrongCat&); //copy assignement it replace the previous data
	WrongCat(const WrongCat&); //copy constructor
	void makeSound() const;
};

#endif