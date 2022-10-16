#include"Zombie.hpp"

 Zombie::Zombie()
{
    name = "Horde";
}

Zombie::Zombie(std::string name)
{
    std::cout << "Horde created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Horde destroyed" << std::endl;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
