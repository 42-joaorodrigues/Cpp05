#include "Intern.hpp"
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

// Default constructor
Intern::Intern() {}

// Copy constructor
Intern::Intern(const Intern& other) {
    (void)other; // Unused parameter
}

// Copy assignment operator
Intern& Intern::operator=(const Intern& other) {
    (void)other; // Unused parameter - properly silencing the warning
    return *this;
}

// Destructor
Intern::~Intern() {}

// Helper functions to create different types of forms
static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// Exception implementation
const char* Intern::UknownFormException::what() const throw() {
    return "Error: Unknown form type requested";
}

// makeForm implementation
AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    // Define form types and their corresponding creation functions
    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // Array of function pointers (C++98 compatible)
    AForm* (*formFunctions[3])(const std::string&) = {
        createShrubbery,
        createRobotomy,
        createPresidential
    };

    // Find matching form type
    for (int i = 0; i < 3; ++i) {
        if (name == formNames[i]) {
            AForm* form = formFunctions[i](target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }

    // If form type not found, throw exception and print error
    std::cout << "Intern cannot create form: " << name << " (unknown form type)" << std::endl;
    throw UknownFormException();
    return NULL; // Never reached, but prevents compiler warning
}
