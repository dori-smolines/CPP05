#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Colors.hpp"

class Bureaucrat; // déclaration anticipée
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class AForm {

private :
	const std::string _name;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExecute;
	
public :
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(AForm const & source); // constructeur par copie
	~AForm();
	AForm & operator=(AForm const & source); 

	int getGradeToSign() const ;
	int getGradeToExecute() const ;
	std::string getName() const ;
	bool getIsSigned() const ;
	void beSigned (const Bureaucrat & bur);
	virtual void execute(Bureaucrat const & executor) const = 0;
	
	class GradeTooLowException : public std::exception {
		public:
				virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class FormNotSigned : public std::exception {
		public:
			virtual const char* what() const throw();
	};

};

	std::ostream &operator<<(std::ostream &out, AForm const &source);
	






