
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {

	if (ac != 2) {
		std::cerr << "Invalid number of arguments. Usage : ./bitcoin input.txt" << std::endl;
		return (1);
	}

	std::map<std::string, double> mapData;
	readData("data.csv", mapData);
	readInput(av[1], mapData);
	return 0;
}
