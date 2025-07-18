#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        // _target can't be copied
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Main Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

// Actions
void ShrubberyCreationForm::executeAction() const {
    std::ofstream file((this->_target + "_shrubbery").c_str(), std::ios::app);
    file << "        /\\        " << std::endl
         << " |\\    /  \\    /| " << std::endl
         << " | \\   \\  /   / | " << std::endl
         << " |  |  \\  /  |  | " << std::endl
         << "  \\  \\ \\  / /  /  " << std::endl
         << "|\\__\\ \\\\  // /__/|" << std::endl
         << " \\___--    --___/ " << std::endl
         << "     /_/||\\_\\     " << std::endl
         << "        ||        " << std::endl;
    file.close();
}
