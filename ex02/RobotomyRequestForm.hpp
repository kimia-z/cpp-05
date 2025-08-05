#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>


class RobotomyRequestForm : public AForm
{
private:
	const std::string	_target;
public:
	RobotomyRequestForm(const std::string &target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &source);
	RobotomyRequestForm &operator = (const RobotomyRequestForm &source);

	void	execute(const Bureaucrat &executor) const override;
};

#endif
