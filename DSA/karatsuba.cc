#include <iostream>
#include <cmath>

long long int karatsuba(long long int x, long long int y);
int ndigit(long long int x, long long int y);
long long int left(long long int x, int n);
long long int right(long long int x, int n);

int main()
{
    int x, y;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;

    std::cout << x << " * " << y << " = "
              << karatsuba(x, y) << '\n';
}

long long int karatsuba(long long int x, long long int y)
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

int ndigit(long long int x, long long int y)
{
    int nx, ny;

    for(nx = 0; x; x /= 10, ++nx);
    for(ny = 0; y; y /= 10, ++ny);

    return (nx > ny) ? nx : ny;
}

long long int left(long long int x, int n)
{
    return x / pow(10, n);
}

long long int right(long long int x, int n)
{
    return x % static_cast<int>(pow(10, n));
} 