#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp" // Include AForm to use AForm pointers
#include "Bureaucrat.hpp" // Include Bureaucrat if you want to sign/execute

#include <iostream>

int main() {
	Intern someRandomIntern;
	AForm* form1 = nullptr;
	AForm* form2 = nullptr;
	AForm* form3 = nullptr;
	AForm* form4 = nullptr;

	std::cout << "--- Test 1: Creating a 'robotomy request' form ---" << std::endl;
	try {
		form1 = someRandomIntern.makeForm("robotomy", "Bender");
		if (form1) {
			std::cout << "Successfully created: " << *form1 << std::endl;
		}
		Bureaucrat highGradeBureaucrat("AI", 1);
		highGradeBureaucrat.signForm(*form1);
		highGradeBureaucrat.executeForm(*form1);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	if (form1) delete form1;
	std::cout << std::endl;

	std::cout << "--- Test 2: Creating a 'presidential pardon' form ---" << std::endl;
	try {
		form2 = someRandomIntern.makeForm("presidential", "Zaphod");
		if (form2) {
			std::cout << "Successfully created: " << *form2 << std::endl;
		}
		Bureaucrat president("Goerge", 1);
		president.signForm(*form2);
		president.executeForm(*form2);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	if (form2) delete form2;
	std::cout << std::endl;

	std::cout << "--- Test 3: Creating a 'shrubbery creation' form ---" << std::endl;
	try {
		form3 = someRandomIntern.makeForm("shrubbery", "garden");
		if (form3) {
			std::cout << "Successfully created: " << *form3 << std::endl;
		}
		Bureaucrat mediumGrade("Human", 1);
		mediumGrade.signForm(*form3);
		mediumGrade.executeForm(*form3);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	if (form3) delete form3;
	std::cout << std::endl;

	std::cout << "--- Test 4: Trying to create an unknown form ---" << std::endl;
	try {
		form4 = someRandomIntern.makeForm("unknown form type", "nowhere");
		if (form4) {
			std::cout << "Successfully created (unexpected): " << *form4 << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "Caught expected error: " << e.what() << std::endl;
	}
	if (form4) delete form4;
	std::cout << std::endl;

	return 0;
}