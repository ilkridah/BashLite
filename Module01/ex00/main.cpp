#include"Zombie.hpp"

int main()
{
    Zombie A = Zombie("stack");
    Zombie *B = newZombie("heap");

    A.announce();
    (*B).announce();
    randomChump("chump");
    delete B;
}