#pragma once
#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Colors.hpp"

# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class AForm;

class Intern {

protected :

	
public :
	Intern();
	Intern(Intern const & source); // constructeur par copie
	~Intern();
	Intern & operator=(Intern const & source); 

	AForm* createShrub(std::string & targetName);
	AForm* createPardon(std::string & targetName);
	AForm* createRobot(std::string & targetName);
	AForm* unknownForm(std::string & targetName);
	AForm* makeForm(std::string formName, std::string targetName);

};



