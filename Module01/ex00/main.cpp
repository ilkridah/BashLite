/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:00:26 by ilkridah          #+#    #+#             */
/*   Updated: 2022/11/24 08:02:28 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

int main()
{
    Zombie A = Zombie("stack");
    Zombie *B = newZombie("heap");

    A.announce();
    B->announce();
    randomChump("chump");
    delete B;
}