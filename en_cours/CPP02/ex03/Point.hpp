#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
private:
	Fixed	m_x;
	Fixed	m_y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	Point&	operator=(const Point& other);
	~Point();

	const Fixed&	getX() const;
	const Fixed&	getY() const;
	void			setX(Fixed& x);
	void			setY(Fixed& y);
};

#endif