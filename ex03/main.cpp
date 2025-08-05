#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	std::cout << "--- TEST 1: ShrubberyCreationForm (Success) ---\n" << std::endl;
	try {
		Bureaucrat highGradeGuy("John", 130);
		ShrubberyCreationForm form1("Home");
		highGradeGuy.signForm(form1);
		highGradeGuy.executeForm(form1);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- TEST 2: RobotomyRequestForm (Success/Failure) ---\n" << std::endl;
	try {
		Bureaucrat mediumGradeGuy("Tom", 40);
		RobotomyRequestForm form2("Robotomy");
		mediumGradeGuy.signForm(form2);
		mediumGradeGuy.executeForm(form2); // 50% chance of success
		mediumGradeGuy.executeForm(form2); // 50% chance of success
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "--- TEST 3: PresidentialPardonForm (Success) ---\n" << std::endl;
	try {
		Bureaucrat president("Goerge", 3);
		PresidentialPardonForm form3("Zaphod Beeblebrox");
		president.signForm(form3);
		president.executeForm(form3);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- TEST 4: PresidentialPardonForm (Grade Too Low to execute) ---\n" << std::endl;
	try {
		Bureaucrat president("Goerge", 6);
		PresidentialPardonForm form3("Zaphod Beeblebrox");
		president.signForm(form3);
		president.executeForm(form3); // President's grade is 6, needs 5
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- TEST 5: ShrubberyCreationForm (Not Signed) ---\n" << std::endl;
	try {
		Bureaucrat highGradeGuy("John", 130);
		ShrubberyCreationForm form1("School");
		highGradeGuy.executeForm(form1); // Not signed
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}