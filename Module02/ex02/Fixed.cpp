/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 06:55:41 by ilkridah          #+#    #+#             */
/*   Updated: 2022/11/21 06:55:42 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default Constructor called\n";
    _fixedPointValue = 0;
}
Fixed::Fixed(const int parameter)
{
    std::cout << "Int Constructor called\n";
    _fixedPointValue = parameter << _fractionalBits;
}
Fixed::Fixed(const float parameter)
{
    std::cout << "Float Constructor called\n";
    _fixedPointValue = roundf(parameter * (1 << _fractionalBits));
}
Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& old_obj)
{
    std::cout << "Copy constructor called\n";
    _fixedPointValue = old_obj._fixedPointValue;
}

Fixed & Fixed::operator=(const Fixed& old_obj)
{
    std::cout << "Copy assignment oprater called\n";
    this->_fixedPointValue = old_obj._fixedPointValue;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    _fixedPointValue = raw;
}

int Fixed::toInt( void ) const
{
    return (_fixedPointValue >> _fractionalBits);
}

float Fixed::toFloat( void ) const
{
    return (((float)_fixedPointValue / (1 << _fractionalBits)));
}

std::ostream &operator <<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return (os);
}

bool Fixed::operator < (const Fixed &p) const
{
    return (this->_fixedPointValue < p._fixedPointValue);
}

bool Fixed::operator > (const Fixed &p) const
{
    return (this->_fixedPointValue > p._fixedPointValue);
}
bool Fixed::operator >= (const Fixed &p) const
{
    return (this->_fixedPointValue >= p._fixedPointValue);
}
bool Fixed::operator <= (const Fixed &p) const
{
    return (this->_fixedPointValue <= p._fixedPointValue);
}

bool Fixed::operator == (const Fixed &p) const
{
    return (this->_fixedPointValue == p._fixedPointValue);
}
bool Fixed::operator != (const Fixed &p) const
{
    return (this->_fixedPointValue != p._fixedPointValue);
}

Fixed Fixed::operator+ (const Fixed &p)
{
    Fixed ret;
    ret._fixedPointValue =this->_fixedPointValue + p._fixedPointValue;
    return ret;

}
Fixed Fixed::operator- (const Fixed &p)
{
    Fixed ret;
    ret._fixedPointValue=this->_fixedPointValue - p._fixedPointValue;
    return ret;
}
Fixed Fixed::operator* (const Fixed &p)
{
    Fixed ret;
    ret._fixedPointValue=roundf(this->_fixedPointValue * p._fixedPointValue)/(1 << _fractionalBits);
    return ret;
}
Fixed Fixed::operator/ (const Fixed &p)
{
    Fixed ret;
    ret._fixedPointValue=roundf(((float)this->_fixedPointValue /p._fixedPointValue) * (1 << _fractionalBits));
    return ret;
}

Fixed &Fixed::operator++(void)
{
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    this->_fixedPointValue++;
    return *this;
}
Fixed &Fixed::operator--(void)
{
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    this->_fixedPointValue--;
    return *this;
}

 Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a._fixedPointValue < b._fixedPointValue)
        return a;
    return b;
}

 Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a._fixedPointValue > b._fixedPointValue)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a._fixedPointValue < b._fixedPointValue)
        return a;
    return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a._fixedPointValue > b._fixedPointValue)
        return a;
    return b;
}




