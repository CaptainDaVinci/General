#include <iostream>
#include <random>

/*
    A primality test algorithm which improves upon the Fermat's
    theorem.

    1. Handle base cases when given number p = 1, 2, 3 or any other even
    number.

    2. Then let s = p - 1 (s will be even). Express p - 1 in the form of 2^s * d.

    3. Pick a random number 'a' between 1 and p - 1, calculate x = a ^ s (mod p).

    4. While x != p - 1 and x != 1 and s != n - 1:
        x = x * x (mod p)
        s = s * 2

    5. if x != p - 1 and s % 2 == 0, then p is composite, else its prime.
*/

std::random_device rd;
std::mt19937 mt(rd());

inline long long mulmod(long long a, long long b, long long p) {
    return ((a % p) * (b % p)) % p;
}

inline long long expmod(long long a, long long b, long long p) {
    long long res = 1;

    while (b) {
        if (b & 1) {
            res = mulmod(res, a, p);
        }

        b /= 2;
        a = mulmod(a, a, p);
    }

    return res;
}

bool isPrime(long long p) {
    if (p <= 1) return false;
    if (p == 2 || p == 3) return true;
    if (p % 2 == 0) return false;

    long long s = p - 1;
    while (s % 2 == 0) {
        s /= 2;
    }

    std::uniform_int_distribution<long long> dist(1, p - 1);
    for (long long i = 0; i < 10; ++i) {
        long long a = dist(mt);
        long long x = expmod(a, s, p);
        long long temp = s;
        while (temp != p - 1 && x != 1 && x != p - 1) {
            x = mulmod(x, x, p);
            temp *= 2;
        }

        if (x != p - 1 && temp % 2 == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    long long a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    if (isPrime(a)) {
        std::cout << "Yes" << '\n';
    } else {
        std::cout << "No" << '\n';
    }
}
