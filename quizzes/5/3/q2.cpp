#include <iostream>

int get_integer() {
    int input {};
    std::cout << "Enter an integer: ";
    std::cin >> input;
    return input;
}

bool is_even(int num) {
    return (num % 2) == 0;
}

int main() {
    int num {get_integer() };
    if (is_even(num)) {
        std::cout << num << " is even\n";
    } else {
        std::cout << num << " is odd\n";
    }

    return 0;
}
