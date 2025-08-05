#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
		: AForm(target, 72, 45), _target(target)
{srand(time(0));}
RobotomyRequestForm::~RobotomyRequestForm()
{}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source)
		: AForm(source), _target(source._target)
{srand(time(0));}
RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &source)
{
	AForm::operator=(source);
	return (*this);
}

//Makes some drilling noises, then informs that <target> has been robotomized successfully 50% of the time. Otherwise, it informs that the robotomy failed.
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
	std::cout << "\n*******some drilling noises*******" << std::endl;
	if ((std::rand() % 2) == 0){
		std::cout << getName() << " has been robotomized successfully!" << std::endl;
		return;
	}
	std::cout << getName() << " has been failed to robotomized!" << std::endl;
}