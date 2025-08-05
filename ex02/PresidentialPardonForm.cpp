#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
		: AForm(target, 25, 5), _target(target)
{}
PresidentialPardonForm::~PresidentialPardonForm()
{}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &source)
		: AForm(source), _target(source._target)
{}
PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &source)
{
	AForm::operator=(source);
	return (*this);
}

// Informs that <target> has been pardoned by Zaphod Beeblebrox.
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}