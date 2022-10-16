#include"Zombie.hpp"

void randomchump(std::string name)
{
    Zombie zombie = Zombie(name);
    zombie.announce();
}