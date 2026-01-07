//
// Created by tjooris on 1/7/26.
//

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);

		AForm* makeForm(const std::string& formName, const std::string& target) const;

		class UnknownFormException : public std::exception {
			public:
				const char* what() const throw();
		};
};


#endif //CPP_MODULE_05_INTERN_HPP