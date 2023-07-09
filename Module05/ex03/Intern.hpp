#pragma once

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		Intern(Intern& c);
		Intern& operator=(Intern& c);

	public:
		Intern();
		~Intern();

		AForm*	makeForm(std::string name, std::string target);
};