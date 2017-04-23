#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
#include <ctime>

long long int splitInversions(std::vector<int> &ivec, int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;

    std::vector<int> left(n1), right(n2);

    for(int i = 0; i < n1; ++i)
        left[i] = ivec[i + l];
    
    for(int i = 0; i < n2; ++i)
        right[i] = ivec[i + m + 1];
    
    int i = 0, j = 0, k = l;
    long long int countInv = 0;

    while(i < n1 && j < n2)
    {
        if(left[i] > right[j])
        {
            ivec[k++] = right[j++];
            countInv += static_cast<long long int>(n1) - static_cast<long long int>(i);
        }

        else
            ivec[k++] = left[i++];
    }

    while(i < n1)
        ivec[k++] = left[i++];
    
    while(j < n2)
        ivec[k++] = right[j++];

    return countInv;
}

long long int inversions(std::vector<int> &ivec, int l, int h)
{
    if(l >= h)
        return 0;
    
    int m = (l + h) / 2;
    long long int x = inversions(ivec, l, m);
    long long int y = inversions(ivec, m + 1, h);
    long long int z = splitInversions(ivec, l, m, h);

    return x + y + z;
}

long long int naiveInv(std::vector<int> &ivec)
{
    long long int countInv = 0;

    for(size_t i = 0; i < ivec.size() - 1; ++i)
        for(size_t j = i + 1; j < ivec.size(); ++j)
            if(ivec[i] > ivec[j])
                ++countInv;
    
    return countInv;
}

int main()
{
    int n;
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> gen(1, 1000);

    std::cout << "Size: ";
    std::cin >> n;
    std::vector<int> ivec;

    for(int i = 0; i < n; ++i)
    {
        int num = gen(engine);
        ivec.push_back(num);
    }
    
    clock_t start, end;
    std::vector<int> temp(ivec.begin(), ivec.end());

    start = clock();
    std::cout << "Inversions: " << inversions(ivec, 0, n - 1)
              << '\n';
    end = clock();
              
    std::cout << "Time Taken: " << std::fixed 
              << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n\n";
            
    start = clock();
    std::cout << "Inversions: " << naiveInv(temp)
              << '\n';
    end = clock();

    std::cout << "Time Taken(Naive): " << std::fixed 
              << static_cast<double>(end - start) / CLOCKS_PER_SEC << '\n';
}