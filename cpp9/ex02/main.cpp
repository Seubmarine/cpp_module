#include <iostream>
#include <vector>
#include <list>

template<typename container>
void print_container(container &c)
{
    for (size_t i = 0; i < c.size(); i++)
    {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
}

#include <algorithm>
template<typename container>
void	merge_sort(container &c, size_t size, size_t pos)
{
	size_t	middle;
   
	if (size <= 2)
		return ;
	middle = size / 2 + pos;
	merge_sort(c, size / 2, pos);
	merge_sort(c, size / 2, middle);
    
    container tmp;

    size_t left = pos;
    size_t right = middle;
    while (right < (pos + size) && left < middle) {
        if (c[left] < c[right]) {
            tmp.push_back(c[left]);
            tmp.push_back(c[left + 1]);
            left += 2;
        } else {
            tmp.push_back(c[right]);
            tmp.push_back(c[right + 1]);
            right += 2;
        }
    }
    for (; right < size; right += 2) {
            tmp.push_back(c[right]);
            tmp.push_back(c[right + 1]);
    }
    for (; left < middle; left += 2) {
            tmp.push_back(c[left]);
            tmp.push_back(c[left + 1]);
    }

    for (size_t i = 0; i < tmp.size(); i++) {
        c[pos + i] = tmp[i];
    }
}

template<typename container>
void insert_binary_search(container &c, typename container::iterator low, typename container::iterator high, typename container::value_type &to_find) {
    typename container::iterator middle = low + std::distance(low, high) / 2;

    std::cout << "distance = " << std::distance(low, high) << std::endl;
    
    if (std::distance(low, high) <= 1 || *middle == to_find)
    {
        if (to_find < *middle)
            c.insert(middle, to_find);
        else
            c.insert(middle + 1, to_find);

        return ;
    }
    else if (*middle > to_find) {
        insert_binary_search(c, low, middle, to_find);
        return ;
    } else if (*middle < to_find) {
        insert_binary_search(c, middle, high, to_find);
        return ;
    }
    else
        c.insert(middle, to_find);    
}

template<typename container>
void sort_pair(container &c)
{
    for (size_t i = 0; i + 1 < c.size(); i += 2)
    {
        if (c[i] > c[i + 1])
            std::swap(c[i], c[i + 1]);
    }

    print_container(c);
    merge_sort(c, c.size(), 0);
    print_container(c);
    container s; //sorted number
    container tmp; //temporary hold what will be inserted
    for (size_t i = 0; i < c.size(); i++)
    {
        if (i % 2 == 0)
            s.push_back(c[i]);
        else
            tmp.push_back(c[i]);
    }

    for (size_t i = 0; i < tmp.size(); i++)
    {
        print_container(s);
        print_container(tmp);
        insert_binary_search(s, s.begin(), s.end(), tmp[i]);
        // insert_binary_search(s, 0, s.size(), tmp[i]);
    }
    c = s;
}

#define sizeof_array(x) (sizeof(x) / sizeof(*x))
int main()
{
    // int seq[] = {7, 8, 5, 6, 4, 2, 1, 3};
    // int seq[] = {5, 2, 4, 7, 3, 1, 6, 8};
    int seq[] = {46, 8, 7, 123, 3, 46, 85, 79, 96, 28, 29, 46, 91, 13, 0, 3};
    std::vector<int> v(seq, &seq[sizeof_array(seq)]);

    print_container(v);
    sort_pair(v);
    print_container(v);
}
