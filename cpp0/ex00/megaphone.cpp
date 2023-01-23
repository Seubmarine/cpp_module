#include <iostream>

void string_ascii_to_uppercase(std::string &str) {
    for (size_t i = 0; i < str.length(); i++) {
        str[i] = static_cast<char>(std::toupper(str[i]));
    }
}

int main(int argc, char const *argv[])
{
    std::string sentence;
    for (int index = 1; index < argc; ++index) {
        sentence.append(argv[index]);
    }
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else {
        string_ascii_to_uppercase(sentence);
        std::cout << sentence;
    }
    std::cout << std::endl;
    return 0;
}
