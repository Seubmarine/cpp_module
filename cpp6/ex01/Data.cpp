#include "Data.hpp"
#include <iostream>

Data::Data() :
		name("person"), age(0) {}

Data::~Data() {}

Data::Data(std::string name, unsigned int age) :
		name(name), age(age) {}

Data::Data(const Data &rhs) :
		name(rhs.name), age(rhs.age) {}

const Data &Data::operator=(const Data &rhs) {
	if (&rhs != this) {
		this->name = rhs.name;
		this->age = rhs.age;
	}
	return *this;
}

std::string Data::getName() const {
	return this->name;
}
unsigned int Data::getAge() const {
	return this->age;
}

std::ostream &operator<<(std::ostream &os, const Data &data) {
	os << "name: " << data.getName() << " age: " << data.getAge();
	return os;
}
