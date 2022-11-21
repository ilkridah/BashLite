/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 06:55:47 by ilkridah          #+#    #+#             */
/*   Updated: 2022/11/21 06:55:48 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream> 
#include <math.h>
class Fixed
{
    private:
        int _fixedPointValue;
        const static int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const int parameter);
        Fixed(const float parameter);
        Fixed( const Fixed& old_obj);
        Fixed &operator=(const Fixed& old_obj);
        ~Fixed();
        float toFloat( void ) const;
        int toInt ( void ) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        //op
        bool operator < (const Fixed &p) const;
        bool operator > (const Fixed &p) const;
        bool operator >= (const Fixed &p) const;
        bool operator <= (const Fixed &p) const;
        bool operator == (const Fixed &p) const;
        bool operator != (const Fixed &p) const;
        
        //ap
        Fixed operator+ (const Fixed &p);
        Fixed operator- (const Fixed &p);
        Fixed operator* (const Fixed &p);
        Fixed operator/ (const Fixed &p);
        //io
        Fixed &operator ++(void);
        Fixed operator ++(int);
        Fixed &operator --(void);
        Fixed operator --(int);
        //static
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
    
        
};

std::ostream &operator << (std::ostream & os, const Fixed &fixed);
#endif