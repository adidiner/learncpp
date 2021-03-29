#include <iostream>
#include <limits>

double get_number() {
    double input {};
    std::cout << "Enter a double value: ";
    std::cin >> input;
    return input;
}

char get_operator() {
    char input {};
    std::cout << "Enter one of the following: +, -, *, or /: ";
    std::cin >> input;
    return input;
}

double calculate(double x, double y, char op) {
    if (op == '+') {
        return x + y;
    } if (op == '-') {
        return x - y;
    } if (op == '*') {
        return x * y;
    } if (op == '/') {
        return x / y;
    }
    return std::numeric_limits<double>::quiet_NaN();
}

int main() {
    double x { get_number() };
    double y { get_number() };
    char op { get_operator() };
    std::cout << x << " " << op << " " << y
             << " is " << calculate(x, y, op) << '\n';
    return 0;
}
