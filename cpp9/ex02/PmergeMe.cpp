#include "PmergeMe.hpp"

size_t jacobsthal(size_t n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<size_t> jacobsthal_build(size_t sequence_length) {
	std::vector<size_t> seq;
	seq.reserve(sequence_length);

	for (size_t i = 0; i <= sequence_length; i++)
	{
		size_t num = jacobsthal(i);
		if (num >= sequence_length)
			break;
		seq.push_back(num);
	}
	seq.push_back(sequence_length);

	std::vector<size_t> jacob_array;
	for (size_t i = 1; i < seq.size(); i++) {
    	for (size_t x = seq[i]; x > seq[i - 1]; x--) {
        	jacob_array.push_back(x - 1);
    	}
	}
	return jacob_array;
}

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return (a.second < b.second);
}