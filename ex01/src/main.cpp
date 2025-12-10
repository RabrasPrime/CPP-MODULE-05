
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#include "doctest.h"

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

TEST_CASE("Bureaucrat and Form Interaction") {
    Bureaucrat b("Alice", 50);
    Form f("TopSecret", 45, 30);

    SUBCASE("Signing Form Successfully") {
        b.incrementGrade(); // Grade 49
        b.incrementGrade(); // Grade 48
        b.incrementGrade(); // Grade 47
        b.incrementGrade(); // Grade 46
        b.incrementGrade(); // Grade 45
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

