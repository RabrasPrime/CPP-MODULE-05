/*
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#include "doctest.h"
*/
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
/*
TEST_CASE("Bureaucrat and Form Interaction") {
	Bureaucrat b("Alice", 50);
	ShrubberyCreationForm shrubberyForm("Home");
	RobotomyRequestForm robotomyForm("Bob");
	PresidentialPardonForm pardonForm("Charlie");

	SUBCASE("Signing ShrubberyCreationForm Successfully") {
		b.incrementGrade();
		b.incrementGrade();
		b.incrementGrade();
		b.incrementGrade();
		b.incrementGrade();
		CHECK_NOTHROW(shrubberyForm.beSigned(b));
		CHECK(shrubberyForm.isSigned() == true);
	}

	SUBCASE("Signing RobotomyRequestForm Fails Due to Low Grade") {
		CHECK_THROWS_AS(robotomyForm.beSigned(b), Form::GradeTooLowException);
		CHECK(robotomyForm.isSigned() == false);
	}

	SUBCASE("Signing PresidentialPardonForm Fails Due to Low Grade") {
		CHECK_THROWS_AS(pardonForm.beSigned(b), Form::GradeTooLowException);
		CHECK(pardonForm.isSigned() == false);
	}
}*/

int main()
{
	try {
		Bureaucrat b1("Alice", 2);
		std::cout << b1.getName() << " created with grade " << b1.getGrade() << std::endl;
		ShrubberyCreationForm shrubberyForm("Home");
		RobotomyRequestForm robotomyForm("Bob");
		PresidentialPardonForm pardonForm("Charlie");
		b1.signForm(shrubberyForm);
		b1.signForm(robotomyForm);
		b1.signForm(pardonForm);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}