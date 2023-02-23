#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

void default_example() {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");
    
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
}

int main()
{
    // default_example();

    AMateria *mat_ice = new Ice();
    AMateria *mat_cure = new Cure();
    
    AMateria *mat_from = mat_ice;
    *mat_from = *mat_cure;

    ICharacter *tmp = new Character("Theo");

    tmp->equip(mat_from);
    tmp->use(0, *tmp);
    std::cout << mat_from->getType() << std::endl;
    delete mat_ice;
    delete mat_cure;
    delete tmp;
    return 0;
}
