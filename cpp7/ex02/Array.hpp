#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stddef.h>
#include <exception>

template<typename T>
class Array
{
private:
	T *elements;
	size_t array_size;
public:
	
	Array() : elements(NULL) , array_size(0) {};
	
	Array(unsigned int size) : elements(NULL) , array_size(size) {
		this->elements = new T[this->array_size]();
	}
	
	~Array() {
		if (this->elements != NULL) {
			delete[] elements;
			elements = NULL;
			array_size = 0;
		}
	}

	Array(const Array &rhs) {
		this->elements = NULL;
		this->array_size = 0;
		if (rhs.size() > 0) {
			*this = rhs;
		}
	}

	const Array &operator=(const Array &rhs) {
		if (this != &rhs) {
			if (this->elements != NULL) {
				delete[] this->elements;
				this->elements = NULL;
			}
			this->array_size = rhs.array_size;
			if (this->array_size) {
				this->elements = new T[this->array_size]();
				for (size_t i = 0; i < this->array_size; i++) {
					this->elements[i] = rhs.elements[i];
				}
			}
			
		}
		return *this;
	}

	T& operator[](int idx) const {
		if (this->array_size == 0 || idx < 0 || size_t(idx) > this->array_size - 1)
			throw std::exception();
		return this->elements[idx];
	};

	size_t size() const {
		return this->array_size;
	};

};

#endif