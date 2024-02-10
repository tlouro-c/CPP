#include "ClapTrap.hpp"

ClapTrap::ClapTrap( const std::string& name )
	: _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "ClapTrap Constructor Called" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

void ClapTrap::attack( const std::string& target )
{
	if (_energyPoints > 0)
	{
		std::cout << "ClapTrap "
				<< _name 
				<< " attacks "
				<< target
				<< ", causing "
				<<  _attackDamage 
				<< " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "ClapTrap "
				<< _name 
				<< " doesn't have enough energy" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (static_cast<int> (_hitPoints - amount) <= 0)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << _name << " took " << amount 
			  << " points of damage. Remaining hit points: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	_hitPoints += amount;
	std::cout << _name << " restored " << amount
			  << " hit points. Remaining hit points: " << _hitPoints << std::endl;
}

uint ClapTrap::getAD( void )
{
	return (_attackDamage);
}
