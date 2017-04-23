#include <iostream>
#include <cctype>
#include <string>

size_t max(size_t a, size_t b)
{
    return (a > b) ? a : b;
}

std::string calc(std::string x, std::string y);
std::string karatsuba(std::string x, std::string y);

int main()
{
    std::string x, y;
    std::cout << "Two Operands: ";
    std::cin >> x >> y;

    std::cout << x + " * " + y + " = " << karatsuba(x, y) << '\n';
}

std::string karatsuba(std::string x, std::string y)
{
    if(x.size() < 2 || y.size() < 2)
    {
        int a = std::stoi(x);
        int b = std::stoi(y);
        int c = a * b;
        std::string res = std::to_string(c);

        return res;
    }

    int digits = max(x.size(), y.size());
    int n = digits / 2;

    std::string a(x.begin(), x.begin() + n);
    std::string c(y.begin(), y.begin() + n);
    std::string b(x.begin() + n, x.end());
    std::string d(y.begin() + n, y.end());

    std::string ac = karatsuba(a, c);
    std::string bd = karatsuba(b, d);
    std::string tempa = std::to_string(std::stoi(a) + std::stoi(b));
    std::string tempb = std::to_string(std::stoi(c) + std::stoi(d));
    std::string abcd = karatsuba(tempa, tempb);
    tempa = std::to_string(std::stoi(ac) + std::stoi(bd));
    std::string mid = calc(abcd,tempa);

    return std::to_string(std::stoi(ac.append(2 * n, '0')) +  std::stoi(mid.append(n, '0')) + std::stoi(bd));
}

std::string calc(std::string x, std::string y)
{
    int a = std::stoi(x), b = std::stoi(y);
    int c = a - b;
    std::string res = std::to_string(c);
    return res;
}

