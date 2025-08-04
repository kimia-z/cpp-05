#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(const std::string &target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &source);
	ShrubberyCreationForm &operator = (const ShrubberyCreationForm &source);

	void	execute(Bureaucrat const &executor) const;
};

#endif
