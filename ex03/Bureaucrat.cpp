#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	checkGrade(grade);
	_grade = grade;
	// std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {}


Bureaucrat::Bureaucrat(const Bureaucrat &source) : _name(source._name), _grade(source._grade) {}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &source)
{
	if (this != &source)
		this->_grade = source._grade;
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

void Bureaucrat::checkGrade(int grade)
{
	if (grade < 1){
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150){
		throw Bureaucrat::GradeTooLowException();
	}
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	checkGrade(_grade - 1);
	_grade -= 1;
	std::cout << "The grade incremented!" << std::endl;;
}

void Bureaucrat::decrementGrade()
{
	checkGrade(_grade + 1);
	_grade += 1;
	std::cout << "The grade decremented!" << std::endl;
}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << ".\n";
	return out;
}

// Ex01:Form
void Bureaucrat::signForm(AForm &source)
{
	try{
		source.beSigned(*this);
		std::cout << getName() << " signed " << source.getName() << "!" << std::endl;
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cout << getName() << " couldn’t sign " << source.getName()
				<< " because " << e.what() << "!" << std::endl;
	}
}

// Ex02

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << "!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName()
				<< " because " << e.what() << "!" << std::endl;
	}
}