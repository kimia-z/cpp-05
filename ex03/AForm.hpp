#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
public:
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	virtual ~AForm();
	AForm(const AForm &source);
	AForm &operator = (const AForm &source);

	// Getters
	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	// Modifiers
	void		beSigned(const Bureaucrat &source);

	// Helper
	void		checkGrade(int grade);

	// Exceptions
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
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	// Execute
	virtual void	execute(Bureaucrat const &executor) const = 0;

};

std::ostream &operator << (std::ostream &out, const AForm &source);

#endif