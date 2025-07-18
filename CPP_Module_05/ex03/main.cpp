#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void printSeparator() {
    std::cout << "\n------------------------------------------\n";
}

int main() {
    // Seed for random number generation (used by RobotomyRequestForm)
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Create bureaucrats with different clearance levels
    Bureaucrat boss("Boss", 1);         // Can sign and execute any form
    Bureaucrat manager("Manager", 25);  // Can sign but not execute all forms
    Bureaucrat employee("Employee", 140);   // Can sign only low-level forms

    std::cout << "\n=== BUREAUCRAT INFO ===\n";
    std::cout << boss << std::endl;
    std::cout << manager << std::endl;
    std::cout << employee << std::endl;

    printSeparator();
    std::cout << "=== INTERN BASIC FUNCTIONALITY ===\n";

    // Create an intern
    Intern someRandomIntern;

    // Test creating each type of form
    std::cout << "\n--- Standard form creation ---\n";
    AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "Garden");
    AForm* robot = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Zaphod");

    printSeparator();
    std::cout << "=== TESTING CASE SENSITIVITY ===\n";
    // Test with mixed case (may or may not work depending on implementation)
    try {
        std::cout << "Attempting to create form with mixed case: 'RoBoToMy ReQuEsT'...\n";
        AForm* mixedCase = someRandomIntern.makeForm("RoBoToMy ReQuEsT", "C3PO");
        if (mixedCase) {
            std::cout << "Success! Case insensitive form creation works.\n";
            std::cout << *mixedCase << std::endl;
            delete mixedCase;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
        std::cout << "Note: Case sensitive form names are required.\n";
    }

    printSeparator();
    std::cout << "=== TESTING INVALID FORM TYPES ===\n";
    // Test with invalid form name
    try {
        std::cout << "Attempting to create a 'coffee making' form...\n";
        AForm* invalid = someRandomIntern.makeForm("coffee making", "Office");
        if (invalid) {
            delete invalid;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "Attempting to create form with empty name...\n";
        AForm* empty = someRandomIntern.makeForm("", "Nowhere");
        if (empty) {
            delete empty;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printSeparator();
    std::cout << "=== TESTING FORMS WITH BUREAUCRATS ===\n";

    // Test the forms with bureaucrats of different levels
    if (shrub) {
        std::cout << "\n--- Shrubbery Creation Form (Garden) ---\n";
        std::cout << *shrub << std::endl;
        employee.signForm(*shrub);  // Should succeed (grade 145 required)
        employee.executeForm(*shrub); // Should fail (grade 137 required)
        manager.executeForm(*shrub);  // Should succeed
        delete shrub;
    }

    if (robot) {
        std::cout << "\n--- Robotomy Request Form (Bender) ---\n";
        std::cout << *robot << std::endl;
        employee.signForm(*robot);  // Should fail (grade 72 required)
        manager.signForm(*robot);   // Should succeed
        manager.executeForm(*robot); // Should fail (grade 45 required)
        boss.executeForm(*robot);    // Should succeed
        delete robot;
    }

    if (pardon) {
        std::cout << "\n--- Presidential Pardon Form (Zaphod) ---\n";
        std::cout << *pardon << std::endl;
        manager.signForm(*pardon);  // Should fail (grade 25 required)
        boss.signForm(*pardon);     // Should succeed
        boss.executeForm(*pardon);   // Should succeed
        delete pardon;
    }

    printSeparator();
    std::cout << "=== STRESS TEST: MULTIPLE FORMS ===\n";
    // Create and immediately use multiple forms
    for (int i = 0; i < 3; i++) {
        std::string subject = "Subject-";
        subject += static_cast<char>('0' + i); // Convert i to char and append
        AForm* form = someRandomIntern.makeForm("robotomy request", subject);
        if (form) {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }

    std::cout << "\nAll tests completed!\n";
    return 0;
}
