/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:33:48 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 12:12:06 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) 
	: AForm("ShrubberyCreationForm", 145, 137), target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
	: AForm("ShrubberyCreationForm", 145, 137), target(other.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

const std::string&		ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

void					ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::ofstream	file;
	std::string		name;

	this->checkExecutability(executor);
	name = target + "_shrubbery";
	file.open(name.c_str(), std::ofstream::out);

    file << "      # #### ####               " << std::endl;
    file << "     ### \\/#|### |/####        " << std::endl;
    file << "    ##\\/#/ \\||/##/_/##/_#     " << std::endl;
    file << "  ###  \\/###|/ \\/ # #####     " << std::endl;
    file << " ##_\\_#\\_\\## | #/###_/_####  " << std::endl;
    file << "## #### # \\ #| /  #### ##/##   " << std::endl;
    file << " __#_--###`  |{,###---###-~     " << std::endl;
    file << "          \\ }{                 " << std::endl;
    file << "           }}{                  " << std::endl;
    file << "           }}{                  " << std::endl;
    file << "           {{}                  " << std::endl;
    file << "           `}                   " << std::endl;
    file << "            {                   " << std::endl;
	file.close();
}