#include "BitcoinExchange.hpp"

bitcoinExchange::bitcoinExchange() {}
bitcoinExchange::~bitcoinExchange() {}
bitcoinExchange::bitcoinExchange(const bitcoinExchange &src) { *this = src; }
bitcoinExchange &bitcoinExchange::operator=(const bitcoinExchange &rhs) {
	if (this != &rhs) {}
	return *this;
}

bool isLeapYear(int year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}


bool is_date_valide(std::string date)
{
	std::istringstream iss(date);
   

    int day, month, year;
    char delimiter;

	if(date.length() != 10) 
	{
		std::cout << "Error: bad input *** => " << date << std::endl;
		return false;}

	iss >> year >> delimiter >> month >> delimiter >> day >> delimiter;

	if (delimiter != '-')
	{
		std::cout << "Error: hhhhh => " << date << std::endl;
		return false;
	}

	if((year > 2023 || year < 2009 ) || (month > 12 || month <= 0) || (day > 31 || day <= 0))
	{
		std::cout << "Error: hohoho => " << date << std::endl;
		return false;
	}
	if(month == 2){
		if (!isLeapYear(year) && day == 29) {
			std::cout << year << " it is not a leap year, so February has 28 days => " << date << std::endl;
			return false;}

		else if(day > 29){
			std::cout << "Error: bad input zz => " << date << std::endl;
			return false;}
	}
    return true;
}

void bitcoinExchange::readInput(const std::string& fileName, std::map<std::string, double> &mapdData) {
	std::string line;
	std::ifstream file;

	file.open(fileName.c_str());
	if (!file.is_open() || file.bad()) {std::cout << "Error: bad file !!" << std::endl; return ;}
	std::getline(file, line);

	if(line != "date | value")
	{
		std::cout << "Error: bad file !!" << std::endl;
		return ;}

	while (std::getline(file, line))
	{
		unsigned long pos;
		std::string temp;
		if ((pos = line.find(" | ")) != std::string::npos) {
			temp = line.substr(0, pos);
			line.erase(0, pos + 3);
		if(!is_date_valide(temp))
			continue ;
		} else {
			std::cout << "Error: bad input 1 => " << line << std::endl;
			continue ;
		}
		if(!line.find_first_not_of("-+0123456789")){std::cout << "Error: bad input last => " << line << std::endl; continue ;}
		if(line.back() == '.'){std::cout << "Error: bad input for => " << line << std::endl;continue ;}
			
		std::istringstream ss(line);
		double d;
		if(ss >> d && ss.eof())
		{	
			if (d < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (d > 1000)
				std::cout << "Error: number is too large." << std::endl;
			else
				std::cout << temp << " => " << d << " = " << bitcoinExchange::findValue(mapdData, temp) * d << std::endl;
		}
		else
			std::cout << "Error: bad input jijijii => " << line << std::endl;
	}
	file.close();
}


double bitcoinExchange::findValue(std::map<std::string, double> &mapData, const std::string& date)
{
	std::map<std::string, double>::iterator it;
	it = mapData.lower_bound(date);
	if (it != mapData.begin() && it->first != date){
		it--;
	}
	return (it->second);
}

void bitcoinExchange::readData(const std::string& fileName, std::map<std::string, double> &mapData) {
	std::string line;
	std::ifstream file;

	file.open(fileName.c_str());
	if (!file.is_open() || file.bad()){std::cout << "Error: bad file !!" << std::endl; return ;}
		
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