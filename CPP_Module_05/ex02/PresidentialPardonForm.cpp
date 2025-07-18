#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("Default") {}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {}

// Copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        // can't copy _target
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

void PresidentialPardonForm::executeAction() const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

