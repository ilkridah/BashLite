/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:01:13 by ilkridah          #+#    #+#             */
/*   Updated: 2022/10/25 04:01:14 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<iostream>
int main()
{
   std::string str = "HI THIS IS BRAIN";
   std::string *stringPTR = &str;
   std::string &stringREF = str;

   std::cout << "String = " << str << std::endl;
   std::cout << "Adress of String = " << &str << std::endl;

    std::cout << "StringPTR = " << *stringPTR << std::endl;
    std::cout << "Adress of StringPTR = " << &stringPTR << std::endl;

    std::cout << "StringREF = " << stringREF << std::endl;
    std::cout << "Adress of StringREF = " << &stringREF << std::endl;
}