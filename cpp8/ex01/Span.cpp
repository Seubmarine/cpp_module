#include "Span.hpp"
#include <algorithm>
#include <limits>
Span::Span() {}
Span::~Span() {}
Span::Span(unsigned int N) {
	this->max_capacity = N;
	this->elements = std::vector<int>();
	// this->elements = std::vector<int>();
}


void Span::addNumber(int element) {
	if (this->elements.size() == this->max_capacity)
		throw Span::IsTooFull();
	// this->elements[this->elements.size()] = element;
	this->elements.push_back(element);
}

unsigned long Span::shortestSpan() {
	if (this->elements.size() <= 1)
		throw Span::NotEnougthElements();
	sort(this->elements.begin(), this->elements.end());
	unsigned long shortest_span = std::numeric_limits<unsigned long>::max();
	for (size_t i = 0; i < this->elements.size() - 1; i++) {
		unsigned long current_span = std::abs((long)this->elements[i] - (long)this->elements[i + 1]);
		if (current_span < shortest_span)
			shortest_span = current_span;
	}
	return shortest_span;
}

unsigned long Span::longestSpan() {
	if (this->elements.size() <= 1)
		throw Span::NotEnougthElements();
	long min = *std::min_element(this->elements.begin(), this->elements.end());
	long max = *std::max_element(this->elements.begin(), this->elements.end());
	return std::abs(min - max);
}
