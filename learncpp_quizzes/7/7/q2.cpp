#include <iostream>

int main() {
    for (char c {'a'}; c <= 'z'; ++c) {
        std::cout << c << ' ' << static_cast<int>(c) << '\n';
    }

    return 0;
}
