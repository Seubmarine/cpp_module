#include "Character.hpp"

Character::Character() {
    for (size_t i = 0; i < inventory_size; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(const Character &rhs) : name(rhs.name) {
    for (size_t i = 0; i < inventory_size; i++) {
		inventory[i] = NULL;
        if (rhs.inventory[i] != NULL)
			inventory[i] = rhs.inventory[i]->clone();
    }
}

Character &Character::operator=(const Character &rhs){
    if (this != &rhs) {
        *this = rhs;
    }
    return *this;
}

Character::Character(std::string name) : name(name) {
    for (size_t i = 0; i < inventory_size; i++) {
        inventory[i] = NULL;
    }
}

Character::~Character() {
	for (size_t i = 0; i < inventory_size; i++) {
        if (inventory[i] != NULL)
            delete inventory[i];
    }
}

std::string const &Character::getName() const {
    return this->name;
}

void Character::equip(AMateria *m) {
    if (m == NULL)
        return ;
    for (size_t i = 0; i < inventory_size; i++) {
        if (inventory[i] == NULL) {
            inventory[i] = m->clone();
            return ;
        }
    }
}

bool Character::isInventoryIndexValid(int idx, const char *function_caller_name) const {
    if (idx < 0 || idx >= (int)inventory_size) {
        std::cout << function_caller_name << " Character unequip invalid not in valid range 0.." << this->inventory_size << std::endl;
        return false;
    }
    if (inventory[idx] == NULL) {
        std::cout << function_caller_name << " index point to empty Materia." << std::endl;
        return false;
    }
    return true;
}

void Character::unequip(int idx) {
    if (!this->isInventoryIndexValid(idx, __FUNCTION__))
        return ;
    delete inventory[idx];
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (!this->isInventoryIndexValid(idx, __FUNCTION__))
        return ;
    inventory[idx]->use(target);
}