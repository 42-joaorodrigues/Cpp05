#include "Form.hpp"
#include "iostream"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form() : _name("Default"), _is_signed(false), _grade_to_sign(150),
    _grade_to_execute(150) {}

// Copy constructor
Form::Form(const Form& other) : _name(other._name), _is_signed(other._is_signed),
    _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute) {
}

// Copy assignment operator
Form& Form::operator=(const Form& other) {
    if (this != &other) {
        // Name, Grade to Sign and Grade to Execute are const. They can't be copied
        this->_is_signed = other._is_signed;
    }
    return *this;
}

// Destructor
Form::~Form() {}

// Full Constructor
Form::Form(const std::string& name, const int grade_to_sign, const int grade_to_execute)
    : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign),
    _grade_to_execute(grade_to_execute) {
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_execute > 150)
        throw GradeTooLowException();
}

// Getters
const std::string&  Form::getName() const { return this->_name; }
bool                Form::getIsSigned() const { return this->_is_signed; }
int                 Form::getGradeToSign() const { return this->_grade_to_sign; }
int                 Form::getGradeToExecute() const { return this->_grade_to_execute; }

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->_grade_to_sign)
        throw GradeTooLowException();
    this->_is_signed = true;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName()
       << ", requires grade " << f.getGradeToSign()
       << " to sign, grade " << f.getGradeToExecute()
       << " to execute, signed: " << (f.getIsSigned() ? "true" : "false");
    return os;
}


