#include <iostream>
#include <vector>

int splitInversions(std::vector<int> &ivec, int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;

    std::vector<int> left(n1), right(n2);

    for(int i = 0; i < n1; ++i)
        left[i] = ivec[i + l];
    
    for(int i = 0; i < n2; ++i)
        right[i] = ivec[i + m + 1];
    
    int i = 0, j = 0, k = l;
    int countInv = 0;

    while(i < n1 && j < n2)
    {
        if(left[i] > right[j])
        {
            ivec[k++] = right[j++];
            countInv += n1 - i;
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

int inversions(std::vector<int> &ivec, int l, int h)
{
    if(l >= h)
        return 0;
    
    int m = (l + h) / 2;
    int x = inversions(ivec, l, m);
    int y = inversions(ivec, m + 1, h);
    int z = splitInversions(ivec, l, m, h);

    return x + y + z;
}

int main()
{
    int n;
    std::cout << "Size: ";
    std::cin >> n;
    std::vector<int> ivec(n);
    std::cout << "Elements: ";

    for(int i = 0; i < n; ++i)
        std::cin >> ivec[i];
    
    std::cout << "Inversions: " << inversions(ivec, 0, n - 1)
              << '\n';
}