#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
private:
    unsigned int length;
    static const unsigned int capacity = 8;
    unsigned int oldest_index;
    Contact contacts[capacity];

public:
    PhoneBook();
    ~PhoneBook();
    void add_contact(Contact &contact);
    void list_contact(void);
};

#endif