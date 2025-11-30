#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
    
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

bool operator==(const Point& a, const Point& b);

class Figure {    
    friend std::istream& operator>>(std::istream& is, Figure& figure);
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
    friend bool operator==(const Figure& figure1, const Figure& figure2);
    
public:
    virtual Point centre() const = 0;
    explicit operator double() const;

    virtual ~Figure() = default;
    
protected: 
    virtual std::istream& read(std::istream& is) = 0;
    virtual std::ostream& print(std::ostream& os) const = 0;
    virtual double area() const = 0;
    virtual bool equal(const Figure& other) const = 0;
};

std::istream& operator>>(std::istream& is, Figure& figure);
std::ostream& operator<<(std::ostream& os, const Figure& figure);
bool operator==(const Figure& figure1, const Figure& figure2);

#endif