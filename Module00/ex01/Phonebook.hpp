/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 23:18:44 by ilkridah          #+#    #+#             */
/*   Updated: 2022/10/15 23:18:44 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
