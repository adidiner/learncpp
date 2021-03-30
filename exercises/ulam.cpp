#include <iostream>
#include <vector>

int ulam(int n) {
    std::vector<int> ulam_numbers(n);
    ulam_numbers[0] = 1;
    ulam_numbers[1] = 2;
    
    std::vector<int> ways(n); // ways[i] = ways to make i with previous ulam numbers
    ways[3] = 1;
    int max_next = 3; // maximum size of the next ulam numbers
    for (std::vector<int>::size_type i {2}; i < ulam_numbers.size(); ++i) {
        // find the next ulam number
        for (int num {ulam_numbers[i - 1] + 1}; num <= max_next; ++num) {
            // num is the next ulam number
            if (ways[num] == 1) {
                ulam_numbers[i] = num;
                break;
            }
        }

        // resize ways if needed
        max_next = ulam_numbers[i - 1] + ulam_numbers[i]; 
        if (max_next >= ways.size()) {
            ways.resize(max_next + 1);
        }

        // update ways according to the new number
        for (std::vector<int>::size_type j {}; j < i; ++j) {
            ways[ulam_numbers[j] + ulam_numbers[i]]++;
        }
    }
    return ulam_numbers[n - 1];
}

int main() {
    std::cout << ulam(10) << '\n';
    std::cout << ulam(206) << '\n';
    return 0;
}