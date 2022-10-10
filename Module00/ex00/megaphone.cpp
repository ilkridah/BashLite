/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:24:28 by ilkridah          #+#    #+#             */
/*   Updated: 2022/08/13 18:24:29 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac,char **av)
{
        char c;
        if(ac == 1)
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        for(int i = 1; av[i]; i++)
        {
            for(int j = 0; av[i][j]; j++){

                c = toupper(av[i][j]); 
                std::cout << c;
            }
        }
        std::cout << '\n';
    return 0;
}