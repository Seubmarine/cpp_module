#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal
{
protected:
	std::string type;
public:
	Animal(); //default constructor
	virtual ~Animal(); //destructor
	Animal& operator=(const Animal&); //copy assignement it replace the previous data
	Animal(const Animal&); //copy constructor
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif