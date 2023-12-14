import sys
import io
import os
import math
from typing import List, Tuple

# Disable buffering for interactive problems
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

# Uncomment the following lines if you need to use external C++ code
# import subprocess
# subprocess.run(['g++', '-O3', 'external_code.cpp', '-o', 'external_code'])

# Common optimization flags for GCC
# You can adjust these based on your needs
# flags = ['-O3', '-march=native', '-funroll-loops', '-fno-stack-protector', '-fno-strict-aliasing']
# os.environ['CXXFLAGS'] = '- '.join(flags)

def prime(n: int) -> bool:
    if n <= 1:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    for i in range(5, int(math.sqrt(n)) + 1, 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False
    return True

def print_prime_factors(n: int) -> None:
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            print(i, end=' ')
    for i in range(int(math.sqrt(n)) + 1, 0, -1):
        if n % i == 0:
            print(n // i, end=' ')

def sieve(n: int) -> List[bool]:
    primes = [True] * (n + 1)
    primes[0] = primes[1] = False
    for index in range(2, int(math.sqrt(n)) + 1):
        if primes[index]:
            for i in range(index * index, n + 1, index):
                primes[i] = False
    return primes

def solve() -> None:
    # Your solution goes here
    pass

def main() -> None:
    # Uncomment the next line if you are using USACO
    # usaco("filename")

    # Common input/output optimizations
    # sys.set_in(input)
    # sys.stdout = io.BytesIO()

    t = int(input().decode())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    # Uncomment the following lines if you want to measure execution time
    # import time
    # start_time = time.time()

    main()

    # Uncomment the following lines if you want to measure execution time
    # print("Execution time:", time.time() - start_time, "seconds")
