#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
	class NotEnougthElements : public std::exception {virtual const char* what() const throw() {return "Span::NotEnougthElements";}};
	class IsTooFull : public std::exception {virtual const char* what() const throw() {return "Span::IsTooFull";}};
private:
	std::vector<int> elements;
	unsigned int max_capacity;
public:
	Span();
	~Span();

	Span(unsigned int N);
	void addNumber(int element);
	unsigned long shortestSpan();
	unsigned long longestSpan();
	// Span(std::input_iterator_tag first, std::input_iterator_tag last);
	template <typename Iterator>
	void addNumbers(Iterator start, Iterator end) {
		for (Iterator it = start; it != end; ++it)
		{
			this->addNumber(*it);
		}
	};
};

#endif