#include <iostream>
#include <vector>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes
vector<int> generatePrimes(int max_limit) {
    vector<bool> is_prime(max_limit + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= max_limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= max_limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

// Recursive function to generate numbers and count valid ones
void generateNumbers(int index, int divisor_count, long long current_num, const vector<int>& primes, long long limit, int& count) {
    if (current_num > limit) return;
    if (index >= primes.size()) return;

    // Check if the divisor count is prime
    if (divisor_count > 1 && binary_search(primes.begin(), primes.end(), divisor_count)) {
        ++count;
    }

    // Try all possible exponents for the current prime
    long long power = 1;
    for (int exp = 0; ; ++exp) {
        if (current_num * power > limit) break;
        generateNumbers(index + 1, divisor_count * (exp + 1), current_num * power, primes, limit, count);
        power *= primes[index];
        if (power > limit || power == 0) break; // Avoid overflow
    }
}

int main() {
    long long limit = 1e12;
    int prime_limit = 1000; // Generate primes up to this value
    vector<int> primes = generatePrimes(prime_limit);

    int count = 0;
    generateNumbers(0, 1, 1, primes, limit, count);

    cout << "Count of numbers with prime divisor counts: " << count << endl;
    return 0;
}
