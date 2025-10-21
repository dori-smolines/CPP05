#pragma once
#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Colors.hpp"

class AForm;

class Bureaucrat {

protected :
	std::string const _name;
	int _grade;
	
public :
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & source); // constructeur par copie
	~Bureaucrat();
	Bureaucrat & operator=(Bureaucrat const & source); 

	int getGrade() const ;
	std::string getName() const ;
	void incrementGrade();
	void decrementGrade();
	void checkGrade(int grade);
	void signForm(AForm & form);
	void executeForm(AForm const & form) const;
	
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

};

	std::ostream &operator<<(std::ostream &out, Bureaucrat const &source);
	






