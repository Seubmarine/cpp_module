#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void)
{
    this->length = 0;
    this->oldest_index = 0;
}

PhoneBook::~PhoneBook()
{
    this->length = 0;
    this->oldest_index = 0;
}

std::string string_truncated_at(std::string str, size_t max_size = 10) {
    if (str.size() <= max_size) {
        return (str);
    }
    std::string truncated = str.substr(0, max_size);
    truncated[max_size - 1] = '.';
    return (truncated);
}

void PhoneBook::list_contact(void) {
    for (size_t i = 0; i < this->length; i++)
    {
        Contact &current = this->contacts[i];
        std::cout << std::setw(10);
        std::cout << i << "|";
        
        std::cout << std::setw(10);
        std::cout << string_truncated_at(current.first_name) << "|";
        
        std::cout << std::setw(10);
        std::cout << string_truncated_at(current.last_name) << "|";
        
        
        std::cout << std::setw(10);
        std::cout << string_truncated_at(current.nickname) << "|";
    
        std::cout << std::endl;
    }

    std::cout << "\nSelect Contact Index :" << std::endl;
    size_t prompt_index = 9;
    if (!(std::cin >> prompt_index)) { //check if the user inputed a valid number
       return ;
    }
    if (prompt_index > this->capacity || prompt_index >= this->length) {
        std::cout << "\nInvalid Index\n" << std::endl;
    }
    else {
        std::cout << std::endl;
        this->contacts[prompt_index].print_all_fields();
    }
    std::cout << std::endl;
}

void PhoneBook::add_contact(Contact &contact) {
    unsigned int contact_index = this->length;
    if (contact_index == this->capacity) {
        contact_index = this->oldest_index;
        this->oldest_index += 1;
        this->oldest_index %= this->capacity;
    }
    this->contacts[contact_index] = contact;
    this->length += 1;
    if (this->length > this->capacity)
        this->length = this->capacity;
}
