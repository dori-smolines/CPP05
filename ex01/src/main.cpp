#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main( void ) {


	
Bureaucrat Bu01 ("Alice", 5);
Bureaucrat Bu02 ("Xavier", 6);

std::cout << Bu01 << std::endl;
std::cout << Bu02 << std::endl;




std::cout << "/////////////// TEST 1 /////////////" << std::endl;

Form A1 ("A1", 5, 120);
std::cout << A1 << std::endl;

// try {
// 	Form A2 ("A2", 0, 120);
// 	std::cout << A2 << std::endl;
// 	}
// catch (const Form::GradeTooHighException &e) {
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}
// catch (const Form::GradeTooLowException &e) {
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}

	
// try {
// 	Form A3 ("A3", 5, 151);
// 	std::cout << A3 << std::endl;
// 	}
// catch (const Form::GradeTooHighException &e) {
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}
// catch (const Form::GradeTooLowException &e) {
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}



std::cout << "/////////////// TEST 2 /////////////" << std::endl;


	Form A2 ("A2", 5, 120);
	std::cout << A2 << std::endl;


try {
	A2.beSigned(Bu02);
	}
catch (const Form::GradeTooLowException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}


std::cout << "/////////////// TEST 3 /////////////" << std::endl;


try {
	Bu01.signForm(A1);
	}
catch (const Form::GradeTooLowException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}



std::cout << "/////////////// TEST 4 /////////////" << std::endl;

try {
	Bu02.signForm(A1);
	}
catch (const Form::GradeTooLowException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
