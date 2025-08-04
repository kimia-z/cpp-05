#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45), _target(target)
{}
RobotomyRequestForm::~RobotomyRequestForm()
{}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source) : AForm(source), _target(source._target)
{}
RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &source)
{
	AForm::operator=(source);
	return (*this);
}

//Makes some drilling noises, then informs that <target> has been robotomized successfully 50% of the time. Otherwise, it informs that the robotomy failed.
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{}