/*
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#include "doctest.h"
*/
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>




int main()
{
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1.getName() << " created with grade " << b1.getGrade() << std::endl;

        ShrubberyCreationForm form1("Home");
        RobotomyRequestForm form2("Bob");
        PresidentialPardonForm form3("Charlie");

        b1.signForm(form1);
        b1.executeForm(form1);

        b1.signForm(form2);
        b1.executeForm(form2);

        b1.signForm(form3);
        b1.executeForm(form3);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}