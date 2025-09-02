/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:29:24 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 10:31:44 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is higher than the maximum!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is lower than the minimum!";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	if (grade < maxGrade)
		throw GradeTooHighException();
	else if (grade > minGrade)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat() : name("Default"), grade(minGrade) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade <= maxGrade)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade >= minGrade)
		throw GradeTooLowException();
	this->grade++;
}

void    Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "Bureaucrat " << this->name << " signed ";
		std::cout << "the form " << form.getName() << "!" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << this->getName()
				  << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}
