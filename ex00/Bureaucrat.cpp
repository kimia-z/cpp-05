#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Defualt"), _grade(150) {}

// Bureaucrat::Bureaucrat(const std::string _name, int _grade)
// {
// 	std::cout << "Bureaucrat constructor called" << std::endl;
// }

Bureaucrat::~Bureaucrat() {}


Bureaucrat::Bureaucrat(const Bureaucrat &source) : _grade(source._grade), _name(source._name) {}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &source)
{
	if (this != &source)
		this->_grade = source._grade;
	return *this;
}

const std::string &Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	try
	{
		_grade -= 1;
		if (_grade < 1)
			throw 505;
	}
	catch(...)
	{
		std::cerr << "the grade can not increase and got out of its range!(1-150)" << '\n';
	}
	
}
// void Bureaucrat::decrementGrade();

void Bureaucrat::decrementGrade()
{
	try
	{
		_grade += 1;
		if (_grade > 150)
			throw 505;
	}
	catch(...)
	{
		std::cerr << "the grade can not decrease and got out of its range!(1-150)" << '\n';
	}
	
}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << ".\n";
	return out;
}