#include"Zombie.hpp"

 Zombie::Zombie()
{
    name = "Horde";
}

Zombie::Zombie(std::string name)
{
    name = "horde";
}

Zombie::~Zombie()
{
    std::cout << "Horde destroyed" << std::endl;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}