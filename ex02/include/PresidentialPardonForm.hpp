//
// Created by tjooris on 1/5/26.
//

#ifndef CPP_MODULE_05_PRESIDENTIALPARDONFORM_HPP
#define CPP_MODULE_05_PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "Form.hpp"

class PresidentialPardonForm
{
	private:
		std::string	_target;
		virtual void executeAction() const;
	public:
		PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
};


#endif //CPP_MODULE_05_PRESIDENTIALPARDONFORM_HPP