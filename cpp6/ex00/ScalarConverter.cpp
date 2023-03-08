#include "ScalarConverter.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <cstdlib> //to get absolute value of a double using fabs()
#include <cmath>

template <class T>
void to_scalar(const T& scalar) {
    char c = static_cast<char>(scalar);
    float f = static_cast<float>(scalar);
    double d = static_cast<double>(scalar);
    int i = static_cast<int>(scalar);

    bool is_inf = (scalar == std::numeric_limits<double>::infinity() || scalar == -std::numeric_limits<double>::infinity());
    bool is_nan = (scalar != scalar);


    std::cout << "char: ";
    if (is_inf || is_nan || !isprint(c) || scalar < std::numeric_limits<char>::min() || scalar > std::numeric_limits<char>::max())
        std::cout << "Non diplayable" << std::endl; 
    else
        std::cout << c << std::endl; 
    

    std::cout << "int: ";
    if (is_inf || is_nan || scalar < std::numeric_limits<int>::min() || scalar > std::numeric_limits<int>::max())
        std::cout << "Non diplayable" << std::endl; 
    else
        std::cout << i << std::endl;

    std::cout.precision(1);
    T scalar_positive = std::fabs(scalar);
    if (!is_inf && (scalar_positive > std::numeric_limits<float>::max() || scalar_positive < std::numeric_limits<float>::min()))
        std::cout << "float: Non diplayable" << std::endl;
    else
        std::cout << "float: " << std::fixed << f << 'f' << std::endl;

    std::cout << "double: " << std::fixed << d << std::endl;
};

bool is_valid_integer(const std::string& str, int &num) {
    std::stringstream ss(str);
    return (ss >> num) && ss.eof();
}

bool is_valid_float(const std::string& str, float &num) {
    if (str.compare("-inff") == 0)
        return (num = -std::numeric_limits<float>::infinity());
    else if (str.compare("+inff") == 0  || str.compare("inff") == 0)
        return (num = std::numeric_limits<float>::infinity());
    else if (str.compare("nanf") == 0)
        return (num = std::numeric_limits<float>::quiet_NaN());
    
    double tmp = 0.0f; //we put the result in a double to verify later if it surpass the size of a float if it's the case it's not a valid float 

    std::stringstream ss(str);
    if (!(ss >> tmp))
        return false;
    num = tmp;
    std::string end;
    return ((ss >> end) && end.length() == 1 && end[0] == 'f' && ss.eof() && (fabs(tmp) < std::numeric_limits<float>::max() && fabs(tmp) > std::numeric_limits<float>::min()) );
}

bool is_valid_double(const std::string& str, double &num) {
    if (str.compare("-inf") == 0)
        return (num = -std::numeric_limits<double>::infinity());
    else if (str.compare("+inf") == 0  || str.compare("inf") == 0)
        return (num = std::numeric_limits<double>::infinity());
    else if (str.compare("nan") == 0)
        return (num = std::numeric_limits<double>::quiet_NaN());
    
    std::stringstream ss(str);
    return (ss >> num) && ss.eof();
}

void ScalarConverter::convert(std::string scalar) {
    
    int integer = 0;
    float f = 0.0f;
    double d = 0.0;
    if (is_valid_double(scalar, d)) {
        to_scalar(d);
    }
    else if (is_valid_float(scalar, f)) {
        to_scalar(f);
    }
    else if (is_valid_integer(scalar, integer))
    {
        to_scalar(integer);
    }
    else if (scalar.length() == 1) {
        char c = scalar[0];
        to_scalar(c);
    }
}