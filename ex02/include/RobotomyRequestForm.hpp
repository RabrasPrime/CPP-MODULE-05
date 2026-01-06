//
// Created by tjooris on 1/5/26.
//

#ifndef CPP_MODULE_05_ROBOTOMYREQUESTFORM_HPP
#define CPP_MODULE_05_ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string	_target;
		virtual void executeAction() const;
	public:
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
};


#endif //CPP_MODULE_05_ROBOTOMYREQUESTFORM_HPP