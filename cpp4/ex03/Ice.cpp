#include "Ice.hpp"
#include <string>

Ice::Ice() {
    this->type = "ice";
}

Ice::~Ice() {}

Ice::Ice(const Ice &rhs) : AMateria() {
    *this = rhs;
}

Ice &Ice::operator=(const Ice &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}