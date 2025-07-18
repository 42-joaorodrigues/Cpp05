#include "AForm.hpp"
#include "iostream"
#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm() : _name("Default"), _is_signed(false), _grade_to_sign(150),
    _grade_to_execute(150) {}

// Copy constructor
AForm::AForm(const AForm& other) : _name(other._name), _is_signed(other._is_signed),
    _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute) {
}

// Copy assignment operator
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        // Name, Grade to Sign and Grade to Execute are const. They can't be copied
        this->_is_signed = other._is_signed;
    }
    return *this;
}

// Destructor
AForm::~AForm() {}

// Full Constructor
AForm::AForm(const std::string& name, const int grade_to_sign, const int grade_to_execute)
    : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign),
    _grade_to_execute(grade_to_execute) {
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_execute > 150)
        throw GradeTooLowException();
}

// Getters
const std::string&  AForm::getName() const { return this->_name; }
bool                AForm::getIsSigned() const { return this->_is_signed; }
int                 AForm::getGradeToSign() const { return this->_grade_to_sign; }
int                 AForm::getGradeToExecute() const { return this->_grade_to_execute; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->_grade_to_sign)
        throw GradeTooLowException();
    this->_is_signed = true;
}

void AForm::execute(const Bureaucrat& execute) const {
    if (!this->getIsSigned())
        throw FormNotSignedException();
    if (execute.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();

    executeAction();
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

// Operator
std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName()
       << ", requires grade " << f.getGradeToSign()
       << " to sign, grade " << f.getGradeToExecute()
       << " to execute, signed: " << (f.getIsSigned() ? "true" : "false");
    return os;
}
