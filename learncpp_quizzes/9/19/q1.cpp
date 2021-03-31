#include <iostream>
#include <string>

std::string input_name() {
    std::string name {};
    std::cout << "Enter a name: ";
    std::cin >> name;
    return name;
}

int main() {
    constexpr std::string_view names[] 
          {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

    std::string_view to_find {input_name()};
    bool found {false};
    for (auto name : names) {
        if (name == to_find) {
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << to_find << " was found.\n";
    } else {
        std::cout << to_find << " was not found.\n";
    }
    
    return 0;
}
