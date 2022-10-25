/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:02:43 by ilkridah          #+#    #+#             */
/*   Updated: 2022/10/25 04:02:44 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
