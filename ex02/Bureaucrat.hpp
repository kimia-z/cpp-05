#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

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

	// Ex02
	void				executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat);

/*
Now that you have basic forms, it’s time to create a few more that actually do something.
In all cases, the base class Form must be an abstract class and should therefore be
renamed AForm. Keep in mind that the form’s attributes need to remain private and
that they belong to the base class.
Add the following concrete classes:
• ShrubberyCreationForm: Required grades: sign 145, exec 137
Creates a file <target>_shrubbery in the working directory and writes ASCII trees
inside it.
• RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.
• PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox.
All of them take only one parameter in their constructor: the target of the form. For
example, "home" if you want to plant shrubbery at home.
Now, add the execute(Bureaucrat const & executor) const member function to
the base form and implement a function to execute the form’s action in the concrete
classes. You must check that the form is signed and that the grade of the bureaucrat attempting to execute the form is high enough. Otherwise, throw an appropriate exception.
Whether you check the requirements in every concrete class or in the base class (and
then call another function to execute the form) is up to you. However, one way is more
elegant than the other.
Lastly, add the executeForm(AForm const & form) const member function to the
Bureaucrat class. It must attempt to execute the form. If successful, print something like:
<bureaucrat> executed <form>
If not, print an explicit error message.
*/
