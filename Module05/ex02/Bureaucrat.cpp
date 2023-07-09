#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name) {
    grade = other.grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        grade = other.grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(AForm& form) const {
    try {
        form.beSigned(*this);
        std::cout << *this << " signed form: " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << *this << " cannot sign form: " << form.getName();
        std::cerr << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << *this << " executed form: " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << *this << " cannot execute form: " << form.getName();
        std::cerr << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << "Bureaucrat: " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade();
    return os;
}
