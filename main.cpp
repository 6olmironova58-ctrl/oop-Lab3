#include <iostream>
#include "include/trapezoid.hpp"
#include "include/rhombus.hpp"
#include "include/pentagon.hpp"

int main() {
    Trapezoid trapezoid;
    Rhombus rhombus;
    Pentagon pentagon;

    std::cin >> trapezoid;
    std::cin >> rhombus;
    std::cin >> pentagon;

    Figure* figures[] = {&trapezoid, &rhombus, &pentagon};

    for (int i = 0; i < 3; ++i) {
        std::cout << *figures[i];
        Point centre = figures[i]->centre();
        std::cout << " Centre: " << centre.x << " " << centre.y;
        std::cout << " Area: " << static_cast<double>(*figures[i]) << '\n';
    }

    return 0;
}