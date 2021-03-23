#include <iostream>
#include <string>

int main() {
    std::string name{};
    int age{};

    std::cout << "Enter your full name: ";
    std::getline(std::cin, name);
    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "You've lived " << static_cast<double>(age) / name.length()
              << " years for each letter in your name.\n";

    return 0;
}