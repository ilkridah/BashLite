#include"HumanA.hpp"
#include"HumanB.hpp"
#include"Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}   

void HumanA::attack() const
{
    std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
