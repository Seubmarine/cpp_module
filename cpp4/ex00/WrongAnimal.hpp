#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal &from);
	WrongAnimal& operator=(const WrongAnimal &rhs);
	void makeSound() const;
	std::string getType() const;
};

#endif