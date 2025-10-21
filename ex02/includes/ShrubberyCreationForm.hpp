#pragma once
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

private:
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const & source); // constructeur par copie
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & source);
	void execute(Bureaucrat const & executor) const;
};


