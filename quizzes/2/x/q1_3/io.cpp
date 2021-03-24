#include "io.h"
#include <iostream>

int read_number() {
    int input{};
    std::cin >> input;
    return input;
}

void write_answer(int answer) {
    std::cout << answer << '\n';
}
