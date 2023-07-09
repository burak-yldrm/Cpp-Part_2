#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;

		// Written for orthadox canonical form compliance only.
		// Functions are empty.
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	public:
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm();


		void execute(const Bureaucrat& executor) const;
};
