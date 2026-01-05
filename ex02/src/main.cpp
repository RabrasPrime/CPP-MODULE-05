/*
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#include "doctest.h"
*/
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
/*
TEST_CASE("Bureaucrat and Form Interaction") {
    Bureaucrat b("Alice", 50);
    Form f("TopSecret", 45, 30);

    SUBCASE("Signing Form Successfully") {
        b.incrementGrade();
        b.incrementGrade();
        b.incrementGrade();
        b.incrementGrade();
        b.incrementGrade();
        CHECK_NOTHROW(f.beSigned(b));
        CHECK(f.isSigned() == true);
    }

    SUBCASE("Signing Form Fails Due to Low Grade") {
        CHECK_THROWS_AS(f.beSigned(b), Form::GradeTooLowException);
        CHECK(f.isSigned() == false);
    }
}

TEST_CASE("Form Creation") {
    SUBCASE("Valid Grades") {
        Form f("Confidential", 100, 50);
        CHECK(f.getName() == "Confidential");
        CHECK(f.isSigned() == false);
        CHECK(f.getSignGrade() == 100);
        CHECK(f.getExecuteGrade() == 50);
    }

    SUBCASE("Sign Grade Too High") {
        CHECK_THROWS_AS(Form("InvalidForm", 0, 50), Form::GradeTooHighException);
    }

    SUBCASE("Execute Grade Too High") {
        CHECK_THROWS_AS(Form("InvalidForm", 100, 0), Form::GradeTooHighException);
    }

    SUBCASE("Sign Grade Too Low") {
        CHECK_THROWS_AS(Form("InvalidForm", 151, 50), Form::GradeTooLowException);
    }

    SUBCASE("Execute Grade Too Low") {
        CHECK_THROWS_AS(Form("InvalidForm", 100, 151), Form::GradeTooLowException);
    }
}
*/

int main()
{
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1.getName() << " created with grade " << b1.getGrade() << std::endl;

        b1.incrementGrade();
        std::cout << b1.getName() << " incremented to grade " << b1.getGrade() << std::endl;

        Form f1("TopSecret", 70, 50);
        std::cout << "Form " << f1.getName() << " created with sign grade " << f1.getSignGrade() << std::endl;

        b1.signForm(f1);
        f1.beSigned(b1);
        b1.signForm(f1);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}