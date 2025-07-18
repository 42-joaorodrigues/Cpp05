#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing Form Creation ===" << std::endl;

    try {
        // Valid form creation
        Form validForm("Tax Form", 50, 25);
        std::cout << "Created: " << validForm << std::endl;

        // Invalid form creation - grade too high
        try {
            Form invalidHigh("Invalid High", 0, 50);
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Invalid form creation - grade too low
        try {
            Form invalidLow("Invalid Low", 50, 151);
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Bureaucrat Creation ===" << std::endl;

    try {
        // Valid bureaucrats
        Bureaucrat alice("Alice", 30);
        Bureaucrat bob("Bob", 60);
        Bureaucrat charlie("Charlie", 100);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << charlie << std::endl;

        // Invalid bureaucrat - grade too high
        try {
            Bureaucrat invalid("Invalid", 0);
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Invalid bureaucrat - grade too low
        try {
            Bureaucrat invalid("Invalid", 151);
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Form Signing ===" << std::endl;

    try {
        // Create forms with different requirements
        Form easyForm("Easy Form", 100, 50);
        Form mediumForm("Medium Form", 50, 25);
        Form hardForm("Hard Form", 20, 10);

        // Create bureaucrats with different grades
        Bureaucrat junior("Junior", 80);
        Bureaucrat senior("Senior", 40);
        Bureaucrat director("Director", 15);

        std::cout << "\nInitial forms:" << std::endl;
        std::cout << easyForm << std::endl;
        std::cout << mediumForm << std::endl;
        std::cout << hardForm << std::endl;

        std::cout << "\nInitial bureaucrats:" << std::endl;
        std::cout << junior << std::endl;
        std::cout << senior << std::endl;
        std::cout << director << std::endl;

        std::cout << "\n--- Junior trying to sign forms ---" << std::endl;
        junior.signForm(easyForm);      // Should succeed (80 <= 100)
        junior.signForm(mediumForm);    // Should fail (80 > 50)
        junior.signForm(hardForm);      // Should fail (80 > 20)

        std::cout << "\n--- Senior trying to sign forms ---" << std::endl;
        senior.signForm(easyForm);      // Should succeed (40 <= 100)
        senior.signForm(mediumForm);    // Should succeed (40 <= 50)
        senior.signForm(hardForm);      // Should fail (40 > 20)

        std::cout << "\n--- Director trying to sign forms ---" << std::endl;
        director.signForm(easyForm);    // Should succeed (15 <= 100)
        director.signForm(mediumForm);  // Should succeed (15 <= 50)
        director.signForm(hardForm);    // Should succeed (15 <= 20)

        std::cout << "\nFinal form states:" << std::endl;
        std::cout << easyForm << std::endl;
        std::cout << mediumForm << std::endl;
        std::cout << hardForm << std::endl;

    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Grade Increment/Decrement ===" << std::endl;

    try {
        Bureaucrat test("Test", 75);
        std::cout << "Initial: " << test << std::endl;

        // Increment grade (improve rank)
        test.incrementGrade();
        std::cout << "After increment: " << test << std::endl;

        // Decrement grade (worsen rank)
        test.decrementGrade();
        test.decrementGrade();
        std::cout << "After two decrements: " << test << std::endl;

        // Test boundary conditions
        Bureaucrat topBureaucrat("Top", 1);
        std::cout << "Top bureaucrat: " << topBureaucrat << std::endl;

        try {
            topBureaucrat.incrementGrade(); // Should throw exception
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        Bureaucrat bottomBureaucrat("Bottom", 150);
        std::cout << "Bottom bureaucrat: " << bottomBureaucrat << std::endl;

        try {
            bottomBureaucrat.decrementGrade(); // Should throw exception
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Copy Constructor and Assignment ===" << std::endl;

    try {
        Form originalForm("Original", 42, 21);
        std::cout << "Original form: " << originalForm << std::endl;

        // Test copy constructor
        Form copiedForm(originalForm);
        std::cout << "Copied form: " << copiedForm << std::endl;

        // Test assignment operator
        Form assignedForm("Temp", 1, 1);
        assignedForm = originalForm;
        std::cout << "Assigned form: " << assignedForm << std::endl;

        // Sign original and check if copies are affected
        Bureaucrat signer("Signer", 30);
        signer.signForm(originalForm);

        std::cout << "\nAfter signing original:" << std::endl;
        std::cout << "Original: " << originalForm << std::endl;
        std::cout << "Copied: " << copiedForm << std::endl;
        std::cout << "Assigned: " << assignedForm << std::endl;

    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
