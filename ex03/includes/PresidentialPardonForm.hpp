#pragma once
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const & source); // constructeur par copie
	PresidentialPardonForm & operator=(PresidentialPardonForm const & source);

	void execute(Bureaucrat const & executor) const;
};


