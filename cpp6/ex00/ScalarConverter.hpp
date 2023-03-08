#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
    ScalarConverter();
    ~ScalarConverter();
public:
    static void convert(std::string scalar);
};

#endif