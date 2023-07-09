#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form form("Form", 130, 2);
        Bureaucrat bureaucrat("Bureaucrat", 5);
        bureaucrat.signForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}