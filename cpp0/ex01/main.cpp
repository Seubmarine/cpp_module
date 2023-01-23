#include "PhoneBook.hpp"
#include <iostream>
enum InputState {
    ADD,
    SEARCH,
    EXIT,
    INVALID,
};


// std::istream &operator >>(std::istream &in, Base& object)


std::istream& operator>>(std::istream& is, InputState& state)
{
    state = INVALID;
    std::string value;
    if (is >> value) {
        if (value == "ADD") {
            state = ADD;
        }
        else if (value == "SEARCH") {
            state = SEARCH;
        }
        else if (value == "EXIT") {
            state = EXIT;
        }
    }
    return is;
}

int main(void)
{
    PhoneBook phonebook = PhoneBook();
    bool running = true;
    while (running)
    {
        InputState asked_state = INVALID;
        std::cout << "Input a command: " << std::endl;
        Contact contact_to_add;
        std::cin >> asked_state;
        switch (asked_state)
        {
        case ADD:
            contact_to_add.from_input();
            phonebook.add_contact(contact_to_add);
            break;
        case INVALID:
            std::cout << "Invalid command.\n" << std::endl;
            break;
        case SEARCH:
            std::cout << "Searching.\n" << std::endl;
            phonebook.list_contact();
            break;
        case EXIT:
            running = false;
            break;
        }
    }
    
    return 0;
}
