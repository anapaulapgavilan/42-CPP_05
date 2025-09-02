/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:30:10 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 11:09:53 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException(void)
{
	this->msg = "The grade is higher than the maximum!";
}

AForm::GradeTooHighException::GradeTooHighException(const char *msg) : msg(msg) {}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return (this->msg);
}

AForm::GradeTooLowException::GradeTooLowException(void)
{
	this->msg = "The grade is lower than the minimum!";
}

AForm::GradeTooLowException::GradeTooLowException(const char *msg) : msg(msg) {}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return (this->msg);
}

AForm::InvalidFormException::InvalidFormException(void)
{
	this->msg = "The form cannot be executed!";
}

AForm::InvalidFormException::InvalidFormException(const char *msg) : msg(msg) {}

const char	*AForm::InvalidFormException::what() const throw()
{
	return (this->msg);
}

AForm::AForm() : name(), gradeToSign(1), gradeToExecute(1), _signed(false) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
	: name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();

	this->_signed = false;
}

AForm::AForm(const AForm &copy) : name(copy.name), gradeToSign(copy.gradeToSign),
gradeToExecute(copy.gradeToExecute), _signed(copy._signed) {}

AForm::~AForm() {}

AForm&   AForm::operator=(const AForm& other)
{
	this->_signed = other._signed;
	return (*this);
}

const std::string&	AForm::getName(void) const
{
	return (this->name);
}

int AForm::getGradeToSign(void) const
{
	return (this->gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (this->gradeToExecute);
}

bool    AForm::isSigned(void) const
{
	return (this->_signed);
}

void    AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->gradeToSign)
		throw GradeTooLowException("Bureaucrat is not authorized to sign the form!");
	this->_signed = true;
}

void    AForm::checkExecutability(const Bureaucrat& executor) const
{
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException("Bureaucrat is not authorized to execute the form!");
	if (!this->_signed)
		throw InvalidFormException("Not signed forms cannot be executed!");
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "AForm: " << form.getName()
        << " Signed: " << (form.isSigned() ? "true" : "false")
        << " GradeToSign: " << form.getGradeToSign()
        << " GradeToExecute: " << form.getGradeToExecute();
    return out;
}
