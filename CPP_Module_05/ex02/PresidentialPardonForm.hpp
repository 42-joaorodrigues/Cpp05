#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	const std::string	_target;
public:
	// Orthodox Canonical Form
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

	// Parameterized Constructor
	PresidentialPardonForm(const std::string& target);

	// Action
	void	executeAction() const;
};

#endif // PRESIDENTIALPARDONFORM_HPP
