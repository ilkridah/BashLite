
#include "Contact.hpp"
#include "Book.hpp"

void head_printer(void){

		std::cout << " ******************************************** " << std::endl;
		std::cout << "|              Awesome PhoneBook             | " << std::endl;
		std::cout << "|             ADD, SEARCH, EXIT              | " << std::endl;
		std::cout << " ********************************************  " << std::endl;
}

void	search_contacts(Book phone){
	int	input;

	phone.display_phonebook();
	while (ON)
	{
		if (std::cin.eof())
			OFF;
		std::cout << "Enter an index: ";
		std::cin >> input;
		if (input > 0 && input < 9)
		{
			phone.display_contact(input - 1);
			OFF;
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
		if (std::cin.eof())
			OFF;
		if (i == 8)
			i = 0;
		head_printer();
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			phone.fill_contact(i);
			i++;
		}
		if (input == "SEARCH")
			search_contacts(phone);
		if (input == "EXIT")
			OFF;
	}
	return (0);
}
