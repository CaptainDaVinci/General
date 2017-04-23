#include <iostream>
#include <vector>

void merge_sort(std::vector<int> &ivec, int l, int h);
void merge(std::vector<int> &ivec, int l, int m, int h);

int main()
{
    int n;
    std::cout << "Enter the size: ";
    std::cin >> n;
    std::vector<int> ivec(n);
    std::cout << "Enter the elements: ";
    
    for(int i = 0; i < n; ++i)
        std::cin >> ivec[i];
    
    merge_sort(ivec, 0, ivec.size() - 1);

    std::cout << "Sorted array: ";
    
    for(auto const &i : ivec)
        std::cout << i << ' ';
    std::cout << '\n';
}

void merge_sort(std::vector<int> &ivec, int l, int h)
{
    if(l < h)
    {
        int m = l + (h - l) / 2;
        merge_sort(ivec, l, m);
        merge_sort(ivec, m + 1, h);
        merge(ivec, l, m, h);
    }
}

void merge(std::vector<int> &ivec, int l, int m, int h)
{
    std::vector<int> left(m - l + 1), right(h - m);

    for(size_t i = 0; i < left.size(); ++i)
        left[i] = ivec[l + i];
    
    for(size_t i = 0; i < right.size(); ++i)
        right[i] = ivec[i + m + 1];
    
    size_t i = 0, j = 0, k = l;

    while(i < left.size() && j < right.size())
        ivec[k++] = (left[i] < right[j]) ? left[i++] : right[j++];

    while(i < left.size())
        ivec[k++] = left[i++];
    
    while(j < right.size())
        ivec[k++] = right[j++];
}