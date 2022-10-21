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