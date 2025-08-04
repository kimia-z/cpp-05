#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, 145, 137)
{}
ShrubberyCreationForm::~ShrubberyCreationForm()
{}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source) : AForm(source)
{}
ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &source)
{}


// Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	
}