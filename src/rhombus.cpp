#include "../include/rhombus.hpp"
#include <cmath>
#include <iostream>

Rhombus::Rhombus() : p1(0,1), p2(1,0), p3(0,-1), p4(-1,0) {}

Rhombus::Rhombus(Point a, Point b, Point c, Point d) : p1(a), p2(b), p3(c), p4(d) {}

Point Rhombus::centre() const {
    double x = (p1.x + p2.x + p3.x + p4.x) / 4;
    double y = (p1.y + p2.y + p3.y + p4.y) / 4;
    return Point(x, y);
}

double Rhombus::area() const {
    double d1 = sqrt(pow(p2.x - p4.x, 2) + pow(p2.y - p4.y, 2));
    double d2 = sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2));
    return (d1 * d2) / 2;
}

std::istream& Rhombus::read(std::istream& is) {
    is >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

    if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4)
        throw "duplicate points";
    
    double s1 = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    double s2 = sqrt(pow(p3.x - p2.x, 2) + pow(p3.y - p2.y, 2));
    double s3 = sqrt(pow(p4.x - p3.x, 2) + pow(p4.y - p3.y, 2));
    double s4 = sqrt(pow(p1.x - p4.x, 2) + pow(p1.y - p4.y, 2));

    if (fabs(s1 - s2) > 1e-9 || fabs(s2 - s3) > 1e-9 || fabs(s3 - s4) > 1e-9)
        throw "not thombus";

    return is;
}

std::ostream& Rhombus::print(std::ostream& os) const {
    os << "Rhombus " << p1.x << " " << p1.y << " "
       << p2.x << " " << p2.y << " " << p3.x << " " << p3.y << " "
       << p4.x << " " << p4.y;
    return os;
}

bool Rhombus::equal(const Figure& other) const {
    const Rhombus* r = dynamic_cast<const Rhombus*>(&other);
    if (!r) return false;
    return p1 == r->p1 && p2 == r->p2 && p3 == r->p3 && p4 == r->p4;
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this != &other) {
        p1 = other.p1;
        p2 = other.p2;
        p3 = other.p3;
        p4 = other.p4;
    }
    return *this;
}