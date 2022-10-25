/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:01:27 by ilkridah          #+#    #+#             */
/*   Updated: 2022/10/25 04:01:28 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_HPP
#define HUMANA_HPP

#include<iostream>
#include"HumanA.hpp"
#include"Weapon.hpp"

    class HumanA
    {
        public:
            HumanA(std::string name, Weapon &weapon);
            ~HumanA();
            void attack() const;
        private:
            std::string _name;
            Weapon &_weapon;
    };

#endif