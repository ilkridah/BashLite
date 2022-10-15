/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 23:18:40 by ilkridah          #+#    #+#             */
/*   Updated: 2022/10/15 23:18:40 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Phonebook.hpp"

void	Phonebook::display_phonebook(void)
{
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		contact[i].display_names();
	}
}

void	Phonebook::fill_contact(int idx)
{
	contact[idx].fill_contact();
}

void	Phonebook::display_contact(int idx)
{
	contact[idx].display_contact();
}

