/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:00:54 by ilkridah          #+#    #+#             */
/*   Updated: 2022/11/29 17:30:30 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

int main(int ac, char **av)
{
    int num;
    (void)av;
    if(ac != 1){
        std::cerr << "ERROR :: Try again !!" << std::endl;
        exit(1);
    }
    std::cout << "Enter the number of zombies in the horde: ";
    std::cin >> num;
    if(num > 0 && num < INT_MAX)
    {
        Zombie *zombies = zombieHorde(num,"Horde");
        delete [] zombies;
    }
    return 0;
}