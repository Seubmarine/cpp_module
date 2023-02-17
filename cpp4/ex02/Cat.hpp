#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
private:
	Brain *brain;
public:
	Cat(); //default constructor
	~Cat(); //destructor
	Cat& operator=(const Cat &rhs); //copy assignement it replace the previous data
	Cat(const Cat &rhs); //copy constructor
	void makeSound() const;
};

#endif