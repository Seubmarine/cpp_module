#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public virtual AMateria
{
public:
    Cure ();
    ~Cure ();
    Cure(const Cure &rhs);
    Cure &operator=(const AMateria &rhs);
    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif