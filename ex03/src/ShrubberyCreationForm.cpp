#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"

////  constructors ////

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137){
	std::cout << "ShrubberyCreationForm default constructor is called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){
	std::cout << "ShrubberyCreationForm constructor is called" << std::endl;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor is called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & source) : AForm(source), _target(source._target) // constructeur par copie
{
	return;
}

//// operator ////

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & source) {
   AForm::operator=(source);
    this->_target = source._target;
    return (*this);
}

//// member fonctions ////

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << GREEN << executor.getName() << " execute " 
		<< this->getName() << " form" << RESET << std::endl;
	
	const std::string filename = this->_target + "_shrubbery";
    std::ofstream file(filename.c_str()); // creer ou ecrase et ouvre le fichier en ecriture
    
    if (!file) 
	{
        std::cerr << "Erreur : impossible de créer le fichier '" << filename << "'.\n";
        return;
    }

file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢱⣸⠀⠀⠀⠀⠀⠀⠀⠀⡄⡄⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢱⣸⠀⠀⠀⠀⠀⠀⠀⠀⡄⡄⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⢶⢠⠀⢀⡸⡄⠒⢺⠀⣸⣀⡀⣦⠽⠑⠁⠀⠀⠀⠀⠀⠀⠀⣆⣀⠗⠂⠀⠀⡆⢠⠃⡠⠜⠒⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⡄⠀⢤⠞⢳⠊⠓⠣⢸⡸⣲⠇⣘⣦⠚⢗⣻⠉⠻⡴⠂⢀⣀⠀⠀⣠⠂⠀⡇⠀⠀⠀⠀⡚⡲⢃⡉⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠐⠺⠤⢼⡀⡞⢶⠦⣤⡖⠯⠭⡽⠟⡲⠀⠀⣆⠴⠊⢀⠀⠈⠅⡜⠒⠁⠀⠀⠉⢱⠀⠀⠀⠈⣑⡼⠁⢀⢠⢠⠄⢠⠆⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠢⢄⢳⣁⣀⠆⠃⣇⡇⠜⠍⢳⡄⢰⢃⡈⡩⣲⠾⡃⢀⠀⠘⠤⢁⣠⠃⢠⢼⣇⣰⢃⣼⠀⠀⠀⣩⡾⠦⣆⠷⣅⠜⠉⠁⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⢦⠀⠈⠒⡥⣽⢁⠌⢹⢶⡤⡧⣾⠀⠀⠙⣾⣤⠖⠿⡿⣄⡗⢴⢣⡌⢲⣩⠚⠸⣌⣍⠹⣸⣚⡙⢷⣤⠞⠡⢄⣀⡳⣎⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⢄⣣⡈⠦⡜⣸⡹⣰⠃⡀⢱⣛⣰⣑⢽⣧⠀⢰⣿⡇⠰⠋⠑⡜⡗⡞⠋⠂⠘⢦⠳⣠⠿⠦⣼⢩⣤⢊⡾⠋⠀⠀⠀⠋⠀⢨⠏⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⢁⠇⠀⡏⠀⠈⢾⡄⠙⣤⠃⣟⠀⠋⣿⣅⡾⢻⢀⡀⡆⣰⣥⣟⢱⣞⣀⠀⣨⠧⣯⡀⠀⢸⣈⣷⡟⠀⢀⢦⠀⠀⠀⢠⠏⠀⠀⡀⣷⠀⠀⠀⠀" << std::endl;
file << "⠤⢲⠚⢒⢻⠙⢶⣴⢺⠉⠒⡧⠔⠛⠲⢤⣸⣿⠁⣼⡶⠿⠿⣽⣓⣸⢿⣓⡶⣚⢧⡷⣿⢫⣦⣸⣿⠏⢹⡴⠋⠸⡄⠀⠀⡞⠀⢰⣰⢣⠊⠀⣰⡠⠀" << std::endl;
file << "⠀⠈⡄⠀⢭⡇⡀⠉⠻⣇⠀⡇⠀⠀⠀⣀⡝⢿⡆⣿⢁⢀⡴⠋⣏⣏⡼⠋⡷⣇⡝⣇⣿⡜⠋⣿⣿⡆⣼⡝⡄⣠⢹⠀⣸⠁⠀⠀⠀⠛⣄⣸⡖⠊⠀" << std::endl;
file << "⠐⠴⣅⡆⠘⡎⢢⠀⠀⢹⣎⣷⠀⠀⣀⡕⠻⢚⣿⣿⡉⠉⠳⣄⣰⠟⠑⢶⠁⠹⢴⠁⡇⣠⣴⠿⣏⣾⡇⢹⡃⡗⢸⣷⢃⣠⠔⠋⠀⢠⠃⠀⠑⠹⠀" << std::endl;
file << "⠀⢤⢎⣈⡲⠵⣈⠉⠓⣾⠙⣾⣇⠀⠀⠛⣆⡇⢻⣿⡇⠀⣠⡾⠛⢶⡆⠈⣇⣰⠏⢰⣿⢏⡏⢠⣏⣼⠞⠉⠉⠱⣿⢿⡭⣄⠀⠀⢠⠏⠀⠀⠀⠀⠀" << std::endl;
file << "⠐⠚⠒⠂⠼⣄⠀⠉⠢⣼⡀⠈⢻⣆⠠⡄⠳⡇⢸⣿⣧⣾⡟⠀⠀⢸⡇⠀⣸⠋⠀⣼⡏⢾⠛⣿⢹⡏⠀⠀⢀⡼⠃⢘⠂⢨⠀⢀⡞⠀⢀⠄⢀⠆⡀" << std::endl;
file << "⠀⠀⠀⠀⠀⠈⠳⣄⠀⠈⠳⣄⠀⣿⣆⠸⡠⠜⣆⣿⣿⠏⠀⠀⠀⢸⡇⢰⠇⠀⢀⣿⠁⣿⢰⡇⣼⠁⠀⢠⡞⠁⠀⠸⣚⣮⠵⠟⠓⠦⣸⠀⡤⠼⠓" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠙⢦⣀⣀⣈⠳⣜⢿⣯⠀⠀⢈⣿⡿⠦⣤⣀⠀⢸⣷⡏⠀⠀⣸⣿⡾⠋⣿⢁⡟⠀⣰⣯⣤⠶⠞⣋⠽⢓⣒⡡⠤⠒⠛⠳⢧⡀⡄" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠙⠳⣿⣷⡀⢸⣿⡇⠀⠀⠉⠛⢾⣿⠀⠀⠀⣿⡟⠁⣸⣿⣾⣿⣿⠟⢉⣠⣴⠞⠋⠉⠉⠉⠂⠀⠀⠀⠀⠈⠃⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣿⣾⣿⡇⠀⠀⠀⠀⢸⣿⠀⠀⢸⡟⢀⣼⡿⠋⣼⣿⣿⡿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⡇⠀⠀⠀⠀⠀⣿⡀⠀⣿⣷⡿⠋⠀⢠⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣄⠀⠀⠀⠀⢿⡇⣸⣿⠟⠀⠀⢀⣾⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣆⠀⠀⠀⣸⣷⣿⡇⠀⠀⠀⣼⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⡏⢿⣿⣦⣀⣾⣿⢯⣿⠀⠀⠀⣼⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣮⣿⣿⣿⡿⠁⣸⡟⠀⠀⣼⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣿⣿⣿⣿⡟⠀⢠⣿⠃⠀⣼⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣷⣠⣾⣿⣤⣾⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡿⠿⠛⠻⣿⣿⠿⠿⠿⢿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠈⠡⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
file.close();
}

