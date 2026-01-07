//
// Created by tjooris on 1/5/26.
//

#ifndef CPP_MODULE_05_SHRUBBERYCREATIONFORM_HPP
#define CPP_MODULE_05_SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		virtual void execute(const Bureaucrat& executor) const;
		std::string getTarget() const;
};


#endif //CPP_MODULE_05_SHRUBBERYCREATIONFORM_HPP