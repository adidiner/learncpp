#include <iostream>

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    for (int i = 0; i < 7; ++i) {
        std::cout << factorial(i) << '\n';
    }

    return 0;
}
