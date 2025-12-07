#include <iostream>
#include "include/trapezoid.hpp"
#include "include/rhombus.hpp"
#include "include/pentagon.hpp"

double area_sum(Figure** figures, size_t size) {
    double total = 0;
    for (size_t i = 0; i < size; i++)
        if (figures[i] != nullptr)
            total += static_cast<double>(*figures[i]);

    return total;
}

void pop_figure(Figure** figures, size_t* size, int index) {
    if (index < 0 || index >= *size) return;

    for (size_t i = index; i < *size - 1; ++i)
        figures[i] = figures[i + 1];
    
    figures[*size - 1] = nullptr;
    --(*size);
}


int main() {
    Trapezoid trapezoid;
    Rhombus rhombus;

    std::cin >> trapezoid;
    std::cin >> rhombus;
    std::cin >> rhombus;

    Figure* figures[] = {&trapezoid, &rhombus, &rhombus};
    size_t n = 3;

    for (int i = 0; i < n; ++i) {
        std::cout << *figures[i];
        Point centre = figures[i]->centre();
        std::cout << " Centre: " << centre.x << " " << centre.y;
        std::cout << " Area: " << static_cast<double>(*figures[i]) << '\n';
    }

    double total = area_sum(figures, n);
    std::cout << "Total area: " << total << "\n\n";

    std::cout << "pop(1)\n";
    pop_figure(figures, &n, 1);

    std::cout << "Number of figures: " << n << "\n";

    total = area_sum(figures, n);
    std::cout << "Total area: " << total << "\n\n";

    return 0;
}