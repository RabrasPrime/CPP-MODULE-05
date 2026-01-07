//
// Created by tjooris on 1/5/26.
//

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		virtual void execute(const Bureaucrat& executor) const;
		std::string getTarget() const;
};


#endif //CPP_MODULE_05_PRESIDENTIALPARDONFORM_HPP