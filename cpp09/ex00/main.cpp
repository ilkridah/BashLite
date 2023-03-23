#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>


double findValue(std::map<std::string, double> &mapData, const std::string& date)
{
	std::map<std::string, double>::iterator it = mapData.begin();
	for ( ; it != mapData.end(); it++) {
		if (date > it->first)
			;
		else
			break;
	}
	if (date != it->first)
		it--;
	return (it->second);
}


void readData(const std::string& fileName, std::map<std::string, double> &mapData) {
	std::string line;
	std::ifstream file;

	file.open(fileName.c_str());
	if (!file.is_open() || file.bad())
		throw std::bad_exception();
	std::getline(file, line);
	while (std::getline(file, line))
	{
		unsigned long pos = 0;
		std::string temp;
		if ((pos = line.find(',')) != std::string::npos)
		{
			temp = line.substr(0, pos);
			line.erase(0, pos + 1);
		}
		mapData[temp] = std::atof(line.c_str());
	}
	file.close();
}

void readInput(const std::string& fileName, std::map<std::string, double> &mapdData) {
	std::string line;
	std::ifstream file;
	std::string y = "2023";
	std::string m = "12";
	std::string j = "31";

	file.open(fileName.c_str());
	if (!file.is_open() || file.bad())
		throw std::bad_exception();
	std::getline(file, line);
	while (std::getline(file, line))
	{
		unsigned long pos;
		std::string temp;
		if ((pos = line.find(" | ")) != std::string::npos) {
			temp = line.substr(0, pos);
			line.erase(0, pos + 3);
		} else {
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (y < temp.substr(0,4) || m < temp.substr(5, 2) || j < temp.substr(8, 2)) {
			std::cout << "Error: bad input => " << temp + " | " + line  << std::endl;
			continue ;
		}

	double d = std::atof(line.c_str());
		if (d < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (d > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
			std::cout << temp << " => " << d << " = " << findValue(mapdData, temp) * d << std::endl;
	}
	file.close();
}

int main(int ac, char **av) {
	std::cout << "----------- 🍌🐤 -----------" << std::endl;

	/* Error argc */
	if (ac != 2) {
		std::cerr << "Invalid number of arguments. Usage : ./btc input.txt" << std::endl;
		return (1);
	}

	std::map<std::string, double> mapData;
	readData("data/data.csv", mapData);
	readInput(av[1], mapData);
	return 0;
}
