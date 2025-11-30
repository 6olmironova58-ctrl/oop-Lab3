#ifndef RHOMBUS_HPP
#define RHOMBUS_HPP

#include "figure.hpp"

class Rhombus : public Figure {
private:
    Point p1, p2, p3, p4;
    
public:
    Rhombus();
    Rhombus(Point a, Point b, Point c, Point d);
    
    Point centre() const override;
    double area() const override;
    
    Rhombus& operator=(const Rhombus& other);
    
protected:
    std::istream& read(std::istream& is) override;
    std::ostream& print(std::ostream& os) const override;
    bool equal(const Figure& other) const override;
};

#endif