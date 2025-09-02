/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:30:46 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 09:31:04 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat		Ana("Ana", 1);
	Bureaucrat		Mariana("Mariana", 40);
	Bureaucrat		Fernando("Fernando", 150);
	AForm			*form = NULL;

	srand(time(NULL));
	std::cout << "\nLet's execute an unsigned presidential pardon form\n" << std::endl;
	try
	{
		form = new PresidentialPardonForm("A11");
		form->execute(Ana);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nLet's sign and execute a presidential pardon form\n" << std::endl;
	try
	{
		form = new PresidentialPardonForm("A12");
		form->beSigned(Ana);
		form->execute(Ana);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nLet's sign and execute robotomy request form with different people\n" << std::endl;
	try
	{
		form = new RobotomyRequestForm("28B");
		Ana.signForm(*form);
		std::cout << std::endl;
		Mariana.executeForm(*form);
		Mariana.executeForm(*form);
		Mariana.executeForm(*form);
		Mariana.executeForm(*form);
		Mariana.executeForm(*form);
		Mariana.executeForm(*form);
		Mariana.executeForm(*form);

		std::cout << "\nNow Ana\n" << std::endl;
		Ana.executeForm(*form);
		
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nLet's execute shrubbery creation form with unauthorized bureaucrat\n" << std::endl;
	try
	{
		form = new ShrubberyCreationForm("A13");
		Ana.signForm(*form);
		Mariana.executeForm(*form);
		Fernando.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}