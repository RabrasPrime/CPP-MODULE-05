//
// Created by tjooris on 1/5/26.
//

#ifndef CPP_MODULE_05_SHRUBBERYCREATIONFORM_HPP
#define CPP_MODULE_05_SHRUBBERYCREATIONFORM_HPP


class ShrubberyCreationForm
{
	private:
		std::string	_target;
		virtual void executeAction() const;
	public:
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
};


#endif //CPP_MODULE_05_SHRUBBERYCREATIONFORM_HPP