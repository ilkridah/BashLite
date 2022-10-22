/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 23:18:24 by ilkridah          #+#    #+#             */
/*   Updated: 2022/10/15 23:18:24 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
#include <string>

# define ON 1

class Contact {
	public:
		void		fill_contact(void);
		void		display_names();
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
