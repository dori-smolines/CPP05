#include "Bureaucrat.hpp"
#include <iostream>

int main( void ) {


	
Bureaucrat Bu01 ("Alice", 5);
Bureaucrat Bu02 ("Georges", 149);
Bureaucrat Bu03 ("Mimi", 162);
Bureaucrat Bu04 ("Lulu", -2);

std::cout << Bu01.getName() << std::endl;
std::cout << Bu01 << std::endl;


for (int i = Bu01.getGrade();  i >= 0; i--)

{
try {
	Bu01.incrementGrade();
	}
catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << Bu01 << std::endl;
}

return 0;
}

