//
// Created by tjooris on 1/7/26.
//

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

const char* Intern::UnknownFormException::what() const throw() {
	return "Intern Error: Unknown form type requested.";
}

static AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*formCreators[3])(const std::string&) = {
		createShrubbery,
		createRobotomy,
		createPresidential
	};

	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return formCreators[i](target);
		}
	}
	throw UnknownFormException();
}