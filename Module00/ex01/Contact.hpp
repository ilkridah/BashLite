
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
#include <string>

# define ON 1

class Contact {
	public:
		void		fill_contact(void);
		void		display_names(void);
		void		display_contact(void);

	private:
		std::string firstname;
		std::string lastname;
		std::string	nickname;
		std::string number;
		std::string Darkest_secret;
		
		void	print_string(std::string str);
};

#endif
