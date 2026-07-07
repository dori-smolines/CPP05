*This project has been created as part of the 42 curriculum by smolines.*

# CPP Module 05

## Description

This repository contains the exercises of **Module 05** of the C++ curriculum at 42. Building on Module 04, this module introduces **exception handling** in C++, through a small bureaucratic simulation involving `Bureaucrat`s who sign and execute administrative `Form`s.

The central topic of this module is designing classes with validated invariants — grades ranging from 1 (highest) to 150 (lowest) — enforced through custom, catchable exceptions rather than silent failures.

### Exercise 00 — Mommy, when I grow up, I want to be a bureaucrat!

A `Bureaucrat` class with a constant `name` and a `grade` ranging from 1 (highest) to 150 (lowest):
- Any attempt to instantiate a Bureaucrat with an invalid grade throws a `Bureaucrat::GradeTooHighException` or `Bureaucrat::GradeTooLowException`.
- `getName()` / `getGrade()` getters, plus member functions to increment/decrement the grade (throwing the same exceptions if the grade goes out of range).
- An overload of the `<<` insertion operator prints `<name>, bureaucrat grade <grade>.`

### Exercise 01 — Form up, maggots!

A `Form` class with a constant `name`, a signed flag (unsigned at construction), and constant grades required to sign and to execute it — all private:
- Same grade exceptions as `Bureaucrat` (`Form::GradeTooHighException` / `GradeTooLowException`).
- `beSigned(Bureaucrat const &)` signs the form if the Bureaucrat's grade is high enough, otherwise throws `Form::GradeTooLowException`.
- `Bureaucrat::signForm(Form &)` attempts to sign a form and prints the outcome (`<bureaucrat> signed <form>` or `<bureaucrat> couldn't sign <form> because <reason>.`).

### Exercise 02 — No, you need form 28B, not 28C...

`Form` becomes the abstract class `AForm`, with three concrete forms:
- `ShrubberyCreationForm` (sign 145, exec 137) — creates a `<target>_shrubbery` file filled with ASCII trees.
- `RobotomyRequestForm` (sign 72, exec 45) — makes drilling noises and robotomizes the target with a 50% success rate.
- `PresidentialPardonForm` (sign 25, exec 5) — announces that `<target>` has been pardoned by Zaphod Beeblebrox.

`execute(Bureaucrat const &)` checks that the form is signed and that the executor's grade is sufficient, throwing an appropriate exception otherwise. `Bureaucrat::executeForm(AForm const &)` attempts execution and reports success or failure.

### Exercise 03 — At least this beats coffee-making

An `Intern` class with no name and no grade, whose only role is `makeForm()`:
- `makeForm(formName, target)` returns a pointer to a new `AForm` (matching one of the three concrete forms from ex02), targeted at `target`.
- Prints `Intern creates <form>`, or an explicit error message if `formName` is unknown.
- Implemented without long `if/else if` chains, favoring a clean lookup mechanism instead.

## Instructions

### Compilation

```bash
make
```

Run inside each exercise's directory (`ex00/` through `ex03/`). Each Makefile compiles the corresponding source files with `c++ -Wall -Wextra -Werror` (compatible with `-std=c++98`), and includes the required `$(NAME)`, `all`, `clean`, `fclean`, and `re` rules.

### Running

```bash
./bureaucrat       # ex00
./form_up          # ex01
./form_28b         # ex02
./intern           # ex03
```

Each exercise ships with its own `main.cpp`, demonstrating valid and invalid cases (out-of-range grades, unsigned/unexecutable forms, unknown form names), all caught cleanly via `try` / `catch (std::exception &)`.

## Resources

- [Wikipedia — Exception handling (C++)](https://en.wikipedia.org/wiki/Exception_handling)
- General documentation on `std::exception`, `try`/`catch` blocks, and custom exceptions in C++98
- General documentation on abstract classes combined with exception-based validation

**AI usage:** AI assistance was used to help draft and structure this README file (organizing sections, describing each exercise's behavior and usage) based on the actual project source code and the official subject requirements. No AI-generated code was used in the implementation of the exercises themselves; all class design and logic were written and understood by the author.
