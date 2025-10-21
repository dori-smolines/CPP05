#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"


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

class Bureaucrat; // déclaration anticipée

class Form {

private :
	std::string const _name;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExecute;
	
public :
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(Form const & source); // constructeur par copie
	~Form();
	Form & operator=(Form const & source); 

	int getGradeToSign() const ;
	int getGradeToExecute() const ;
	std::string getName() const ;
	bool getIsSigned() const ;
	
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	void beSigned (const Bureaucrat & bur);
};

	std::ostream &operator<<(std::ostream &out, Form const &source);
	






