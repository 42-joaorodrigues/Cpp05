#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm" ,72, 45), _target("Default") {}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        // _target is const, so it can't be copied;
    }
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Parameterized Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm" ,72, 45), _target(target) {}

void RobotomyRequestForm::executeAction() const {
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2)
        std::cout << this->_target << " was robotomized successfully." << std::endl;
    else
        std::cout << "Failed to robotomize " << this->_target << "." << std::endl;
}


