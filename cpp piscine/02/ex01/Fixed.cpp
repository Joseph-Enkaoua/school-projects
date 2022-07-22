#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    _fixed_point_num = 0;
}

Fixed::Fixed( const Fixed & other ){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed( const int num ){
    std::cout << "Int constructor called" << std::endl;
	_fixed_point_num = num << _fractional_bits;
}

Fixed::Fixed( const float num ){
    std::cout << "Float constructor called" << std::endl;
	_fixed_point_num = (round(num * (1 << _fractional_bits)));
}

Fixed & Fixed::operator=( const Fixed & rhs ){
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixed_point_num = rhs._fixed_point_num;
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

float	Fixed::to_Float( void ) const {
	return ((double)_fixed_point_num / (double(1 << _fractional_bits)));
}

int		Fixed::toInt( void ) const {
	return (_fixed_point_num / (1 << _fractional_bits));
}

std::ostream	&operator<<(std::ostream &out, const Fixed &tmp){
	out << tmp.to_Float();
	return (out);
}