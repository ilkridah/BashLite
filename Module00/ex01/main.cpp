
#include "Contact.hpp"
#include "Book.hpp"

std::string header(void){

	std::string input;
	std::cout << " ******************************************** " << std::endl;
	std::cout << "|              Awesome PhoneBook             | " << std::endl;
	std::cout << "|             ADD, SEARCH, EXIT              | " << std::endl;
	std::cout << " ********************************************  " << std::endl;
	if (!std::getline(std::cin, input))
		exit(1);
	return input;
}

void	search_contacts(Book phone){

	std::string	input;
	phone.display_phonebook();
	while (ON)
	{
		std::cout << "Enter an index: ";
		if (!std::getline(std::cin,input))
			exit(1);
		int i = atoi(input.c_str());
		if (i > 0 && i < 9)
		{
			phone.display_contact(i - 1);
			return;
		}
	} 
}

int	main(void)
{
	Book		phone;
	std::string	input;
	int			i;
	i = 0;
	
	while (ON)
	{
		if (i == 8)
			i = 0;
		input = header();
		if (input == "ADD")
		{
			phone.fill_contact(i);
			i++;
		}
		else if (input == "SEARCH")
			search_contacts(phone);
		else if (input == "EXIT")
			break;
	}
	return (0);
}
