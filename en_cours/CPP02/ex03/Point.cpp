#include "Point.hpp"

Point::Point() : m_x(Fixed(0)), m_y(Fixed(0)) {}

Point::Point(const float x, const float y) : m_x(Fixed(x)), m_y(Fixed(y)) {}

Point::Point(const Point& other) : m_x(other.m_x), m_y(other.m_y) {}

Point&	Point::operator=(const Point& other)
{
	if (this != &other)
	{
		m_x = other.m_x;
		m_y = other.m_y;
	}
	return (*this);
}

Point::~Point() {}

const Fixed&	Point::getX() const {return (m_x);}
const Fixed&	Point::getY() const {return (m_y);}

void			Point::setX(Fixed& x) {m_x = x;}
void			Point::setY(Fixed& y) {m_y = y;}