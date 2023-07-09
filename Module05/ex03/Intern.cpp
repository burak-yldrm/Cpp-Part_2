#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "The slave has been created" << std::endl;
}

Intern::~Intern()
{
	std::cout << "The slave need a break" << std::endl;
}

AForm*  Intern::makeForm(std::string s1, std::string s2)
{
	std::string name[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int i = 0;
	while (i <= 3)
	{
		if (name[i < 3 ? i : 0] == s1)
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << s1 << std::endl;
			return new PresidentialPardonForm(s2);
		case 1:
			std::cout << "Intern creates " << s1 << std::endl;
			return new RobotomyRequestForm(s2);
		case 2:
			std::cout << "Intern creates " << s1 << std::endl;
			return new ShrubberyCreationForm(s2);
		default:
			std::cout << "Intern can not create " << s1 << std::endl;
			break;
	}
	return NULL;
}
