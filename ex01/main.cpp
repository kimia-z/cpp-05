#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	std::cout << "--- TEST 1: Bureaucrat with high enough grade signs a form ---" << std::endl;
	try {
		Bureaucrat highGradeBureaucrat("Bob", 40);
		Form easyForm("28B", 50, 100);

		std::cout << highGradeBureaucrat << std::endl;
		std::cout << easyForm << std::endl;

		highGradeBureaucrat.signForm(easyForm);
		std::cout << easyForm << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- TEST 2: Bureaucrat with too low grade fails to sign a form ---" << std::endl;
	try {
		Bureaucrat lowGradeBureaucrat("Alice", 60);
		Form hardForm("28C", 50, 100);

		std::cout << lowGradeBureaucrat << std::endl;
		std::cout << hardForm << std::endl;

		lowGradeBureaucrat.signForm(hardForm);
		std::cout << hardForm << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- TEST 3: Invalid Form creation (too high grade) ---" << std::endl;
	try {
		Form invalidForm("Invalid", 0, 100);
		std::cout << invalidForm << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- TEST 4: Invalid Form creation (too low grade) ---" << std::endl;
	try {
		Form invalidForm("Invalid 2", 151, 100);
		std::cout << invalidForm << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}