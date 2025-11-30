#include "../include/figure.hpp"

Figure::operator double() const {
    return area();
}

bool operator==(const Point& a, const Point& b) {
    return fabs(a.x - b.x) < 1e-9 && fabs(a.y - b.y) < 1e-9;
}

std::istream& operator>>(std::istream& is, Figure& figure) {
    return figure.read(is);
}

std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    return figure.print(os);
}

bool operator==(const Figure& figure1, const Figure& figure2) {
    return figure1.equal(figure2);
}