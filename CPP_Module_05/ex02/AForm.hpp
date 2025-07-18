#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class AForm {
	const std::string   _name;
	bool                _is_signed;
	const int           _grade_to_sign;
	const int           _grade_to_execute;
public:
	// Orthodox Canonical Form
	AForm();
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	// Full Constructor
	AForm(const std::string& name, int grade_to_sign, int grade_to_execute);

	// Getters
	const std::string&  getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	// Actions
	void			beSigned(const Bureaucrat& b);
	void			execute(const Bureaucrat& execute) const;
	virtual void	executeAction() const = 0;

	// Exceptions
	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};
	class FormNotSignedException : public std::exception {
		const char*	what() const throw();
	};
};

// Operator
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif // FORM_HPP
