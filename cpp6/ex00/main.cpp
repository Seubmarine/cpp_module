#include "ScalarConverter.hpp"
#include <string>
#include <limits>
#include <iostream>

int main(int argc, char const *argv[])
{
    if (argc <= 1) {
        return 0;
    }
    ScalarConverter::convert(std::string(argv[1]));
    return 0;
}
