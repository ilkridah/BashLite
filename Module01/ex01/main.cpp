/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:00:54 by ilkridah          #+#    #+#             */
/*   Updated: 2022/10/25 04:00:55 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

int main(int ac, char **av)
{
    int N;
    if(ac == 2 )
        N = atoi(av[1]);
    else {
        std::cout << "ERROR :: Horde Size !!,Please" << std::endl;
        exit(1);
    }
    if ((N < INT_MAX || N > INT_MIN ) && N > 0){
        Zombie *zombies = zombieHorde(N,"Horde");
         delete [] zombies;
    }
    std::cout << "try again !!" << std::endl;
    return 0;
}   