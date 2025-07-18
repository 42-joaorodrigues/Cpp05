#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class AForm;

class Bureaucrat {
    const std::string   _name;  // Name cannot be changed after construction
    int                 _grade; // Grade: 1 (highest) to 150 (lowest)
public:
    // Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat& operator=(const Bureaucrat& src);
    ~Bureaucrat();

    // Full Constructor
    Bureaucrat(const std::string& name, int grade);

    // Getters
    const std::string&  getName() const;
    int                 getGrade() const;

    // Grade modification (1 = highest, 150 = lowest)
    void incrementGrade();  // Decreases grade number (improves rank)
    void decrementGrade();  // Increases grade number (worsens rank)

    // Actions
    void    signForm(AForm& f) const;
    void    executeForm(AForm& f) const;

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif //BUREAUCRAT_HPP
