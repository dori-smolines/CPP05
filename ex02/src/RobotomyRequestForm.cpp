#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

////  constructors ////

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45){
	std::cout << "RobotomyRequestForm default constructor is called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm constructor is called" << std::endl;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor is called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & source)  : AForm(source), _target(source._target) // constructeur par copie
{
	return;
}

//// operator ////

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & source) {
   AForm::operator=(source);
    this->_target = source._target;
    return (*this);
}

//// member fonctions ////

void RobotomyRequestForm::execute(const Bureaucrat & executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << GREEN << executor.getName() << " execute " << this->getName() << " form" << RESET << std::endl;
	
	static bool aleat = false;
    if (!aleat)
    {
        std::srand(std::time(0));//initialisation de srand avec l'heure actuelle
        aleat = true;
    }
	 if ((std::rand() % 2) == 0)
        std::cout << LPURPLE << "DRILLLLL... " << this->_target
			<< " has been robotomized successfully!" << RESET << std::endl;
	else
        std::cout << LPURPLE << "Robotomy failed" << RESET << std::endl;

}
