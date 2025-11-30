#include "../include/trapezoid.hpp"
#include <cmath>
#include <iostream>

Trapezoid::Trapezoid() : lB(0,0), rB(4,0), lT(1,3), rT(3,3) {}

Trapezoid::Trapezoid(Point a, Point b, Point c, Point d) : lB(a), rB(b), lT(c), rT(d) {}

Point Trapezoid::centre() const {
    double x = (lB.x + rB.x + lT.x + rT.x) / 4;
    double y = (lB.y + rB.y + lT.y + rT.y) / 4;
    return Point(x, y);
}

double Trapezoid::area() const {
    double h = lT.y - lB.y;
    double b1 = rB.x - lB.x;
    double b2 = rT.x - lT.x;
    return (b1 + b2) * h / 2;
}

std::istream& Trapezoid::read(std::istream& is) {
    is >> lB.x >> lB.y >> rB.x >> rB.y >> lT.x >> lT.y >> rT.x >> rT.y;

    if (lB == rB ||lB == lT || lB == rT || rB == lT || rB == rT || lT == rT)
        throw "dublicate points";

    if (fabs(lB.y - rB.y) > 1e-9)
        throw "not trapezoid";

    return is;
}

std::ostream& Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid" << lB.x << " " << lB.y << " "
       << rB.x << " " << rB.y << " " << lT.x << " " << lT.y << " "
       << rT.x << " " << rT.y;
    return os;
}

bool Trapezoid::equal(const Figure& other) const {
    const Trapezoid* t = dynamic_cast<const Trapezoid*>(&other);
    if (!t) return false;
    return lB == t->lB && rB == t->rB && lT == t->lT && rT == t->rT;
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        lB = other.lB;
        rB = other.rB;
        lT = other.lT;
        rT = other.rT;
    }
    return *this;
}