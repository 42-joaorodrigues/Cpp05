#include "Bureaucrat.hpp"

#include "AForm.hpp"
#include "iostream"

// Default constructor - lowest grade
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& src)
: _name(src._name), _grade(src._grade) {}

// Assignment operator - only grade can be assigned (name is const)
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
    if (this != &src)
        this->_grade = src._grade;
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Constructor with validation
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
}

const std::string& Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

// Increment grade = better rank (lower number)
void Bureaucrat::incrementGrade() {
    if (this->_grade <= 1)
        throw GradeTooHighException();
    this->_grade--;
}

// Decrement grade = worse rank (higher number)
void Bureaucrat::decrementGrade() {
    if (this->_grade >= 150)
        throw GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::signForm(AForm& f) const {
    try {
        f.beSigned(*this);
        std::cout << this->_name << " signed form " << f.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << this->_name << " couldn't sign form " << f.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm& f) const {
    try {
        f.execute(*this);
        std::cout << this->_name << " executed form " << f.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << this->_name << " couldn't execute form " << f.getName()
                  << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

// Output format: "Name, bureaucrat grade X."
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
