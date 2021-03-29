#include <iostream>

int main() {
    for (int i {1}; i <= 5; ++i) {
        for (int j {}; j < 5 - i; ++j) {
            std::cout << "  ";
        }

        for (int j {i}; j >= 1; --j) {
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "bonus: \n";
    for (int i {1}; i <= 5; ++i) {
        for (int j {}; j < 5 - i; ++j) {
            std::cout << ' ';
        }

        for (int j {i}; j >= 1; --j) {
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
