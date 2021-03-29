#include <iostream>

bool pass_or_fail() {
    static int count {};
    ++count;
    return (count <= 3);
}

int main() {
    std::cout << "User #1: " << (pass_or_fail() ? "Pass" : "Fail") << '\n';
    std::cout << "User #2: " << (pass_or_fail() ? "Pass" : "Fail") << '\n';
    std::cout << "User #3: " << (pass_or_fail() ? "Pass" : "Fail") << '\n';
    std::cout << "User #4: " << (pass_or_fail() ? "Pass" : "Fail") << '\n';
    std::cout << "User #5: " << (pass_or_fail() ? "Pass" : "Fail") << '\n';
 
    return 0;
}
