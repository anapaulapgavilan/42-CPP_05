/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:31:08 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 11:03:17 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) 
        : AForm("PresidentialPardonForm", 25, 5), target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
        : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
        : AForm("PresidentialPardonForm", 25, 5), target(other.getTarget())
{}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm&
PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

const std::string&  PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	this->checkExecutability(executor);
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;	
}