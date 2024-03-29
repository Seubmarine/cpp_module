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

MateriaSource::MateriaSource(const MateriaSource &rhs) {
	*this = rhs;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
	if (this != &rhs) {
		for (size_t i = 0; i < learned_materias_size; i++) {
        	learned_materias[i] = NULL;
			if (rhs.learned_materias[i] != NULL)
        		learned_materias[i] = rhs.learned_materias[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *to_learn) {
    if (this->learned_materias_index < learned_materias_size) {
        if (this->learned_materias[this->learned_materias_index] != NULL)
			delete this->learned_materias[this->learned_materias_index];
		this->learned_materias[this->learned_materias_index] = to_learn;
        this->learned_materias_index++;
    }
	else {
		this->learned_materias_index = 0;
		this->learnMateria(to_learn);
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (size_t i = 0; i < this->learned_materias_index; i++) {
        if (this->learned_materias[i]->getType() == type)
            return this->learned_materias[i];
    }
    return (0);
}
