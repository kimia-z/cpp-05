#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

	void				checkGrade(int grade);

public:

	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &source);
	Bureaucrat &operator = (const Bureaucrat &source);
	~Bureaucrat();
	
	//Getters
	const std::string	&getName() const;
	int					getGrade() const;

	//Modifers
	void				incrementGrade();
	void				decrementGrade();

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	// Ex01
	void				signForm(AForm &source);

	// Ex02
	void				executeForm(AForm const &form) const;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat);

