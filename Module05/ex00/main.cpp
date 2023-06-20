#include "Bureaucrat.hpp"

int main()
{
    try
    {
        // Bureaucrat b("Bob", 150);
        // std::cout << b << std::endl;
        // b.decrementGrade();
        // std::cout << b << std::endl;
        // b.decrementGrade();
        // std::cout << b << std::endl;

        Bureaucrat c("Bob", 1);
        std::cout << c << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}