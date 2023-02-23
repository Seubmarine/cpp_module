#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : virtual public AMateria
{
public:
    Ice();
    ~Ice();
    Ice(const Ice &rhs);
    Ice &operator=(const Ice &rhs);
    virtual AMateria* clone() const;
    virtual void use(ICharacter &target);
};

#endif