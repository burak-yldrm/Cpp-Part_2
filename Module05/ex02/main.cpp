#include "AForm.hpp"

#include "Bureaucrat.hpp"

#include "ShrubberyCreationForm.hpp"


#include "RobotomyRequestForm.hpp"

#include "PresidentialPardonForm.hpp"

int main() {
    // Create a Bureaucrat
    Bureaucrat bureaucrat("John Doe", 150);

    try {
        // Create a ShrubberyCreationForm
        ShrubberyCreationForm shrubberyForm("garden");

        // Try to execute the form
        shrubberyForm.execute(bureaucrat);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // Create a RobotomyRequestForm
        RobotomyRequestForm robotomyForm("target");

        // Try to execute the form
        robotomyForm.execute(bureaucrat);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // Create a PresidentialPardonForm
        PresidentialPardonForm pardonForm("target");

        // Try to execute the form
        pardonForm.execute(bureaucrat);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
