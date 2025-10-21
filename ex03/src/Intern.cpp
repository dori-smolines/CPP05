#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>
#include "Colors.hpp"

////////////// CONSTRUCTOR //////////////////

	Intern::Intern() {
		std::cout << YELLOW << "Intern default constructor is called" << RESET << std::endl; 		
		return ;
	}

	Intern::Intern(Intern const & source){ // constructeur par copie
		(void)source;
		std::cout << YELLOW << "Intern copy constructor is called" 	
			<< RESET
			<< std::endl;
		return;
	}

	Intern::~Intern()	{
		std::cout << YELLOW << "Intern destructor is called" 	
			<< RESET
			<< std::endl;
		return;
	}


	////////////// OPERATORS //////////////////

	Intern & Intern::operator=(Intern const & source){
		(void)source;
		return (*this);
	}

	////////////// MEMBER FONCTIONS //////////////////
	
	AForm*   Intern::createShrub(std::string & targetName)	{
		std::cout << BLUE << "Intern created ShrubberyCreationForm" << RESET << std::endl;
    	return (new ShrubberyCreationForm(targetName));
	}

	AForm*   Intern::createPardon(std::string & targetName)	{
	    std::cout << BLUE << "Intern created PresidentialPardonForm" << RESET << std::endl;
		return (new PresidentialPardonForm(targetName));
	}

	AForm*   Intern::createRobot(std::string & targetName)	{
    	std::cout << BLUE << "Intern created RobotomyRequestForm" << RESET << std::endl;
		return (new RobotomyRequestForm(targetName));
	}

	AForm*  Intern::unknownForm(std::string & targetName)	{
	    (void)targetName;
	    std::cerr << RED << "The requested form does not exist" << RESET << std::endl;
	    return (NULL);
	}

	AForm* Intern::makeForm(std::string formName, std::string targetName)	{

	std::string tab[4] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm", formName};
	AForm* (Intern::*function[4])(std::string & targetName) = {&Intern::createPardon, &Intern::createRobot, &Intern::createShrub, &Intern::unknownForm};
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (formName == tab[i])
			break;
		count++;
	}
	
	return ((this->*function[count])(targetName));
	}
