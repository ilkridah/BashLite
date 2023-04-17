
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {

	if (ac != 2) {
		std::cerr << "Invalid number of arguments. Usage : ./btc input.txt" << std::endl;
		return (1);
	}
	std::map<std::string, double> mapData;
	bitcoinExchange::readData("data.csv", mapData);
	bitcoinExchange::readInput(av[1], mapData);
	return 0;
}
