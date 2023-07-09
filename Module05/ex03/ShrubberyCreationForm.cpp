#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation Form", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    AForm::execute(executor); // Check if form is signed and grade is high enough

    std::ofstream outputFile((target + "_shrubbery").c_str());
    if (!outputFile)
        throw std::runtime_error("Failed to open output file");

    outputFile << "    # #### ####" << std::endl;
    outputFile << "  ### \\/#|### |/####" << std::endl;
    outputFile << " ##\\/#/ \\||/##/_/##/_#" << std::endl;
    outputFile << "   \\/#/\\/ \\/#//###\\/##" << std::endl;
    outputFile << "    #/ \\/ \\/ # / _ \\# #" << std::endl;
    outputFile << "         \\__/\\__/  \\__/\\__/" << std::endl;

    outputFile.close();
}
