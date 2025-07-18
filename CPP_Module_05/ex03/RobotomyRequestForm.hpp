#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	const std::string	_target;
public:
	// Orthodox Canonical Form
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

	// Parameterized Constructor
	RobotomyRequestForm(const std::string& target);

	// Actions
	void	executeAction() const;
};

#endif // ROBOTOMYREQUESTFORM_HPP
