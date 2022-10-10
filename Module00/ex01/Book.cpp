
#include "Book.hpp"

void	Book::display_phonebook(void)
{
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		contact[i].display_names();
	}
}

void	Book::fill_contact(int idx)
{
	contact[idx].fill_contact();
}

void	Book::display_contact(int idx)
{
	contact[idx].display_contact();
}
