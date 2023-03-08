#ifndef DATA_HPP
#define DATA_HPP
#include <string>

class Data {
private:
	std::string name;
	unsigned int age;

public:
	Data();
	Data(std::string name, unsigned int age);
	~Data();
	Data(const Data &rhs);
	const Data &operator=(const Data &rhs);

	std::string getName() const;
	unsigned int getAge() const;
};

std::ostream &operator<<(std::ostream &os, const Data &data);

#endif