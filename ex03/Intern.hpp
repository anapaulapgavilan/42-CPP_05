/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:32:44 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 11:26:35 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private:
		typedef struct	s_form
		{
			std::string	type;
			AForm		*form;
		}				t_form;
	public:
		Intern(void);
		Intern(const Intern& other);
		~Intern(void);

		Intern&		operator=(const Intern& other);
		AForm		*makeForm(const std::string& formName, const std::string& target) const;
};

#endif