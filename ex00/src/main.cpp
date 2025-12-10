
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#include "doctest.h"

#include "Bureaucrat.hpp"
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



/*
int main()
{
    try {
        Bureaucrat b1("Alice", 75);
        std::cout << b1.getName() << " created with grade " << b1.getGrade() << std::endl;

        b1.incrementGrade();
        std::cout << b1.getName() << " incremented to grade " << b1.getGrade() << std::endl;

        b1.decrementGrade();
        std::cout << b1.getName() << " decremented to grade " << b1.getGrade() << std::endl;

        Bureaucrat b2("Bob", 0);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 151);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
*/