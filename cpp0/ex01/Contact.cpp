#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void)
{
}

//set first name, last name, nickname, phone number, darkest secret from the standart input
void Contact::from_input(void) {
    std::cout << "Input contact:" << std::endl;
    
    std::cout << "\nFirst name:" << std::endl;
    std::cin >> this->first_name;
    
    std::cout << "\nLast name:" << std::endl;
    std::cin >> this->last_name;
    
    std::cout << "\nNickname:" << std::endl;
    std::cin >> this->nickname;

    std::cout << "\nPhone number:" << std::endl; // special case ?
    std::cin >> this->phone_number;

    std::cout << "\nDarkest Secret:" << std::endl;
    std::cin >> this->darkest_secret;
}

void Contact::print_all_fields(void) {
    std::cout.setf(std::ios_base::left);
    std::cout
    << std::setw(17) << "First name: " << this->first_name << "\n"
    << std::setw(17) << "Last name: " << this->last_name << "\n"
    << std::setw(17) << "Nickname: " << this->nickname << "\n"
    << std::setw(17) << "Phone number: " << this->phone_number << "\n"
    << std::setw(17) << "Darkest secret: " << this->darkest_secret << "\n";
    std::cout.unsetf(std::ios_base::left);
    std::cout << std::endl;
}

Contact::~Contact()
{
    
}

std::string const &Contact::getFirstName() const {
	return this->first_name;
}
std::string const &Contact::getLastName() const {
	return this->last_name;
}
std::string const &Contact::getNickname() const {
	return this->nickname;
}
std::string const &Contact::getDarkestSecret() const {
	return this->darkest_secret;
}
std::string const &Contact::getPhoneNumber()const {
	return this->phone_number;
}