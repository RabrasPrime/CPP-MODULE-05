
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#include "doctest.h"

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

TEST_CASE("Bureaucrat Creation") {
    SUBCASE("Valid Grade") {
        Bureaucrat b("Alice", 75);
        CHECK(b.getName() == "Alice");
        CHECK(b.getGrade() == 75);
    }

    SUBCASE("Grade Too High") {
        CHECK_THROWS_AS(Bureaucrat("Bob", 0), Bureaucrat::GradeTooHighException);
    }

    SUBCASE("Grade Too Low") {
        CHECK_THROWS_AS(Bureaucrat("Charlie", 151), Bureaucrat::GradeTooLowException);
    }
}

TEST_CASE("Bureaucrat Grade Modification") {
    Bureaucrat b("David", 100);

    SUBCASE("Increment Grade") {
        b.incrementGrade();
        CHECK(b.getGrade() == 99);
    }

    SUBCASE("Decrement Grade") {
        b.decrementGrade();
        CHECK(b.getGrade() == 101);
    }

    SUBCASE("Increment Grade Too High") {
        Bureaucrat high("Eve", 1);
        CHECK_THROWS_AS(high.incrementGrade(), Bureaucrat::GradeTooHighException);
    }

    SUBCASE("Decrement Grade Too Low") {
        Bureaucrat low("Frank", 150);
        CHECK_THROWS_AS(low.decrementGrade(), Bureaucrat::GradeTooLowException);
    }
}

TEST_CASE("Bureaucrat and AForm Interaction") {
    Bureaucrat b("Alice", 20);
    ShrubberyCreationForm shrubberyForm("Home");
    RobotomyRequestForm robotomyForm("Bob");
    PresidentialPardonForm pardonForm("Charlie");

    SUBCASE("Signing Forms Successfully") {
        b.incrementGrade();
        b.incrementGrade();
        b.incrementGrade();
        b.incrementGrade();
        b.incrementGrade();
        CHECK_NOTHROW(shrubberyForm.beSigned(b));
        CHECK(shrubberyForm.isSigned() == true);
        CHECK_NOTHROW(robotomyForm.beSigned(b));
        CHECK(robotomyForm.isSigned() == true);
        CHECK_NOTHROW(pardonForm.beSigned(b));
        CHECK(pardonForm.isSigned() == true);
    }

	Bureaucrat lowGradeBureaucrat("Dave", 150);

    SUBCASE("Signing Forms Fails Due to Low Grade") {
        CHECK_THROWS_AS(shrubberyForm.beSigned(lowGradeBureaucrat), AForm::GradeTooLowException);
        CHECK(shrubberyForm.isSigned() == false);
        CHECK_THROWS_AS(robotomyForm.beSigned(lowGradeBureaucrat), AForm::GradeTooLowException);
        CHECK(robotomyForm.isSigned() == false);
        CHECK_THROWS_AS(pardonForm.beSigned(lowGradeBureaucrat), AForm::GradeTooLowException);
        CHECK(pardonForm.isSigned() == false);
    }
}

TEST_CASE("Executing AForms") {
    Bureaucrat b("Alice", 1);
    ShrubberyCreationForm shrubberyForm("Home");
    RobotomyRequestForm robotomyForm("Bob");
    PresidentialPardonForm pardonForm("Charlie");

    shrubberyForm.beSigned(b);
    robotomyForm.beSigned(b);
    pardonForm.beSigned(b);

    SUBCASE("Executing Forms Successfully") {
        CHECK_NOTHROW(shrubberyForm.execute(b));
        CHECK_NOTHROW(robotomyForm.execute(b));
        CHECK_NOTHROW(pardonForm.execute(b));
    }

    SUBCASE("Executing Forms Fails Due to Low Grade") {
        Bureaucrat lowGradeBureaucrat("Dave", 150);
        CHECK_THROWS_AS(shrubberyForm.execute(lowGradeBureaucrat), AForm::GradeTooLowException);
        CHECK_THROWS_AS(robotomyForm.execute(lowGradeBureaucrat), AForm::GradeTooLowException);
        CHECK_THROWS_AS(pardonForm.execute(lowGradeBureaucrat), AForm::GradeTooLowException);
    }
}

TEST_CASE("AForm Creation") {
    SUBCASE("Valid Grades") {
        ShrubberyCreationForm shrubberyForm("Home");
        CHECK(shrubberyForm.getName() == "ShrubberyCreationForm");
        CHECK(shrubberyForm.isSigned() == false);
        CHECK(shrubberyForm.getSignGrade() == 145);
        CHECK(shrubberyForm.getExecuteGrade() == 137);

        RobotomyRequestForm robotomyForm("Bob");
        CHECK(robotomyForm.getName() == "RobotomyRequestForm");
        CHECK(robotomyForm.isSigned() == false);
        CHECK(robotomyForm.getSignGrade() == 72);
        CHECK(robotomyForm.getExecuteGrade() == 45);

        PresidentialPardonForm pardonForm("Charlie");
        CHECK(pardonForm.getName() == "PresidentialPardonForm");
        CHECK(pardonForm.isSigned() == false);
        CHECK(pardonForm.getSignGrade() == 25);
        CHECK(pardonForm.getExecuteGrade() == 5);
    }
}

TEST_CASE("Intern Form Creation") {
    Intern intern;

    SUBCASE("Creating Known Forms") {
        AForm* shrubberyForm = intern.makeForm("shrubbery creation", "Home");
        CHECK(shrubberyForm->getName() == "ShrubberyCreationForm");
        delete shrubberyForm;

        AForm* robotomyForm = intern.makeForm("robotomy request", "Bob");
        CHECK(robotomyForm->getName() == "RobotomyRequestForm");
        delete robotomyForm;

        AForm* pardonForm = intern.makeForm("presidential pardon", "Charlie");
        CHECK(pardonForm->getName() == "PresidentialPardonForm");
        delete pardonForm;
    }

    SUBCASE("Creating Unknown Form") {
        CHECK_THROWS_AS(intern.makeForm("unknown form", "Target"), Intern::UnknownFormException);
    }
}

/*
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
        std::cout << "Exception: " << e.what() << std::endl;
    }
	try {
		Bureaucrat b2("Dave", 140);
        std::cout << b2.getName() << " created with grade " << b2.getGrade() << std::endl;
		ShrubberyCreationForm form1("Home2");
        RobotomyRequestForm form2("Boby");
        PresidentialPardonForm form3("Charly");

		b2.signForm(form1);
        b2.executeForm(form1);
		b2.signForm(form2);
        b2.executeForm(form2);
        b2.signForm(form3);
		b2.executeForm(form3);
	}
	catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
	}

    return 0;
}*/