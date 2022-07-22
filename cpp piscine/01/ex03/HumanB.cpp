#include "HumanB.hpp"

HumanB::HumanB(){}

HumanB::HumanB(std::string str) : name(str) {}

HumanB::~HumanB(){}

void    HumanB::setWeapon(Weapon *weapon){
	human_weapon = weapon;
}

void    HumanB::attack(){
	std::cout << name << " attacks with their " << human_weapon->getType() << std::endl; 
}