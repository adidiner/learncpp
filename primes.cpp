#include <iostream>

constexpr int prime_index {10001};

int main() {
    int primes[prime_index] {};
    primes[0] = 2;
    int num {3};
    for (int i {1}; i < prime_index; ++num) {
        bool is_prime {true};
        // check if one of the previous primes divides the current number
        for (int p {}; primes[p] > 0; ++p) {
            if (num % primes[p] == 0) {
                is_prime = false;
                break;
            }
        }
        // no prime divides num -> num is prime
        if (is_prime) {
            primes[i] = num;
            ++i;
        }
    }
    std::cout << prime_index << "th prime: " << primes[prime_index - 1] << '\n';
}
