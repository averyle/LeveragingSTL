#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

bool anyPrime(const std::vector<int>& values);

int main() {
    auto integers = randomIntegers();
    std::cout << "Integers: " << integers << "\n";
    std::cout << "Are there any primes? " << (anyPrime(integers) ? "yes" : "no") << "\n";
}

bool isPrime(int num, int div) {
    if (num == 0 || num == 1) {
        return false;
    }
    if (div == 1) {
        return true;
    }
    if (num % div == 0) {
        return false;
    }
    return isPrime(num, div - 1);
}

bool anyPrime(const std::vector<int>& values) {
    // TODO: return true if any of the values are prime numbers
    auto result = false;

    result = (std::find_if(values.begin(), values.end(), [](int num) {return isPrime(num, num - 1);}) != values.end());
    
    return result;
}


