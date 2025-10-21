#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

////  constructors ////

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5){
	std::cout << "PresidentialPardonForm default constructor is called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm constructor is called" << std::endl;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor is called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & source)  : AForm(source), _target(source._target) // constructeur par copie
{
	return;
}

//// operator ////

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & source) {
   AForm::operator=(source);
    this->_target = source._target;
    return (*this);
}

//// member fonctions ////

void PresidentialPardonForm::execute(const Bureaucrat & executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << GREEN << executor.getName() << " execute " 
		<< this->getName() << " form" << RESET << std::endl;
	
	std::cout << LPURPLE << this->_target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;

}