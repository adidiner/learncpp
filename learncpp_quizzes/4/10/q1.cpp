#include <iostream>

int main() {
    int x{};
    std::cout << "Please enter a 1-digit number: ";
    std::cin >> x;
    if (x == 2 || x == 3 || x == 5 || x == 7) {
        std::cout << x << " is prime\n";
    } else {
        std::cout << x << " is not prime\n";
    }
    
    return 0;
}