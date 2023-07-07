#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>

// template<typename container>
// void print_container(container &c)
// {
//     for (size_t i = 0; i < c.size(); i++)
//     {
//         std::cout << c[i] << " ";
//     }
//     std::cout << std::endl;
// }


// #include <algorithm>
// template<typename container>
// void	merge_sort(container &c, size_t left, size_t right)
// {
// 	size_t	middle;
   
// 	if (size <= 1)
// 		return ;
// 	middle = size / 2 + pos;
// 	merge_sort(c, size / 2, pos);
// 	merge_sort(c, size / 2, middle);
    
//     container tmp;

//     size_t left = pos * 2;
//     size_t right = middle * 2;
//     while (right < (pos + (size * 2)) && left < middle) {
//         if (c[left] < c[right]) {
//             tmp.push_back(c[left]);
//             tmp.push_back(c[left + 1]);
//             left += 2;
//         } else {
//             tmp.push_back(c[right]);
//             tmp.push_back(c[right + 1]);
//             right += 2;
//         }
//     }
//     for (; right < size; right += 2) {
//             tmp.push_back(c[right]);
//             tmp.push_back(c[right + 1]);
//     }
//     for (; left < middle; left += 2) {
//             tmp.push_back(c[left]);
//             tmp.push_back(c[left + 1]);
//     }

//     for (size_t i = 0; i < tmp.size(); i++) {
//         c[pos * 2 + i] = tmp[i];
//     }
// }

// template<typename container>
// size_t insert_binary_search(container &c, typename container::iterator low, typename container::iterator high, typename container::value_type &to_find) {
//     typename container::iterator middle = low + std::distance(low, high) / 2;

//     std::cout << "distance = " << std::distance(low, high) << std::endl;
    
//     if (std::distance(low, high) <= 1 || *middle == to_find)
//     {
//         if (to_find < *middle)
//             return (std::distance(c.begin(), middle));
// 			// c.insert(middle, to_find);
//         else
//             return (std::distance(c.begin(), middle + 1));
//             // c.insert(middle + 1, to_find);
//     }
//     else if (*middle > to_find) {
//         return insert_binary_search(c, low, middle, to_find);
//     } else if (*middle < to_find) {
//         return  insert_binary_search(c, middle, high, to_find);
//     }
//     else {
//         // c.insert(middle, to_find);    
// 		std::cout << "HOHO" << std::endl;
// 		return (std::distance(c.begin(), middle));
// 	}
// }

// template<typename container>
// void sort_pair(container &c)
// {
    
	// std::cout << "Pair only:" << std::endl;
    // print_container(c);
    // typename container::value_type straggler;
    // if (c.size() % 2 == 1) {
	// 	straggler = c.back();
	// 	c.pop_back();
	// }
    // std::cout << "Pair sorted (without straggler)" << std::endl;
	// print_container(c);
    // container s; //sorted number
    // container tmp; //temporary hold what will be inserted
	
	// for (size_t i = 0; i < c.size(); i++)
    // {
    //     if (i % 2 == 0)
    //         s.push_back(c[i]);
    //     else
    //         tmp.push_back(c[i]);
    // }
	// if (c.size() % 2 == 1) {
	// 	tmp.push_back(straggler);
	// }

// 	std::vector<size_t> a_positions;
// 	a_positions.reserve(s.size());
// 	for (size_t a_idx = 0; a_idx < s.size(); a_idx++)
// 		a_positions.push_back(a_idx);
	
// 	std::vector<size_t> jacob_arr = jacobsthal_build(tmp.size());
// 	size_t i = 0;
// 	for (std::vector<size_t>::iterator b_index = jacob_arr.begin(); b_index != jacob_arr.end(); b_index++) {
//         print_container(s);
//         print_container(tmp);
		
// 		typename container::iterator s_begin = s.begin();
// 		typename container::iterator s_end = s.begin();
// 		if (*b_index < s.size())
// 			s_end += *b_index;
// 		else
// 			s_end = s.end();

// 		typename container::value_type &to_insert = tmp[i];
// 		size_t insertion_idx = insert_binary_search(s, s_begin, s.end(), to_insert);
// 		main.insert(s.begin() + insertion_idx, to_insert);
// 		i++;
// 		for (std::vector<size_t>::iterator it = a_positions.begin(); it != a_positions.end(); it++)
// 		{
// 			if (*it >= insertion_idx)
// 				(*it) += 1;
// 		}
//     }
//     c = s;
// }

#include <algorithm>
// template <typename Container>
// // Function to merge two sorted arrays using std::merge
// Container merge_(Container& left, Container& right) {
//     Container result;
// 	typename Container::iterator osef;
//     std::merge(left.begin(), left.end(), right.begin(), right.end(), osef);
//     return result;
// }

// template <typename Container>
// // Function to perform merge sort
// Container merge_sort_(Container& array) {
//     if (array.size() <= 1) {
//         return array;
//     }

//     int mid = array.size() / 2;
//     Container left(array.begin(), array.begin() + mid);
//     Container right(array.begin() + mid, array.end());

//     left = merge_sort_(left);
//     right = merge_sort_(right);

//     return merge_(left, right);
// }

#define sizeof_array(x) (sizeof(x) / sizeof(*x))
int main()
{
    int seq[] = {7, 8, 5, 6, 4, 2, 1, 3};
    // int seq[] = {5, 2, 3, 1, 4, 7, 6};
	
    // int seq[] = {5, 2, 4, 7, 3, 1, 6, 8};
    // int seq[] = {46, 8, 7, 123, 3, 46, 85, 79, 96, 28, 29, 46, 91, 13, 0, 3};
    std::vector<int> v(seq, &seq[sizeof_array(seq)]);
	// merge_sort_(v.begin(), v.end());
	PMergeCreator(std::vector, int) p(v.begin(), v.end());
    // print_container(v);
    // sort_pair(v);
    // print_container(v);
}
