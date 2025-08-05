#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm
{
private:
	const std::string	_target;
public:
	ShrubberyCreationForm(const std::string &target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &source);
	ShrubberyCreationForm &operator = (const ShrubberyCreationForm &source);

	void	execute(const Bureaucrat &executor) const override;
};

#endif
