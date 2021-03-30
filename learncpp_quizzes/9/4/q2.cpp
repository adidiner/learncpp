#include <iostream>
#include <utility>

// Selection sort
int main() {
    int array[] {30, 50, 20, 10, 40};
    constexpr std::size_t length {std::size(array)};

    // sort
    for (std::size_t start {0}; start < length - 1; ++start) {
        int max_index = start;

        for (std::size_t i {start + 1}; i < length; ++i) {
            if (array[i] > array[max_index]) {
                max_index = i;
            }
        }

        std::swap(array[start], array[max_index]);
    }

    // print
    for (std::size_t i {0}; i < length; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
