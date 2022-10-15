#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include"iostream"

class Zombie
{
    private:
        string::string name;
    public:
        Zombie();
        ~Zombie();
        void announce();
}
#endif