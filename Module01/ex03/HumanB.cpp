/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:01:30 by ilkridah          #+#    #+#             */
/*   Updated: 2022/10/25 04:01:31 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"HumanB.hpp"

HumanB::HumanB(const std::string &name)
{
    _name = name;
}

HumanB::~HumanB()
{
}

void HumanB::attack() const
{
    std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}
