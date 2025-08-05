#ifndef INTERN_HPP
#define INTERN_HPP

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern &source);
	Intern &operator = (const Intern &source);

	AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif