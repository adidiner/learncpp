#include <iostream>

void swap(int& a, int& b) {
    int temp{a};
    a = b;
    b = temp;
}

int main() {
    int a{1}, b{7};
    std::cout << "a = " << a << ", b = " << b << '\n';
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << '\n';
    return 0;
}
