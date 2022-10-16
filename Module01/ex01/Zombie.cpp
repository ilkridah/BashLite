#include"Zombie.hpp"

 Zombie::Zombie()
{
    name = "Zombie";
}

Zombie::Zombie(std::string name)
{
    std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie destroyed" << std::endl;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
