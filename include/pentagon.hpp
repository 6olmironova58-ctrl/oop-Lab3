#ifndef PENTAGON_HPP
#define PENTAGON_HPP

#include "figure.hpp"
#include <array>

class Pentagon : public Figure {
private:
    std::array<Point, 5> p;
    
public:
    Pentagon();
    Pentagon(Point a, Point b, Point c, Point d, Point e);
    
    Point centre() const override;
    double area() const override;
    
    Pentagon& operator=(const Pentagon& other);
    
protected:
    std::istream& read(std::istream& is) override;
    std::ostream& print(std::ostream& os) const override;
    bool equal(const Figure& other) const override;
};

#endif