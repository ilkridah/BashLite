/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:01:50 by ilkridah          #+#    #+#             */
/*   Updated: 2022/11/28 20:39:29 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>

class Weapon
{
    public:
        Weapon(const std::string &type);
        ~Weapon();
        std::string getType() const;
        void setType(std::string type);
    private:
        std::string _type;
};