#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria() {
    this->type = "cure";
}

Cure::~Cure() {}

Cure::Cure(const Cure &rhs) : AMateria() {
    this->type = rhs.type;
}

Cure &Cure::operator=(const AMateria &rhs) {
    if (this != &rhs) {
        this->type = rhs.getType();
    }
    return *this;
}

AMateria *Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}