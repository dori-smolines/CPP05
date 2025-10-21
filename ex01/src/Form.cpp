#include "Form.hpp"
#include <iostream>


////////////// CONSTRUCTOR //////////////////

	Form::Form() : _isSigned(false), _gradeToSign(0), _gradeToExecute(0) {
		std::cout << YELLOW << "Form default constructor is called" << RESET << std::endl; 		
		return ;
	}

	Form::Form(std::string name, int gradeToSign, int gradeToExecute) : 
		_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 	{
		std::cout << YELLOW << "Form " 
			<< this->_name << " constructor is called" << RESET << std::endl; 		

		if (_gradeToSign > 150 || _gradeToExecute > 150)
			throw Form::GradeTooLowException();
		else if (_gradeToSign < 1 || _gradeToExecute < 1)
			throw Form::GradeTooHighException();
		return;
	}


	Form::Form(Form const & source) : _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute) { // constructeur par copie
		*this = source;
		std::cout << YELLOW << "Form copy constructor is called" 	
			<< RESET
			<< std::endl;
		return;
	}

	Form::~Form()	{
		std::cout << YELLOW << "Form destructor is called" 	
			<< RESET
			<< std::endl;
		return;
	}

	////////////// OPERATORS //////////////////

	Form & Form::operator=(Form const & source){
		 const_cast<std::string &>(this->_name) = source._name;
		 const_cast<int &>(this->_gradeToSign) = source._gradeToSign;
 		 const_cast<int &>(this->_gradeToExecute) = source._gradeToExecute;
		return (*this);
	}

	////////////// ACCESSORS //////////////////

	std::string Form::getName() const {	return (this->_name);	}
	int Form::getGradeToSign() const  {	return (this->_gradeToSign);	}
	int Form::getGradeToExecute() const  {	return (this->_gradeToExecute);	}
	bool Form::getIsSigned() const {	return (this->_isSigned);	}

	////////////// MEMBER FONCTIONS //////////////////

	const char* Form::GradeTooLowException::what() const throw() {
		return "Grade too low!";
	}

	const char* Form::GradeTooHighException::what() const throw() {
		return "Grade too high!";
	}

	void Form::beSigned (const Bureaucrat & bur)
	{
			if (this->_isSigned == true)
				return;
			if (bur.getGrade() > this->_gradeToSign)
				throw Form::GradeTooLowException();
			else 
				{
					this->_isSigned = true;
					std::cout << "Form is signed" << std::endl;
				}
	}

	////////////// NON MEMBER FONCTIONS //////////////////

	std::ostream &operator<<(std::ostream &out, Form const &source) {
        out << "Form " << source.getName() 
			<< " is signed: " << source.getIsSigned() 
			<< ", can be signed by " << source.getGradeToSign() << ", can be executed by "
			<< source.getGradeToExecute();
        return out;
	}


