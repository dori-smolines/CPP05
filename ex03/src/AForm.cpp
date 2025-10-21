#include "AForm.hpp"
#include <iostream>


////////////// CONSTRUCTOR //////////////////

	AForm::AForm() : _gradeToSign(0), _gradeToExecute(0) {
		std::cout << YELLOW << "AForm default constructor is called" << RESET << std::endl; 		
		return ;
	}

	AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : 
		_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 	{
		std::cout << YELLOW << "AForm " 
			<< this->_name << " constructor is called" << RESET << std::endl; 		
		if (_gradeToSign > 150 || _gradeToExecute > 150)
			throw AForm::GradeTooLowException();
		else if (_gradeToSign < 1 || _gradeToExecute < 1)
			throw AForm::GradeTooHighException();
		return;
	}


	AForm::AForm(AForm const & source) : _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute) { // constructeur par copie
		*this = source;
		std::cout << YELLOW << "AForm copy constructor is called" 	
			<< RESET
			<< std::endl;
		return;
	}

	AForm::~AForm()	{
		std::cout << YELLOW << "AForm destructor is called" 	
			<< RESET
			<< std::endl;
		return;
	}

	////////////// OPERATORS //////////////////

	AForm & AForm::operator=(AForm const & source){
		 const_cast<std::string &>(this->_name) = source._name;
		 const_cast<int &>(this->_gradeToSign) = source._gradeToSign;
 		 const_cast<int &>(this->_gradeToExecute) = source._gradeToExecute;
		return (*this);
	}

	////////////// ACCESSORS //////////////////

	std::string AForm::getName() const {	return (this->_name);	}
	int AForm::getGradeToSign() const  {	return (this->_gradeToSign);	}
	int AForm::getGradeToExecute() const  {	return (this->_gradeToExecute);	}
	bool AForm::getIsSigned() const {	return (this->_isSigned);	}

	////////////// MEMBER FONCTIONS //////////////////
	
	void AForm::beSigned (const Bureaucrat & bur)
	{
		if (bur.getGrade() > this->_gradeToSign)
			throw AForm::GradeTooLowException();
		else 
		{
			this->_isSigned = true;
			std::cout << PURPLE << this->getName() << " is signed" << RESET << std::endl;
		}
	}


	////////////// NON MEMBER FONCTIONS //////////////////

	std::ostream &operator<<(std::ostream &out, AForm const &source) {
        out << "AForm " << source.getName() 
			<< " is signed: " << source.getIsSigned() 
			<< ", can be signed by " << source.getGradeToSign() << ", can be executed by "
			<< source.getGradeToExecute();
        return out;
	}


	/////// EXECEPTIONS ///////

	const char* AForm::GradeTooLowException::what() const throw() {
		return "Grade too low!";
	}

	const char* AForm::GradeTooHighException::what() const throw() {
		return "Grade too high!";
	}
	
	const char *AForm::FormNotSigned::what() const throw() {
    	return ("Form is not signed. execution failed");
	}

