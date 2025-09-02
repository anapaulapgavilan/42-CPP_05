/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:33:03 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 11:26:49 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern intern;
    AForm *f = NULL;

    f = intern.makeForm("shrubbery creation", "28C");
    std::cout << *f << std::endl;
    std::cout << std::endl;
    delete f;
    f = NULL;

    f = intern.makeForm("robotomy request", "A11");
    std::cout << *f << std::endl;
    std::cout << std::endl;
    delete f;
    f = NULL;

    f = intern.makeForm("presidential pardon", "A12");
    std::cout << *f << std::endl;
    std::cout << std::endl;
    
    Bureaucrat admin("Admin", 1);
    
    admin.signForm(*f);
    admin.executeForm(*f);
    
    delete f;
    f = NULL;

    f = intern.makeForm("undefined", "A0");
    delete f;

    return 0;
}
