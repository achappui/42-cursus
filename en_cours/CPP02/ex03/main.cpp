#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

// Prototype de la fonction bsp
bool bsp(const Point a, const Point b, const Point c, const Point p);
bool isPointOnSegment(const Point& a, const Point& b, const Point& p);

int main(void)
{
    // Définition des points pour les triangles
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);

    Point e(-2.0f, 6.0f);
    Point f(-2.0f, 2.0f);
    Point g(4.0f, 2.0f);

    Point h(4.0f, 4.0f);
    Point i(7.0f, 4.0f);
    Point j(4.0f, 7.0f);

    // Point à tester
    Point p(2.0f, 2.0f);  // Ce point est à l'intérieur du premier triangle

    // Test pour le triangle (a, b, c)
    std::cout << "Testing point p (2.0, 2.0) in triangle (a, b, c): ";
    if (bsp(a, b, c, p))
        std::cout << "Inside" << std::endl;
    else if (isPointOnSegment(a, b, p) || isPointOnSegment(b, c, p) || isPointOnSegment(c, a, p))
        std::cout << "On border" << std::endl;
    else
        std::cout << "Outside" << std::endl;

    // Test pour le triangle (e, f, g)
    std::cout << "Testing point p (2.0, 2.0) in triangle (e, f, g): ";
    if (bsp(e, f, g, p))
        std::cout << "Inside" << std::endl;
    else if (isPointOnSegment(e, f, p) || isPointOnSegment(f, g, p) || isPointOnSegment(g, e, p))
        std::cout << "On border" << std::endl;
    else
        std::cout << "Outside" << std::endl;

    // Test pour le triangle (h, i, j)
    std::cout << "Testing point p (2.0, 2.0) in triangle (h, i, j): ";
    if (bsp(h, i, j, p))
        std::cout << "Inside" << std::endl;
    else if (isPointOnSegment(h, i, p) || isPointOnSegment(i, j, p) || isPointOnSegment(j, h, p))
        std::cout << "On border" << std::endl;
    else
        std::cout << "Outside" << std::endl;

    return 0;
}

// Fonction pour vérifier si un point est sur un segment
bool isPointOnSegment(const Point& a, const Point& b, const Point& p)
{
    return (std::min(a.getX(), b.getX()) <= p.getX() && p.getX() <= std::max(a.getX(), b.getX()) &&
            std::min(a.getY(), b.getY()) <= p.getY() && p.getY() <= std::max(a.getY(), b.getY()));
}
