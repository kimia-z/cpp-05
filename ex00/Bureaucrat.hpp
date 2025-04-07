#pragma once

#include <string>
#include <iostream>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:

	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &source);
	Bureaucrat &operator = (const Bureaucrat &source);
	~Bureaucrat();

	const std::string &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();
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
