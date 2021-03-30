#include <iostream>
#include <utility>

// Bubble sort
int main() {
    int array[] {6, 3, 2, 9, 7, 1, 5, 4, 8};
    constexpr std::size_t length {std::size(array)};

    // sort
    for (std::size_t i {0}; i < length; ++i) {
        bool sorted {true};
        for (std::size_t j {0}; j < length - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                sorted = false;
            }
        }

        // If no swap was done, array is sorted
        if (sorted) {
            break;
        }
    }

     // print
    for (std::size_t i {0}; i < length; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
