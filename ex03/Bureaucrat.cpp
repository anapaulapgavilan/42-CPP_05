/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:32:17 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 12:14:23 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char		*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is higher than the maximum!");
}

const char		*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is lower than the minimum!");
}

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat&			Bureaucrat::operator=(const Bureaucrat& other)
{
	this->grade = other.grade;
	return (*this);
}

const std::string&	Bureaucrat::getName(void) const
{
	return (this->name);
}

int					Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void				Bureaucrat::incrementGrade(void)
{
	if (this->grade <= Bureaucrat::maxGrade)
		throw GradeTooHighException();
	this->grade--;
}

void				Bureaucrat::decrementGrade(void)
{
	if (this->grade >= Bureaucrat::minGrade)
		throw GradeTooLowException();
	this->grade++;
}

void				Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->getName()
                  << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void 				Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->getName()
                  << " couldn’t execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}