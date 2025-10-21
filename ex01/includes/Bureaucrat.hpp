#pragma once
#include <string>
#include <iostream>
#include "Form.hpp"

#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define RESET	"\033[0m"
#define BOLD	"\033[1m"
#define PINK	"\033[95m"
#define LPINK	"\033[38;5;218m"
#define PURPLE	"\033[35m"
#define LPURPLE "\033[38;5;141m"
#define RED		"\033[31m"

class Form;

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
	void signForm(Form & form);

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
	







