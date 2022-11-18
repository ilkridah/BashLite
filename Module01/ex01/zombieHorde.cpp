/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:01:07 by ilkridah          #+#    #+#             */
/*   Updated: 2022/11/18 06:02:26 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombies = new (std::nothrow)Zombie[N];
    if(!zombies)
        return NULL;
    for(int i = 0; i < N; i++)
    {
        zombies[i].setName(name);
        zombies[i].announce();
    }
    return zombies;
}