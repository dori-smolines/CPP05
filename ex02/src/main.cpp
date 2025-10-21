#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        std::cout << BOLD << PURPLE << "\n=== Création des bureaucrates ===\n" << RESET;
        Bureaucrat bob("Bob", 150);
        Bureaucrat alice("Alice", 50);
        Bureaucrat boss("Boss", 1);

        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << boss << std::endl;

        std::cout << BOLD << PURPLE << "\n=== Création des formulaires ===\n" << RESET;
        ShrubberyCreationForm shrub("Hermione");
        RobotomyRequestForm robot("Ron Weasley");
        PresidentialPardonForm pardon("Harry Pooter");

        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        std::cout << BOLD << PURPLE << "\n=== Tests de signature ===\n" << RESET;
        bob.signForm(shrub);     // trop bas
        alice.signForm(shrub);   // OK
        alice.signForm(robot);   // OK
        boss.signForm(pardon);   // OK

        std::cout << BOLD << PURPLE << "\n=== Tests d'exécution ===\n" << RESET;
        bob.executeForm(shrub);   // trop bas
        alice.executeForm(shrub); // OK -> crée fichier 
        alice.executeForm(robot); // trop bas
		boss.executeForm(robot); // OK -> robotomy aléatoire
        boss.executeForm(pardon); // OK -> est pardonné

        std::cout << BOLD << GREEN << "\n=== Tous les tests sont passés ===\n" << RESET;
    }
    catch (std::exception & e) {
        std::cerr << RED << "Exception attrapée dans main: " << e.what() << RESET << std::endl;
    }
}