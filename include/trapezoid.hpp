#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include "figure.hpp"

class Trapezoid : public Figure {
private:
    Point lB, rB, lT, rT;
    
public:
    Trapezoid();
    Trapezoid(Point lb, Point rb, Point lt, Point rt);
    
    Point centre() const override;
    double area() const override;
    
    Trapezoid& operator=(const Trapezoid& other);
    
protected:
    std::istream& read(std::istream& is) override;
    std::ostream& print(std::ostream& os) const override;
    bool equal(const Figure& other) const override;
};

#endif