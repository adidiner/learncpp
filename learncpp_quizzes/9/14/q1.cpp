#include <algorithm>
#include <iostream>
#include <string>

int input_name_count() {
    int count {};
    std::cout << "How many names would you like to enter? ";
    std::cin >> count;
    return count;
}

void input_names(std::string* names, int length) {
    for (int i {}; i < length; ++i) { 
        std::cout << "Enter name #" << i + 1 << ": ";
        std::cin >> names[i];
    }
}

void print_names(std::string* names, int length) {
    for (int i {}; i < length; ++i) {
        std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
    }
}

int main() {
    int count {input_name_count()};
    auto* names {new std::string[count]{}};
    input_names(names, count);

    std::sort(names, names + count);
    std::cout << "\nHere is your sorted list:\n";
    print_names(names, count);

    delete[] names;

    return 0;
}
