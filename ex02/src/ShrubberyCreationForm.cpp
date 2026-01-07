//
// Created by tjooris on 1/5/26.
//

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowException();

    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (!outfile) {
        std::cout << "Error creating file: " << _target + "_shrubbery" << std::endl;
        return;
    }

    outfile << "          &&& &&  & &&\n"
               "      && &\\//&\\|& ()|/ @, &&\n"
               "      &\\//(/&/&||/& /_/)_&/_&\n"
               "   &() &\\//&|()|/&\\/ '%' & ()\n"
               "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
               "&&   && & &| &| /& & % ()& /&&\n"
               " ()&_---()&\\&\\|&&-&&--%---()~\n"
               "      &&     \\|||\n"
               "             |||\n"
               "             |||\n"
               "             |||\n"
               "       , -=-~  .-^- _\n"
               "              `\n";
    outfile.close();
}

std::string ShrubberyCreationForm::getTarget() const {
    return _target;
}