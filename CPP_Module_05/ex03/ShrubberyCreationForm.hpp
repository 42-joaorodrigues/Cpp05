#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	const std::string	_target;
public:
	// Orthodox Canonical Form
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	// Main Constructor
	ShrubberyCreationForm(const std::string& target);

	// Actions
	void executeAction() const;
};

#endif // SHRUBBERYCREATIONFORM_HPP
