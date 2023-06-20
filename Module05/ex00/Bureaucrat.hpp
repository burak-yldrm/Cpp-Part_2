#pragma once

#include <iostream>

class Bureaucrat
{
	private:
		std::string	const	name;
		int					grade;

		// Written for orthadox canonical form compliance only.
		// Functions are empty.
		Bureaucrat();
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &other);

	public:
		Bureaucrat(std::string const &_name, int _grade);
		~Bureaucrat();
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
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);