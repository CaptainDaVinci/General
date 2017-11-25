#include <iostream>

using ll = long long;

/*
    Calculate a ^ b (mod m) in O(logb) time. 
*/

ll mulmod(ll a, ll b, ll p) {
    ll res = 0;

    while (b) {
        if (b & 1) {
            res = (res + a) % p;
        }

        b /= 2;
        a = (a * 2) % p;
    }

    return res;
}

ll expmod(ll a, ll b, ll p) {
    ll res = 1;

    while (b) {
        if (b & 1) {
            res = mulmod(a, b, p);
        }

        b /= 2;
        a = mulmod(a, a, p);
    }

    return res;
}

int main() {
    ll a, b, p;
    std::cin >> a >> b >> p;
    std::cout << expmod(a, b, p) << '\n';
}
