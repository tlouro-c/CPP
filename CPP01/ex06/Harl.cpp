#include "Harl.hpp"

void	Harl::complain( std::string level )
{
	int	index = ((level == "DEBUG") * 1) + ((level == "INFO") * 2)
		+((level == "WARNING") * 3) + ((level == "ERROR") * 4);
	if (!index)
		level = "Probably complaining about insignificant problems";

	std::cout << "[ " << level << " ]" << std::endl;

	switch (index)
	{
		case 0:
		{
			ignore();
			break ;
		}
		case 1:
			debug();
			__attribute__((fallthrough));
		case 2:
			info();
			__attribute__((fallthrough));
		case 3:
			warning();
			__attribute__((fallthrough));
		case 4:
			error();
			__attribute__((fallthrough));
		default:
			break ;
	}
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::ignore( void ){};