#include <iostream>

int read_number() {
    int input{};
    std::cin >> input;
    return input;
}

void write_answer(int answer) {
    std::cout << answer << '\n';
}

int main() {
    int x { read_number() };
    int y { read_number() };
    write_answer(x + y);
    return 0;
}