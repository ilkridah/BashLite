#include"Zombie.hpp"

int main()
{
    Zombie *zombies = zombieHorde(6,"Horde");
    delete [] zombies;
}