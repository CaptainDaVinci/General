#include <iostream>
#include <cmath>

using lld = long long int;

lld karatsuba(lld x, lld y);
int ndigit(lld x, lld y);
lld left(lld x, int n);
lld right(lld x, int n);

int main()
{
    int x, y;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;

    std::cout << x << " * " << y << " = "
              << karatsuba(x, y) << '\n';
}

lld karatsuba(lld x, lld y)
{
    if(x < 10 || y < 10)
        return x * y;
    
    int digits = ndigit(x, y);
    int n = digits / 2;

    int a = left(x, n);
    int c = left(y, n);
    int b = right(x, n);
    int d = right(y, n);

    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int abcd = karatsuba((a + b), (c + d));     // (a + b) * (c + d)

    return ac * pow(10, n * 2) + (abcd - ac - bd) * pow(10, n) + bd;
}

int ndigit(lld x, lld y)
{
    int nx, ny;

    for(nx = 0; x; x /= 10, ++nx);
    for(ny = 0; y; y /= 10, ++ny);

    return (nx > ny) ? nx : ny;
}

lld left(lld x, int n)
{
    return x / pow(10, n);
}

lld right(lld x, int n)
{
    return x % static_cast<int>(pow(10, n));
} 