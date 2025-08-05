#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
		: AForm(target, 145, 137), _target(target)
{}
ShrubberyCreationForm::~ShrubberyCreationForm()
{}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source)
		: AForm(source), _target(source._target)
{}
ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &source)
{
	AForm::operator=(source);
	return (*this);
}


// Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
	// Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
	std::ofstream outfile(_target + "_shrubbery");
	if (!outfile.is_open()) {
		std::cerr << "couldn't open the file to write in" << std::endl;
		return ;
	}
	std::string tree = 
	"     /\\\n"
	"    /**\\\n"
	"   /****\\\n"
	"  /******\\\n"
	" /********\\\n"
	"    |||\n";
	outfile << tree;
	outfile.close();
}