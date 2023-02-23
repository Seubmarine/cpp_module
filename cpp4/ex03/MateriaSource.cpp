#include "MateriaSource.hpp"


MateriaSource::MateriaSource() : learned_materias_index(0) {
    for (size_t i = 0; i < learned_materias_size; i++)
    {
        learned_materias[i] = NULL;
    }
}

MateriaSource::~MateriaSource() {
    for (size_t i = 0; i < learned_materias_size; i++)
    {
        if (learned_materias[i] != NULL)
            delete learned_materias[i];
    }
}

void MateriaSource::learnMateria(AMateria *to_learn) {
    if (this->learned_materias_index < learned_materias_size) {
        this->learned_materias[this->learned_materias_index] = to_learn;
        this->learned_materias_index++;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (size_t i = 0; i < this->learned_materias_index; i++) {
        if (this->learned_materias[i]->getType() == type)
            return this->learned_materias[i];
    }
    return (0);
}
