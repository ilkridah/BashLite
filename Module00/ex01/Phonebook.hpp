

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>
#include "Contact.hpp"

class Phonebook {
	public:
		void	display_phonebook(void);
		void	display_contact(int idx);
		void	fill_contact(int idx);

	private:
		Contact contact[8];
};

#endif
