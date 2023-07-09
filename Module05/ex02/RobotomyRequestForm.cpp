#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45), target(target) {
    std::srand(std::time(NULL)); // Seed the random number generator
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    AForm::execute(executor); // Check if form is signed and grade is high enough

    std::cout << "Drilling noises..." << std::endl;
    bool success = (std::rand() % 2) == 0;
    if (success)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed for " << target << std::endl;
}
