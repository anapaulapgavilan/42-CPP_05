/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pper <ana-pper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 09:30:03 by ana-pper          #+#    #+#             */
/*   Updated: 2025/09/02 10:32:36 by ana-pper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "Let's create a form with grade to sign 0" << std::endl;
    try
    {
        Form f("A110", 0, 1);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nLet's create a form with grade to execute 0" << std::endl;
    try
    {
        Form f("A111", 1, 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nLet's create a form with grade to execute 151" << std::endl;
    try
    {
        Form f("A112", 1, 151);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nLet's create a form with grade to sign 151" << std::endl;
    try
    {
        Form f("A113", 151, 1);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nLet's sign a form with an appropriate bureaucrat\n" << std::endl;
    try
    {
        Bureaucrat Mariana("Mariana", 1);
        Form f("A114", 150, 150);

        std::cout << f << std::endl;
        Mariana.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "\nLet's sign a form with an inappropriate bureaucrat\n" << std::endl;
    try
    {
        Bureaucrat Ana("Ana", 10);
        Form f("A115", 1, 1);

        std::cout << f << std::endl;
        Ana.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n\nTesting copy constructor for Form:\n" << std::endl;
    try
    {
        Form original("TestForm", 100, 100);
    
        Form copy(original);
        std::cout << "Original form: " << original << std::endl;
        std::cout << "Copied form:   " << copy << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception during copy constructor test: " << e.what() << std::endl;
    }

    std::cout << "\nTesting copy assignment operator for Form:\n" << std::endl;
    try
    {
        Form formA("FormA", 90, 80);
        Form formB("FormB", 100, 70);
        std::cout << "Before assignment:" << std::endl;
        std::cout << "formA: " << formA << std::endl;
        std::cout << "formB: " << formB << std::endl;

        formB = formA;
        std::cout << "\nAfter assignment:" << std::endl;
        std::cout << "formA: " << formA << std::endl;
        std::cout << "formB: " << formB << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception during copy assignment test: " << e.what() << std::endl;
    }
    
    return 0;
}
