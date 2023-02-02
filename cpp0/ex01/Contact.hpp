#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string darkest_secret;
    std::string phone_number;

public:
    Contact();
    ~Contact();

	std::string const &getFirstName() const;
	std::string const &getLastName() const;
	std::string const &getNickname() const;
	std::string const &getDarkestSecret() const;
	std::string const &getPhoneNumber()const;
    void from_input();
    void print_all_fields();
};

#endif