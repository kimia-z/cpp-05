#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}
AForm::~AForm()
{}
AForm::AForm(const AForm &source)
	: _name(source._name), _isSigned(source._isSigned), _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute)
{}
AForm &AForm::operator = (const AForm &source)
{
	if (this != &source)
	{
		this->_isSigned = source._isSigned;
	}
	return (*this);
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw() { return "AForm grade is too high";}
const char *AForm::GradeTooLowException::what() const throw() { return "AForm grade is too low";}

// Getters
std::string	AForm::getName() const { return _name;}
bool		AForm::getIsSigned() const { return _isSigned;}
int			AForm::getGradeToSign() const { return _gradeToSign;}
int			AForm::getGradeToExecute() const { return _gradeToExecute;}

// Modifiers
void	AForm::beSigned(const Bureaucrat &source)
{
	if (getGradeToSign() < source.getGrade()){
		throw AForm::GradeTooLowException();
	}
	_isSigned = true;
}
// Helper
void AForm::checkGrade(int grade)
{
	if (grade < 1){
		throw AForm::GradeTooHighException();
	}
	if (grade > 150){
		throw AForm::GradeTooLowException();
	}
}

std::ostream &operator << (std::ostream &out, const AForm &source)
{
	out << "AForm " << source.getName() << " is " << (source.getIsSigned() ? "signed" : "not signed") << std::endl;
	return out;
}