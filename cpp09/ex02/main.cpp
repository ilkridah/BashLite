
#include "PmergeMe.hpp"

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
	std::deque<int> dec;



	for (int i = 1; i < ac; i++)
	{
		vec.push_back(std::atoi(av[i]));
		dec.push_back(std::atoi(av[i]));
	}


	//
	const std::clock_t vec_begin_time = std::clock();
	//
		mergeSort(vec,0,vec.size()-1);
	//
	const std::clock_t vec_end_time = std::clock();
	//


	const std::clock_t list_begin_time = std::clock();
	mergeSort_deque(dec,0,dec.size()-1);
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
			ssv << " ";
		}
		ssv << *it;
	}
	std::cout << "After std::vector: \t" << ssv.str() << std::endl;

	std::stringstream ssl;
	for(std::deque<int>::iterator it = dec.begin(); it!= dec.end(); it++)
	{
		if (it != dec.begin()) {
			ssl << " ";
		}
		ssl << *it;
	}
	std::cout << "After std::deque: \t" << ssl.str() << std::endl;
	std::cout << "Time to process a range of\t" << ac - 1 << " elements with std::vector :\t" << 100.0 * (vec_end_time - vec_begin_time) / CLOCKS_PER_SEC << " us" << std::endl;
	std::cout << "Time to process a range of\t" << ac - 1 << " elements with std::deque :\t" << 100.0 * (list_end_time - list_begin_time) / CLOCKS_PER_SEC << " us" << std::endl;

	return (0);
}
