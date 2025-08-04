#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

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
	void				signForm(Form &source);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat);

/*
const std:string name
int grade(1-150)

GradeTooHighException --> throw exception
GradeTooLowException  --> throw exception

std:string &getName() const
int getGrade() const

void incrementGrade() --> throw exception
void decrementGrade() --> throw exception

overload of the insertion («) operator

1   --> highest
150 --> lowest

what should print:
<name>, bureaucrat grade <grade>.

*/
