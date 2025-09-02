/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:31:13 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 11:02:04 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string       target;
		
		PresidentialPardonForm(void);

	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm(void);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		const std::string&	getTarget(void) const;
		void				execute(const Bureaucrat& executor) const;
};

#endif