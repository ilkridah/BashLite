
#include "Harl.hpp"

int	main(void)
{
	Harl		harl;
	std::string	input;

	std::cout << "(DEBUG, INFO, WARNING, ERROR)" << std::endl;
	std::cout << "Enter a level: ";
	std::cin >> input;
	harl.complain(input);
	return (0);
}
