//
// Created by Lowell Zima on 3/18/23.
//

#include<iostream>
#include<cmath>
#include<list>
#include<vector>
#include<sstream>
#include<ctime>


int bad_input(char *s)
{
	for (size_t i = 0; i < strlen(s); i++)
		if (!std::isdigit(s[i]))
			return(1);
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
		if(bad_input(av[i])){
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
	sort(vec.begin(), vec.end());
	//
	const std::clock_t vec_end_time = std::clock();
	//


	const std::clock_t list_begin_time = std::clock();
	list.sort();
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
	std::cout << "Time to process a range of: \t" << ac - 1 << " elements with std::vector : \t" << 100.0 * (vec_end_time - vec_begin_time) / CLOCKS_PER_SEC << " us" << std::endl;
	std::cout << "Time to process a range of: \t" << ac - 1 << " elements with std::list : \t" << 100.0 * (list_end_time - list_begin_time) / CLOCKS_PER_SEC << " us" << std::endl;

	return (0);
}
