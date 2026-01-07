//
// Created by tjooris on 1/5/26.
//

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		virtual void execute(const Bureaucrat& executor) const;
		std::string getTarget() const;
};


#endif //CPP_MODULE_05_ROBOTOMYREQUESTFORM_HPP