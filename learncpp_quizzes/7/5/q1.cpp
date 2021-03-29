#include <iostream>

int calculate(int a, int b, char operation) {
    switch (operation) {
        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            return a / b;

        case '%':
            return a % b;

        default:
            // They asked for the function to print an error, idk
            std::cout << "ERROR: Invalid operator\n";
            return 0;
    }
}

int main() {
    // I copied the main from the solution
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
 
    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;
 
    std::cout << "Enter a mathematical operator (+, -, *, /, or %): ";
    char op{};
    std::cin >> op;
 
    std::cout << x << ' ' << op << ' ' << y << " is " << calculate(x, y, op) << '\n';
    return 0;
}
