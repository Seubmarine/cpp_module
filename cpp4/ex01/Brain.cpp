#include "Brain.hpp"

Brain::Brain()
{
    for (size_t i = 0; i < sizeof(idea) / sizeof(idea[0]); i++) {
        this->idea[i] = "";
    }
}

Brain::Brain(Brain &rhs) {
    for (size_t i = 0; i < sizeof(idea) / sizeof(idea[0]); i++) {
        this->idea[i] = rhs.idea[i];
    }
}

Brain &Brain::operator=(Brain &rhs) {
    for (size_t i = 0; i < sizeof(idea) / sizeof(idea[0]); i++) {
        this->idea[i] = rhs.idea[i];
    }
    return *this;
}

Brain::~Brain()
{
}