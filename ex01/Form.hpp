/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:29:56 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 10:48:07 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form {

	private:
		static const int	maxGrade = 1;
		static const int	minGrade = 150;

		const std::string	name;
		const int			gradeToSign;
		const int			gradeToExecute;
		bool				_signed;

		Form(void);

	public:
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form(void);

		const std::string&	getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		bool				isSigned(void) const;
		void				beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception
		{
			private:
				const char	*msg;
			public:
				GradeTooHighException(void);
				GradeTooHighException(const char *msg);
				const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				const char	*msg;
			public:
				GradeTooLowException(void);
				GradeTooLowException(const char *msg);
				const char	*what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif