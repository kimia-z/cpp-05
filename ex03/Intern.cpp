#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const Intern::FormPair Intern::_formPairs[3] = {
		{&Intern::presidentialCreation, "presidential"},
		{&Intern::robotomyCreation, "robotomy"},
		{&Intern::shrubberyCreation, "shrubbery"}
};

Intern::Intern()
{
}
Intern::~Intern()
{}
Intern::Intern(const Intern &source)
{
	*this = source;
}
Intern &Intern::operator = (const Intern &source)
{
	(void)source;
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	for (int i = 0; i < 3; i++)
	{
		if (_formPairs[i]._formName == formName)
		{
			std::cout << "Found the pair for " << formName << std::endl;
			return (this->*_formPairs[i]._ptr)(target);
		}
	}
	throw Intern::UnknownFormException();
	return nullptr;
}

AForm*	Intern::shrubberyCreation(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}
AForm*	Intern::robotomyCreation(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}
AForm*	Intern::presidentialCreation(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

// Exceptions
const char *Intern::UnknownFormException::what() const throw() { return "Unknown form"; }