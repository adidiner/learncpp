#include <iostream>

struct Fraction {
    int numertor {};
    int denuminator {};
};

Fraction input_fraction() {
    Fraction f {};
    std::cout << "Enter numertor: ";
    std::cin >> f.numertor;
    std::cout << "Enter denuminator: ";
    std::cin >> f.denuminator;
    return f;
}

double multiply(Fraction a, Fraction b) {
    return static_cast<double>(a.numertor * b.numertor) / 
           (a.denuminator * b.denuminator);
}

int main() {
    Fraction f1 {input_fraction()}, f2 {input_fraction()};
    std::cout << "Multiplication: " << multiply(f1, f2) << '\n';
    return 0;
}
