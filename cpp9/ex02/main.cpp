#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <iomanip>
#include <sys/time.h>

long timeval_difference(struct timeval start_time, struct timeval end_time) {
    long milli_time, seconds, useconds;
    
    seconds = end_time.tv_sec - start_time.tv_sec; //seconds
    useconds = end_time.tv_usec - start_time.tv_usec; //milliseconds
    milli_time = ((seconds) * 1000 + useconds/1000.0);

    return milli_time;
}

void print_container_time(std::string container_name, long elapsed_time, size_t element_count) {
    std::cout << "Time to process a range of " << element_count << " elements with std::"<< container_name << " " << std::fixed << std::setprecision(5) << elapsed_time  << " us" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        std::cerr << "PmergeMe: Nothing to sort." << std::endl;
        return 1;
    }
    std::vector<int> numbers;
    numbers.reserve(argc - 1);
    for (int i = 1; i < argc; i++)
    {
        std::stringstream num_stream(argv[i]);
        int num;
        if (num_stream >> num && num_stream.eof() && num >= 0)
            numbers.push_back(num);
        else {
            std::cerr << "PmergeMe: invalid argument " << argv[i] << std::endl;
            return 2;
        }
    }
    
    if (numbers.size() <= 1) {
        std::cerr << "PmergeMe: only one number to sort." << std::endl;
        return 3;
    }
   
	std::cout << "Before: ";
    print_container(numbers);

    struct timeval vec_start_time, vec_end_time;
    
    gettimeofday(&vec_start_time, NULL);
    PMergeCreator(std::vector, int) vec(numbers.begin(), numbers.end());
    gettimeofday(&vec_end_time, NULL);
    long vec_time_diff = timeval_difference(vec_start_time, vec_end_time);
    
    std::cout << "After: ";
    vec.PrintElements();

    struct timeval deque_start_time, deque_end_time;
    
    gettimeofday(&deque_start_time, NULL);
    PMergeCreator(std::deque, int) deq(numbers.begin(), numbers.end());
    gettimeofday(&deque_end_time, NULL);
    long deque_time_diff = timeval_difference(deque_start_time, deque_end_time);
    
    print_container_time("vector", vec_time_diff, numbers.size());
    print_container_time("deque", deque_time_diff, numbers.size());
}
