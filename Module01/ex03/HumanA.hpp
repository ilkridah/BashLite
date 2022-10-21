
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