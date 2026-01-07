//
// Created by tomjo on 29/11/2025.
//

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
        const std::string	_name;
		bool				_isSigned;
        const int			_signGrade;
        const int			_executeGrade;
    public:
        AForm(const std::string& name, int signGrade, int executeGrade);
        virtual ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        const std::string& getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
		const std::string& getname() const;
        void beSigned(const Bureaucrat& b);
		virtual void execute(const Bureaucrat& executor) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

		class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif //FORM_HPP
