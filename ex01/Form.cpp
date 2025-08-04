#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}
Form::~Form()
{}
Form::Form(const Form &source)
	: _name(source._name), _isSigned(source._isSigned), _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute)
{}
Form &Form::operator = (const Form &source)
{
	if (this != &source)
	{
		this->_isSigned = source._isSigned;
	}
	return (*this);
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw() { return "Form grade is too high";}
const char *Form::GradeTooLowException::what() const throw() { return "Form grade is too low";}

// Getters
std::string	Form::getName() const { return _name;}
bool		Form::getIsSigned() const { return _isSigned;}
int			Form::getGradeToSign() const { return _gradeToSign;}
int			Form::getGradeToExecute() const { return _gradeToExecute;}

// Modifiers
void	Form::beSigned(const Bureaucrat &source)
{
	if (getGradeToSign() < source.getGrade()){
		throw Form::GradeTooLowException();
	}
	_isSigned = true;
}
// Helper
void Form::checkGrade(int grade)
{
	if (grade < 1){
		throw Form::GradeTooHighException();
	}
	if (grade > 150){
		throw Form::GradeTooLowException();
	}
}

std::ostream &operator << (std::ostream &out, const Form &source)
{
	out << "Form " << source.getName() << " is " << (source.getIsSigned() ? "signed" : "not signed") << std::endl;
	return out;
}