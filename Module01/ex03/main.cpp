#include"HumanA.hpp"
#include"HumanB.hpp"
#include"Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("club_1");
        HumanA kimiko("kimiko", club);
        kimiko.attack();
        club.setType("some other type of club");
        kimiko.attack();
    }
    {
        Weapon club = Weapon("club_2");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
