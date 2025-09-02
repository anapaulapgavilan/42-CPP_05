/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:32:23 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 11:59:08 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#pragma once

#include "AForm.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat {
	private:
		static const int	maxGrade = 1;
		static const int	minGrade = 150;
		const std::string	name;
		int					grade;

		Bureaucrat(void);
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat(void);

		Bureaucrat&			operator=(const Bureaucrat& other);
		const std::string&	getName(void) const;
		int 				getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(AForm& form);
		void 				executeForm(const AForm& form) const;


	private:
		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif