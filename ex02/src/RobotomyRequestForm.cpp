//
// Created by tjooris on 1/5/26.
//

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <sys/time.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : Form("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : Form(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other) {
        Form::operator=(other);
        _target = other._target;
    }
    return *this;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "Bzzzz... Vrrrrr... *drilling noises*" << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
}