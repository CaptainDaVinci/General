#include <iostream>
#include <vector>

void insertionSortRecursion(std::vector<int> &ivec, int n)
{
    if(n < 1)
        return ;
    
    insertionSortRecursion(ivec, n - 1);

    int key = ivec[n];
    int i = n - 1;

    while(i >= 0 && ivec[i] > key)
    {
        ivec[i + 1] = ivec[i];
        --i;
    }

    ivec[i + 1] = key;
}

void insertionSort(std::vector<int> &ivec)
{
    for(size_t j = 1; j < ivec.size(); ++j)
    {
        int key = ivec[j];
        int i = j - 1;

        while(i >= 0 && ivec[i] < key)
        {
            ivec[i + 1] = ivec[i];
            --i;
        }

        ivec[i + 1] = key;
    }
}

int main()
{
    int n;
    std::cout << "Enter the size: ";
    std::cin >> n;
    std::vector<int> ivec(n);

    std::cout << "Elements: ";
    for(int i = 0; i < n; ++i)
        std::cin >> ivec[i];

    insertionSort(ivec);
    insertionSortRecursion(ivec, n - 1);
    std::cout << "The sorted elements: ";

    for(const auto &i : ivec)
        std::cout << i << ' ';
    std::cout << '\n';
}