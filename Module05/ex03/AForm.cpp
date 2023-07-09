#include "AForm.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(false) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute), isSigned(other.isSigned) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

const std::string& AForm::getName() const {
    return name;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
	std::cout << this->getName() << ", executed from " << executor.getName();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName();
    os << ", Grade to Sign: " << form.getGradeToSign();
    os << ", Grade to Execute: " << form.getGradeToExecute();
    os << ", Is Signed: " << (form.getIsSigned() ? "Yes" : "No");
    return os;
}
