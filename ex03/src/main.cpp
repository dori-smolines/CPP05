#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {

Bureaucrat bob("Bob", 150);
Bureaucrat alice("Alice", 50);
Bureaucrat boss("Boss", 1);

std::cout << "************ ROBOTOMY ******************" << std::endl;

Intern someRandomIntern;
AForm* rrf;
rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
if (rrf) {
	alice.signForm(*rrf);
	boss.executeForm(*rrf);
}

std::cout << "************ SHRUBERRY ******************" << std::endl;

Intern Martin;
AForm* srf;
srf = Martin.makeForm("ShrubberyCreationForm", "Anyway");

std::cout << "************ NO FORM  ******************" << std::endl;

Intern Moulinette;
AForm* nof;
nof = Moulinette.makeForm("Miaou", "Miaou");

delete rrf;
delete srf;
delete nof;

std::cout << "******************************" << std::endl;

}