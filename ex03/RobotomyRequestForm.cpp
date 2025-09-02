/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:33:28 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 12:11:40 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) 
        : AForm("RobotomyRequestForm", 72, 45), target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
        : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
        : AForm("RobotomyRequestForm", 72, 45), target(other.getTarget()) {}

RobotomyRequestForm&
RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

void				RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	this->checkExecutability(executor);

	std::cout << "* Unbearable drilling noises *" << std::endl;
	if (rand() % 2)
	{
		std::cout << "The victim " << this->target;
		std::cout << " has been successfully robotomized!" << std::endl;
	}
	else
		std::cout << "The robotomization on " << this->target << " failed!" << std::endl;
}