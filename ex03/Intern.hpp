#ifndef INTERN_HPP
#define INTERN_HPP

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class Intern
{
public:

	Intern();
	~Intern();
	Intern(const Intern &source);
	Intern &operator = (const Intern &source);

	/*his creates a new type name, formsCreationPointer, which is a pointer to a const member function
		of the Intern class. This member function takes a const std::string& as an argument and returns a pointer to an AForm.*/
	typedef AForm *(Intern::*formsCreationPointer)(const std::string &target) const; 
	
	// List of FormPairs
	struct FormPair
	{
		formsCreationPointer	_ptr; // point to : shrubberyCreation() / robotomyCreation() / presidentialCreation()
		std::string				_formName;	  // 	shrubbery			/ robotomy			 / presidential
		FormPair(formsCreationPointer ptr, std::string formName) : _ptr(ptr), _formName(formName) {}
	};
	static const FormPair	_formPairs[3];

	// Main function
	AForm *makeForm(const std::string &formName, const std::string &target);

	// Exception
	class UnknownFormException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:

	AForm*		shrubberyCreation(const std::string &target) const;
	AForm*		robotomyCreation(const std::string &target) const;
	AForm*		presidentialCreation(const std::string &target) const;
};

#endif