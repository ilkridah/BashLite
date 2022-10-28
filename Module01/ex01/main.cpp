/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:00:54 by ilkridah          #+#    #+#             */
/*   Updated: 2022/10/25 15:52:23 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

int main(int ac, char **av)
{
    int N;
    (void)av;
    if(ac != 1){
        std::cout << "ERROR :: Horde Size !!,Please" << std::endl;
        exit(1);
    }
    else {
        std::cout << "Enter the number of zombies in the horde: ";
        std::cin >> N;
    }
    if ((N < INT_MAX || N > INT_MIN ) && N > 0 && isdigit(N)){
        Zombie *zombies = zombieHorde(N,"Horde");
         delete [] zombies;
    }
    else
        std::cout << "try again !!" << std::endl;
    return 0;
}