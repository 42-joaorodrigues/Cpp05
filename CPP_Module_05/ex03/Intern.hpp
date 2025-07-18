#ifndef INTERN_HPP
#define INTERN_HPP
#include <exception>

#include "AForm.hpp"

class Intern {
public:
	// Orthodox Canonical Form
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

	// Actions
	AForm*	makeForm(const std::string& name, const std::string& target);

	// Exception
	class UknownFormException : public std::exception {
	public:
		const char*	what() const throw();
	};
};

#endif // INTERN_HPP
