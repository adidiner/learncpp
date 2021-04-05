#include <iostream>

void print_binary(unsigned int n) {
    if (n == 0) {
        return;
    }

    int bit = n & 1;
    print_binary(n >> 1);
    std::cout << bit;
}

int main() {
    print_binary(2);
    std::cout << '\n';
    print_binary(3);
    std::cout << '\n';
    print_binary(5);
    std::cout << '\n';
    print_binary(static_cast<unsigned int>(-15));
    std::cout << '\n';
    return 0;
}
