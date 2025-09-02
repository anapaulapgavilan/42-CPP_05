/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:32:32 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 12:15:37 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& other) { *this = other; }

Intern::~Intern(void) {}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

AForm	*Intern::makeForm(const std::string& formName, const std::string& target) const
{
	AForm	*result;

	t_form	data[] = 
	{
		{ "presidential pardon", new PresidentialPardonForm(target) },
		{ "robotomy request", new RobotomyRequestForm(target) },
		{ "shrubbery creation", new ShrubberyCreationForm(target) },
		{ "", NULL }
	};

	result = NULL;
	for (int i = 0; data[i].form != NULL; i++)
	{
		if (data[i].type == formName)
			result = data[i].form;
		else
			delete data[i].form;
	}

	if (result == NULL)
		std::cout << "Intern could not find the form " << formName << std::endl;
	else
		std::cout << "Intern creates " << formName << std::endl;
	return result;
}