#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : virtual public ICharacter
{
private:
    static const size_t inventory_size = 4;
    AMateria *inventory[inventory_size];
    std::string name;
    bool isInventoryIndexValid(int idx, const char *function_caller_name) const; //helper function
public:
    Character();
    ~Character();
    Character(const Character &rhs);
    Character &operator=(const Character &rhs);
    Character(std::string name);
    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif