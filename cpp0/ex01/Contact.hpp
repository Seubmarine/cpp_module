#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
private:
    

public:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string darkest_secret;
    std::string phone_number;
    Contact();
    ~Contact();
    void from_input();
    void print_all_fields();
};

#endif