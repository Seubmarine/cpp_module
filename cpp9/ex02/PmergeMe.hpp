
#ifndef PMERGEME_HPP
	#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

template<typename container>
void print_container(container &c)
{
    for (size_t i = 0; i < c.size(); i++)
    {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
}

template<typename container>
size_t insert_binary_search(container &c, typename container::iterator low, typename container::iterator high, typename container::value_type &to_find) {
    typename container::iterator middle = low + std::distance(low, high) / 2;

    if (std::distance(low, high) <= 1 || *middle == to_find)
    {
        if (to_find <= *middle)
            return (std::distance(c.begin(), middle));
			// c.insert(middle, to_find);
        else
            return (std::distance(c.begin(), middle + 1));
            // c.insert(middle + 1, to_find);
    }
    else if (*middle > to_find) {
        return insert_binary_search(c, low, middle, to_find);
    } else if (*middle < to_find) {
        return  insert_binary_search(c, middle, high, to_find);
    }
    else {
        // c.insert(middle, to_find);    
		// std::cout << "HOHO" << std::endl;
		return (std::distance(c.begin(), middle));
	}
}

size_t jacobsthal(size_t n);

std::vector<size_t> jacobsthal_build(size_t sequence_length);

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b);

template<class Iter>
void merge_sort(Iter first, Iter last)
{
    if (last - first > 1)
    {
        Iter middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last, cmp);
    }
}

#define PMergeCreator(cont, inner_type) PmergeMe< cont<inner_type>, cont<std::pair< inner_type, inner_type > > >

template <typename Container, typename ContainerPaired>
class PmergeMe {
// typedef typename Container::template rebind<Type>::other MyContainer;
// typedef typename Container::template rebind< std::pair<Type, Type> >::other MyContainerPaired;
typedef typename Container::value_type value_type;
typedef typename Container::iterator iterator;
private:
  Container container_;
  ContainerPaired pair_;

public:
	PmergeMe() {}
	PmergeMe(const PmergeMe& pm) {
		*this = pm;
	}
	PmergeMe &operator=(const PmergeMe &pm) {
		this->container_ = pm.container_;
		this->pair_ = pm.pair_;
	}
	
	void PrintElements() {
		print_container(container_);
	}
	
	template <typename ConstructIterator>
	PmergeMe(ConstructIterator begin, ConstructIterator end) : container_(begin, end)
	{
		value_type straggler;
		bool has_straggler = false;

		if (container_.size() % 2)
		{
			has_straggler = true;
			straggler = container_.back();
			container_.pop_back();
		}
		for (size_t i = 0; i < container_.size(); i += 2)
		{
			std::pair<value_type, value_type> s(container_[i], container_[i + 1]);
			if (s.first > s.second)
				std::swap(s.first, s.second);
			pair_.push_back(s);
		}
		merge_sort(pair_.begin(), pair_.end());
		Container sorted;
		Container pending;
		for (typename ContainerPaired::iterator it = pair_.begin(); it != pair_.end(); it++) {
			std::pair<int, int> hi;
			// hi.first
			sorted.push_back(it->second);
			pending.push_back(it->first);
		}
		if (has_straggler)
			pending.push_back(straggler);
	
	
		//INSERTION SORT SECTION
	
		std::vector<size_t> a_positions;
		a_positions.reserve(sorted.size());
		for (size_t a_idx = 0; a_idx < sorted.size(); a_idx++)
			a_positions.push_back(a_idx);
	
		std::vector<size_t> jacob_arr = jacobsthal_build(pending.size());
		size_t i = 0;
		for (std::vector<size_t>::iterator b_index = jacob_arr.begin(); b_index != jacob_arr.end(); b_index++) {
			// print_container(sorted);
			// print_container(pending);

			typename Container::iterator s_begin = sorted.begin();
			typename Container::iterator s_end;
			if (*b_index < a_positions.size())
				s_end = sorted.begin() + a_positions[*b_index];
			else
				s_end = sorted.end();

			typename Container::value_type to_insert = pending[*b_index];
			size_t insertion_idx = insert_binary_search(sorted, s_begin, s_end, to_insert);
			sorted.insert(sorted.begin() + insertion_idx, to_insert);
			i++;
			for (std::vector<size_t>::iterator it = a_positions.begin(); it != a_positions.end(); it++)
			{
				if (*it >= insertion_idx)
					(*it) += 1;
			}
		}
		container_ = sorted;
	}
};

#endif