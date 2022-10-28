/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:01:30 by ilkridah          #+#    #+#             */
/*   Updated: 2022/10/25 17:29:51 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name) 
{
    
}

HumanB::~HumanB()
{
}

void HumanB::attack() const
{
    if(_weapon)
        std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " attacks with his penis " << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{     
    _weapon = &weapon;
}
