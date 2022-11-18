/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 06:06:41 by ilkridah          #+#    #+#             */
/*   Updated: 2022/11/18 06:06:42 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;
    public:
            Fixed();
            Fixed(const Fixed &copy);
            ~Fixed();
            Fixed& operator=(const Fixed &copy);
            int getRawBits(void) const;
            void setRawBits(int const raw);
};

#endif