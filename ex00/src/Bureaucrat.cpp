#include "Bureaucrat.hpp"
#include <iostream>


////////////// CONSTRUCTOR //////////////////

	Bureaucrat::Bureaucrat() {
		std::cout << YELLOW << "Bureaucrat default constructor is called" << RESET << std::endl; 		
		return ;
	}

	Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) 	{
		std::cout << YELLOW << "Bureaucrat " 
			<< this->_name << " constructor is called" << RESET << std::endl; 		
		try {
				checkGrade(grade);
			}
		catch (const Bureaucrat::GradeTooHighException &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		}
		return;
	}

	Bureaucrat::Bureaucrat(Bureaucrat const & source){ // constructeur par copie
		*this = source;
		std::cout << YELLOW << "Bureaucrat copy constructor is called" 	
			<< RESET
			<< std::endl;
		return;
	}

	Bureaucrat::~Bureaucrat()	{
		std::cout << YELLOW << "Bureaucrat destructor is called" 	
			<< RESET
			<< std::endl;
		return;
	}


	////////////// OPERATORS //////////////////

	Bureaucrat & Bureaucrat::operator=(Bureaucrat const & source){
		this->_grade = source._grade;
		 const_cast<std::string &>(this->_name) = source._name;
		return (*this);
	}

	////////////// ACCESSORS //////////////////

	std::string Bureaucrat::getName() const {
		return (this->_name);
	}

	int Bureaucrat::getGrade() const {
		return (this->_grade);
	}

	////////////// MEMBER FONCTIONS //////////////////
	
	void Bureaucrat::incrementGrade()	{
		if (_grade == 1)
			throw Bureaucrat::GradeTooHighException();
		else
			_grade -= 1;
		std::cout << "Bureaucrat " << _name << " has been promoted to grade " << _grade << std::endl;
		return;
	}
	
	void Bureaucrat::decrementGrade()	{
		if (_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		_grade += 1;
		std::cout << "Bureaucrat " << _name << " has been demoted to grade " << _grade << std::endl;
		return;
	}
	
	void Bureaucrat::checkGrade(int grade)	{
	if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1) 
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade = grade;
		return;
	}

	const char* Bureaucrat::GradeTooLowException::what() const throw() {
		return "Grade too low!";
	}

	const char* Bureaucrat::GradeTooHighException::what() const throw() {
		return "Grade too high!";
	}


		////////////// NON MEMBER FONCTIONS //////////////////

	std::ostream &operator<<(std::ostream &out, Bureaucrat const &source) {
        out << source.getName() << ", bureaucrat grade " << source.getGrade();
        return out;
	}


