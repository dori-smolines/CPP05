#pragma once
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

private:
	std::string _target;
	
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const & source); // constructeur par copie
	RobotomyRequestForm & operator=(RobotomyRequestForm const & source);

	void execute(Bureaucrat const & executor) const;
};

