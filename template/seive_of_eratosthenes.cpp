// Sieve of Eratosthenes
// 
// Author: Nandeesh Bhatrai
//
// Desc: Find the prime numbers from 1 - n

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// returns a list of bools where the index is the number and the value is whether it is prime or not

vector<bool> seive(long n) {
    vector<bool> primes(n + 1, 1);
    primes[0] = primes[1] = 0;
    for (long index = 2; index * index <= n; ++index) {
        if (primes[index]) {
            for (long i = index * index; i <= n; i += index) {
                primes[i] = 0;
            }
        }
    }
    return primes;
}

void printVector(vector<bool> &vc) {
	for (int i = 0; i < vc.size(); ++i)
		cout << vc[i] << " ";
	cout << endl << endl;
}

int main() {
	long n;
	cin >> n; // number to check for primes up to

	vector<bool> primes = seive(n);
	printVector(primes);
}