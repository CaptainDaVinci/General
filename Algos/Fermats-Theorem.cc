/*
    Based on fermat's theorem that a^(p - 1) = 1 (mod p)
    if and only if p is prime. We check for random values of a
    over a number of iterations and if for any value of a,
    a^(p - 1) != 1 (mod p), then p is not prime.

    NOTE: This method fails for Charmichael numbers!
*/

#include <iostream>
#include <random>

std::random_device rd;
std::mt19937 mt(rd());

long long mulmod(int a, int b, int p) {
    return ((a % p) * (b % p)) % p;
}

long long expmod(int a, int n, int p) {
    int res = 1;

    while (n) {
        if (n & 1) {
            res = mulmod(res, a, p);
        }

        n /= 2;
        a = mulmod(a, a, p);
    }

    return res;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n != 2 && n % 2 == 0) return false;

    std::uniform_int_distribution<int> dist(2, n - 1);

    for (int i = 0; i < 10; ++i) {
        int a = dist(mt);
        if (expmod(a, n - 1, n) != 1) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    std::cin >> n;

    if (isPrime(n)) {
        std::cout << "Yes" << '\n';
    } else {
        std::cout << "No" << '\n';
    }
}
