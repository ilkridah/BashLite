
#include <iostream>
#include <stdlib.h>
#include "Contact.hpp"

void	Contact::fill_contact(void)
{
	std::cout << "> First name: ";
	std::getline(std::cin, firstname); 
	std::cout << "> Last name: ";
	std::getline(std::cin, lastname);
	std::cout << "> Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "> Number: ";
	std::getline(std::cin, number); 
	std::cout << "> Darkest_Secret: ";
	std::getline(std::cin, Darkest_secret);
}

void	Contact::print_string(std::string str)
{
	std::cout << std::setw(10);
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	std::cout << str << "|";
}

void	Contact::display_names(void)
{
	print_string(firstname);
	print_string(lastname);
	print_string(nickname);
	std::cout << std::endl;
}

void	Contact::display_contact(void)
{
	std::cout << "> First name: " << firstname << std::endl;
	std::cout << "> Last name: " << lastname << std::endl;
	std::cout << "> Nickname: " << nickname << std::endl;
	std::cout << "> Number: " << number << std::endl;
	std::cout << "> Darkest_Secret: " << Darkest_secret << std::endl;
}
