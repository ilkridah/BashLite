#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include"iostream"

class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void announce();

    Zombie *newZombie(std::string name);
    void randomchump(std::string name);
};
#endif