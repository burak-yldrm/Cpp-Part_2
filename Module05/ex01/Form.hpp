#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const   name;
        int const           gradeToSign;
        int const           gradeToExecute;
        bool                isSigned;

        // Written for orthadox canonical form compliance only.
        // Functions are empty.
        Form();
        Form(Form const &other);
        Form &operator=(Form const &other);
    
    public:
        Form(std::string const &_name, int _gradeToSign, int _gradeToExecute);
        ~Form();
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
};

std::ostream &operator<<(std::ostream &out, Form const &form);