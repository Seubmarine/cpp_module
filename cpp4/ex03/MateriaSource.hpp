#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    static const size_t learned_materias_size = 4;
    size_t learned_materias_index;
    AMateria *learned_materias[learned_materias_size];
public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource &rhs);
    MateriaSource &operator=(const MateriaSource &rhs);
    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);
};

#endif