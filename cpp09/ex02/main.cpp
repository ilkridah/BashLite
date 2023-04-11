
#include<iostream>
#include<cmath>
#include<list>
#include<vector>
#include<sstream>
#include<ctime>

template <typename ForwardIterator>
void merge(ForwardIterator first, ForwardIterator mid, ForwardIterator last) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
    std::vector<value_type> temp(std::distance(first, last));
    ForwardIterator i = first, j = mid, k = temp.begin();

    while (i != mid && j != last) {
        if (*i < *j)
            *k++ = *i++;
        else
            *k++ = *j++;
    }

    while (i != mid)
        *k++ = *i++;

    while (j != last)
        *k++ = *j++;

    std::copy(temp.begin(), temp.end(), first);
}

template <typename ForwardIterator>
void insertion_sort(ForwardIterator first, ForwardIterator last) {
    typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
    for (ForwardIterator i = first; i != last; ++i) {
        value_type key = *i;
        ForwardIterator j = i;
        while (j != first && *(j - 1) > key) {
            *j = *(j - 1);
            --j;
        }
        *j = key;
    }
}

template <typename RandomAccessIterator>
void merge_insertion_sort(RandomAccessIterator first, RandomAccessIterator last, int threshold) {
    typedef typename std::iterator_traits<RandomAccessIterator>::difference_type diff_type;
    if (last - first > threshold) {
        RandomAccessIterator mid = first + (last - first) / 2;
        merge_insertion_sort(first, mid, threshold);
        merge_insertion_sort(mid, last, threshold);
        merge(first, mid, last);
    } else {
        insertion_sort(first, last);
    }
}

template <typename Container>
void merge_insertion_sort(Container& c, int threshold) {
    typedef typename Container::iterator iterator;
    merge_insertion_sort(c.begin(), c.end(), threshold);
}
///////////////////////////////////////////-------------------/////////////////////////////

int ft_error(char *s)
{
	for (size_t i = 0; i < strlen(s); i++)
	{
		if (!std::isdigit(s[i]))
			return(1);
	}
	return(0);
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Need args, positive integer" << std::endl;
		return (1);
	}
	for (int i = 1; i < ac; i++){
		if(ft_error(av[i])){
			std::cout << "Bad input" << std::endl;
			return (1);
		}
	}

	std::vector<int> vec;
	std::list<int> list;



	for (int i = 1; i < ac; i++)
	{
		vec.push_back(std::atoi(av[i]));
		list.push_back(std::atoi(av[i]));
	}


	//
	const std::clock_t vec_begin_time = std::clock();
	//
	merge_insertion_sort(vec,10);
	//
	const std::clock_t vec_end_time = std::clock();
	//


	const std::clock_t list_begin_time = std::clock();
	merge_insertion_sort(list,10);
	const std::clock_t list_end_time = std::clock();


	// unsort print
	std::string unsort = std::string(av[1]);
	for (int i = 2; i < ac; i++){
		unsort += " " + std::string(av[i]);
	}

	std::cout << "Before: \t" << unsort << std::endl;
	std::stringstream ssv;
	for(std::vector<int>::iterator it =vec.begin(); it!=vec.end(); it++)
	{
		if (it != vec.begin()) {
			ssv<<" ";
		}
		ssv << *it;
	}
	std::cout << "After std::vector: \t" << ssv.str() << std::endl;

	std::stringstream ssl;
	for(std::list<int>::iterator it =list.begin(); it!=list.end(); it++)
	{
		if (it != list.begin()) {
			ssl << " ";
		}
		ssl << *it;
	}
	std::cout << "After std::list: \t" << ssl.str() << std::endl;
	std::cout << "Time to process a range of\t" << ac - 1 << " elements with std::vector :\t" << 100.0 * (vec_end_time - vec_begin_time) / CLOCKS_PER_SEC << " us" << std::endl;
	std::cout << "Time to process a range of\t" << ac - 1 << " elements with std::list :\t" << 100.0 * (list_end_time - list_begin_time) / CLOCKS_PER_SEC << " us" << std::endl;

	return (0);
}
