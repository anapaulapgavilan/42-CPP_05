/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:29:32 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 11:19:00 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#pragma once

#include "Form.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat {
	private:
		static const int	maxGrade = 1;
		static const int	minGrade = 150;
		const std::string	name;
		int					grade;

		Bureaucrat();

	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
		void signForm(Form& form);

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

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b);

#endif