/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:00:31 by ilkridah          #+#    #+#             */
/*   Updated: 2022/11/18 06:01:47 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"


Zombie *newZombie(std::string name)
{
    Zombie *new_Zombie = new (std::nothrow)Zombie(name);
    if(!new_Zombie)
        return NULL;
    return (new_Zombie);
}