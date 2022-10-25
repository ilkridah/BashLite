/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:01:47 by ilkridah          #+#    #+#             */
/*   Updated: 2022/10/25 04:01:48 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"Weapon.hpp"

Weapon::Weapon(const std::string &type)
{
    _type = type;
}

Weapon::~Weapon()
{
}

std::string Weapon::getType() const
{
    return _type;
}

void Weapon::setType(std::string type)
{
    _type = type;
}