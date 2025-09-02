/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:29:07 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 10:05:24 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat Mariana("Mariana", 1);
    Bureaucrat Fernando("Fernando", 150);

    std::cout << "Created two bureaucrats !" << std::endl;
    std::cout << Mariana << std::endl;
    std::cout << Fernando << std::endl;

    std::cout << "\nLet's try creating Ana with grade 0" << std::endl;
    try
    {
        Bureaucrat Ana("Ana", 0);
    }
    catch (std::exception& e)
    {
        std::cout << "Cannot create Ana!" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nLet's try creating John with grade 151" << std::endl;
    try
    {
        Bureaucrat John("John", 151);
    }
    catch (std::exception& e)
    {
        std::cout << "Cannot create John!" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nLet's try promoting Mariana!" << std::endl;
    try
    {
        Mariana.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Cannot increment the grade of Mariana!" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nLet's try demoting Fernando!" << std::endl;
    try
    {
        Fernando.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Cannot decrement the grade of Fernando!" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;
    }

        std::cout << "\nLet's try demoting Mariana!" << std::endl;
    try
    {
        Mariana.decrementGrade();
        std::cout << "Mariana has been demoted!" << std::endl;
        std::cout << Mariana << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Cannot decrement the grade of Mariana!" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
