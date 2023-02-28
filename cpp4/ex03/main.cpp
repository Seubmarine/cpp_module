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

	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
    delete bob;
    delete me;
    delete src;
}

int main()
{
    default_example();

    AMateria *mat_ice = new Ice();
    AMateria *mat_cure = new Cure();
    *mat_cure = *mat_ice;

	Character *ptr_hero = new Character("Theo");
    ICharacter *hero = ptr_hero;
	hero->equip(mat_ice);
	hero->equip(mat_cure);

	ICharacter *danpleganger = new Character(*ptr_hero);

	hero->use(0, *danpleganger);
	hero->use(1, *danpleganger);

	delete mat_cure;
    delete mat_ice;
	delete hero;

	danpleganger->unequip(0);
	danpleganger->unequip(1);
	danpleganger->unequip(2);
	danpleganger->unequip(3);
	delete danpleganger;
    return 0;
}
