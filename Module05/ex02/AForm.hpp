#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const   name;
		int const           gradeToSign;
		int const           gradeToExecute;
		bool                isSigned;

		// Written for orthadox canonical form compliance only.
		// Functions are empty.
		AForm();
	
	public:
		AForm(std::string const &_name, int _gradeToSign, int _gradeToExecute);
		AForm(AForm const &other);
		virtual ~AForm();

		AForm &operator=(AForm const &other);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		std::string const &getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat const &bureaucrat);

		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, AForm const &form);