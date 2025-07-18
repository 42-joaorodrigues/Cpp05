#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form {
	const std::string   _name;
	bool                _is_signed;
	const int           _grade_to_sign;
	const int           _grade_to_execute;
public:
	// Orthodox Canonical Form
	Form();
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	// Full Constructor
	Form(const std::string& name, int grade_to_sign, int grade_to_execute);

	// Getters
	const std::string&  getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	void	beSigned(const Bureaucrat& b);

	// Exceptions
	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif // FORM_HPP
