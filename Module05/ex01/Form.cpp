#include "Form.hpp"

Form::Form(std::string const &_name, int _gradeToSign, int _gradeToExecute) :
    name(_name),
    isSigned(false),
    gradeToSign(_gradeToSign),
    gradeToExecute(_gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low.");
}

std::string const &Form::getName() const
{
    return (name);
}

bool Form::getIsSigned() const
{
    return (isSigned);
}

int Form::getGradeToSign() const
{
    return (gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (gradeToExecute);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    isSigned = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << "Form " << form.getName() << " is ";
    if (!form.getIsSigned())
        out << "not ";
    out << "signed. Grade to sign: " << form.getGradeToSign() << ". Grade to execute: " << form.getGradeToExecute() << ".";
    return (out);
}