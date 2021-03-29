#include <iostream>

int main() {
    for (int outer {5}; outer >= 1; --outer) {
        for (int inner {outer}; inner >= 1; --inner) {
            std::cout << inner << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
