#ifndef BURAUCRAT_HPP
#define BURAUCRAT_HPP

#include <string>
#include <exception>

class Buraucrat
{
private:
    const std::string name;
    int grade;
public:
    class GradeTooHighException : public std::exception {};
    class GradeTooLowException : public std::exception {};
    Buraucrat();
    ~Buraucrat();
    Buraucrat(const Buraucrat &rhs);
    const Buraucrat &operator=(const Buraucrat &rhs);

    Buraucrat(std::string name, int grade);
};

#endif