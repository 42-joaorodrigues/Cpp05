#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	std::cout << "=== BUREAUCRAT TESTS ===" << std::endl;
	std::cout << std::endl;

	// Test 1: Valid bureaucrat creation
	std::cout << "Test 1: Creating valid bureaucrats" << std::endl;
	try {
		Bureaucrat highRank("Alice", 1);
		Bureaucrat midRank("Bob", 75);
		Bureaucrat lowRank("Charlie", 150);

		std::cout << highRank << std::endl;
		std::cout << midRank << std::endl;
		std::cout << lowRank << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 2: Invalid grade too high (0)
	std::cout << "Test 2: Creating bureaucrat with grade 0 (too high)" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 3: Invalid grade too low (151)
	std::cout << "Test 3: Creating bureaucrat with grade 151 (too low)" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 4: Increment grade successfully
	std::cout << "Test 4: Incrementing grade (75 -> 74)" << std::endl;
	try {
		Bureaucrat worker("Worker", 75);
		std::cout << "Before: " << worker << std::endl;
		worker.incrementGrade();
		std::cout << "After: " << worker << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 5: Decrement grade successfully
	std::cout << "Test 5: Decrementing grade (75 -> 76)" << std::endl;
	try {
		Bureaucrat worker("Worker", 75);
		std::cout << "Before: " << worker << std::endl;
		worker.decrementGrade();
		std::cout << "After: " << worker << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 6: Increment grade at maximum (grade 1)
	std::cout << "Test 6: Incrementing grade when already at maximum (1)" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		std::cout << "Before: " << boss << std::endl;
		boss.incrementGrade();
		std::cout << "After: " << boss << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 7: Decrement grade at minimum (grade 150)
	std::cout << "Test 7: Decrementing grade when already at minimum (150)" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		std::cout << "Before: " << intern << std::endl;
		intern.decrementGrade();
		std::cout << "After: " << intern << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 8: Copy constructor and assignment
	std::cout << "Test 8: Copy constructor and assignment operator" << std::endl;
	try {
		Bureaucrat original("Original", 50);
		Bureaucrat copy(original);
		Bureaucrat assigned("Temp", 100);

		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
		std::cout << "Before assignment: " << assigned << std::endl;

		assigned = original;
		std::cout << "After assignment: " << assigned << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 9: Default constructor
	std::cout << "Test 9: Default constructor" << std::endl;
	try {
		Bureaucrat defaultBureaucrat;
		std::cout << defaultBureaucrat << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== ALL TESTS COMPLETED ===" << std::endl;
	return 0;
}