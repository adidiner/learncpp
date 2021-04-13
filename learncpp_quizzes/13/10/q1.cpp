#include <iostream>
#include <string>

class Mystring {
private:
    std::string m_string;

public:
    Mystring(const std::string& string={}) : m_string{string} {}

    std::string operator()(int start, int length) {
        auto begin = static_cast<size_t>(start);
        auto end = static_cast<size_t>(start + length);
        std::string result{};
        for (size_t i = begin; i < end; ++i) {
            result += m_string[i];
        }
        return result;
        }
};

int main() {
    Mystring string{ "Hello, world!" };
    std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters
    return 0;
}
