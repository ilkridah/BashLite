/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 23:18:16 by ilkridah          #+#    #+#             */
/*   Updated: 2022/10/15 23:18:16 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <stdlib.h>
#include "Contact.hpp"

std::string mygetline()
{
	std::string var;
	if(!std::getline(std::cin, var))
		exit(1);
	while(var.empty())
	{
		std::cout << "Please enter a value: ";
		if(!std::getline(std::cin, var))
			exit(1);
	}
	return var;	
}

void	Contact::fill_contact(void)
{
	std::cout << "> First name: ";
	firstname = mygetline();
	std::cout << "> Last name: ";
	lastname = mygetline();
	std::cout << "> Nickname: ";
	nickname = mygetline();
	std::cout << "> Number: ";
	number = mygetline(); 
	std::cout << "> Darkest_Secret: ";
	Darkest_secret = mygetline();
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
