#include <iostream>
#include <tuple>

/**
 * Find the index'th prine and calculate the number of iterations the 
 * fractran prime genration would take to reach a given prime.
 * 
 * @param prime_index The index of the given prime 
 * (the index of 2 is 1, 3 is 2..)
 * @return the prime, the number of iterations
 */
std::tuple<int, long long> fractran_primegen(int prime_index) {
    long long iterations {5};
    int a {1};
    for (int i {}; i < prime_index; ) {
        ++a;
        for (int b {a - 1}; b >= 1; --b) {
            if (a % b == 0) {
                // iteration count: performing a % b and updating state to a = a + 1
                iterations += 7 * a + b + 2 * (a / b) + 3;
                if (b == 1) {
                    ++i;
                }
                break;
            } else {
                // iteration count: performing a % b and updating state to b = b - 1
                iterations += 6 * a + 2 * (a / b) + 2;
            }
        }
    }
    iterations -= 3 * a + 2; // don't count last state update
    return {a, iterations};
}

int main() {
    int prime_index = 10001;
    auto [prime, iterations] = fractran_primegen(prime_index);
    std::cout << prime_index << "th prime: " << prime << '\n' 
              << "iterations: " << iterations << '\n';
    return 0;
}
