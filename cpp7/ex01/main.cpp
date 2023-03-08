#include "iter.hpp"
#include <iostream>
#include <string>
#include <cstring>
#define array_sizeof(x) (sizeof(x) / sizeof(x[0]))

void power(int &x) {
	x *= x;
}

void char_toupper(char &c) {
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
}

void word_to_upper(std::string &word) {
	for (size_t i = 0; i < word.length(); i++) {
		char_toupper(word[i]); 
	}
}
template<typename T> void print(T &data) {
	std::cout << data << std::endl;
}

int main()
{
	int simple[] = {0, 1, 2, 3, 4, 5, 6};
	iter(simple, array_sizeof(simple), print);
	iter(simple, array_sizeof(simple), power);
	iter(simple, array_sizeof(simple), print);

	std::string words[] = {"My", "Name", "iS", "minecraft"};
	iter(words, array_sizeof(words), print);
	iter(words, array_sizeof(words), word_to_upper);
	iter(words, array_sizeof(words), print);
	return 0;
}
