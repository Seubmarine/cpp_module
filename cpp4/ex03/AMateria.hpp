#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
    std::string type;
public:
    AMateria(std::string const &type);

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
    AMateria();
    virtual ~AMateria();
    AMateria(const AMateria &rhs);
    AMateria &operator=(const AMateria &rhs);
};

#endif