#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
private:
    std::string idea[100];
public:
    Brain();
    Brain(Brain &from);
    Brain &operator=(Brain &rhs);
    ~Brain();
};

#endif