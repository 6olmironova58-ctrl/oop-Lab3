#include "../include/pentagon.hpp"
#include <cmath>
#include <iostream>

Pentagon::Pentagon() {
    for (int i = 0; i < 5; ++i) {
        double a = 2 * M_PI * i / 5;
        p[i] = Point(cos(a), sin(a));
    }
}

Pentagon::Pentagon(Point a, Point b, Point c, Point d, Point e) {
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    p[4] = e;
}

Point Pentagon::centre() const {
    double x = 0, y = 0;
    for (int i = 0; i < 5; ++i) {
        x += p[i].x;
        y += p[i].y;
    }
    return Point(x / 5, y / 5);
}

double Pentagon::area() const {
    double s = 0;
    for (int i = 0; i < 5; ++i) {
        int j = (i + 1) % 5;
        s += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return fabs(s) / 2;
}

std::istream& Pentagon::read(std::istream& is) {
    for (int i = 0; i < 5; ++i)
        is >> p[i].x >> p[i].y;

    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (p[i] == p[j]) {
                throw "dublicate points";
            }
        }
    }
    return is;
}

std::ostream& Pentagon::print(std::ostream& os) const {
    os << "Pentagon";
    for (int i = 0; i < 5; ++i) 
        os << " " << p[i].x << " " << p[i].y;
    return os;
}

bool Pentagon::equal(const Figure& other) const {
    const Pentagon* pent = dynamic_cast<const Pentagon*>(&other);
    if (!pent) return false;
    for (int i = 0; i < 5; ++i)
        if (!(p[i] == pent->p[i])) return false;
    return true;
}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other)
        for (int i = 0; i < 5; ++i)
            p[i] = other.p[i];
    return *this;
}