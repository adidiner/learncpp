#include <iostream>

int double_number(int x) {
    return x * 2;
}

int main() {
    int x{ };
    std::cin >> x;
    std::cout << x << " doubled is " << double_number(x) << '\n';
    return 0;
}