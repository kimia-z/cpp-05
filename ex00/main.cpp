#include "Bureaucrat.hpp"

int main() {
	
	std::cout << "--- TEST 1: Valid Bureaucrat Creation ---" << std::endl;
	try {
		Bureaucrat bob("Bob", 50);
		std::cout << bob << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- TEST 2: Grade Too High Exception (Constructor) ---" << std::endl;
	try {
		Bureaucrat invalidBob("Invalid Bob", 0); // Grade 0 is too high
		std::cout << invalidBob << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) { // Catch specific exception
		std::cerr << "Caught exception (specific): " << e.what() << std::endl;
	} catch (const std::exception& e) { // Catch general std::exception
		std::cerr << "Caught exception (general): " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- TEST 3: Grade Too Low Exception (Constructor) ---" << std::endl;
	try {
		Bureaucrat invalidAlice("Invalid Alice", 151); // Grade 151 is too low
		std::cout << invalidAlice << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) { // Catch specific exception
		std::cerr << "Caught exception (specific): " << e.what() << std::endl;
	} catch (const std::exception& e) { // Catch general std::exception
		std::cerr << "Caught exception (general): " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- TEST 4: Incrementing Grade ---" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 3);
		std::cout << charlie << std::endl;
		charlie.incrementGrade(); // Grade 2
		std::cout << charlie << std::endl;
		charlie.incrementGrade(); // Grade 1
		std::cout << charlie << std::endl;
		charlie.incrementGrade(); // Should throw GradeTooHighException
		std::cout << charlie << std::endl; // This line should not be reached
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- TEST 5: Decrementing Grade ---" << std::endl;
	try {
		Bureaucrat david("David", 148);
		std::cout << david << std::endl;
		david.decrementGrade(); // Grade 149
		std::cout << david << std::endl;
		david.decrementGrade(); // Grade 150
		std::cout << david << std::endl;
		david.decrementGrade(); // Should throw GradeTooLowException
		std::cout << david << std::endl; // This line should not be reached
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- TEST 6: Copy Constructor and Assignment Operator ---" << std::endl;
	try {
		Bureaucrat original("Original", 75);
		std::cout << original << std::endl;

		Bureaucrat copyConstructed = original; // Uses copy constructor
		std::cout << "Copy constructed: " << copyConstructed << std::endl;

		Bureaucrat assigned("Assigned", 100);
		std::cout << assigned << std::endl;
		assigned = original; // Uses copy assignment operator
		std::cout << "Assigned: " << assigned << std::endl;

		// Verify that original and copy are independent (for _grade)
		original.incrementGrade();
		std::cout << "Original after increment: " << original << std::endl;
		std::cout << "Copy constructed (unchanged): " << copyConstructed << std::endl;
		std::cout << "Assigned (unchanged): " << assigned << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	return 0;
}