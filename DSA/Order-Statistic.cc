#include <iostream>
#include <random>
#include <algorithm>

auto constexpr LOW = -100;
auto constexpr HIGH = 100;

inline void swap(int &a, int &b)
{
    int temp = a;
    a = b; 
    b = temp;
}

int partition(std::vector<int> &arr, int l, int h)
{
    int pivot = arr[l];
    int p_index = l;

    for(int i = l + 1; i <= h; ++i)
    {
        if(arr[i] <= pivot)
        {
            ++p_index;
            swap(arr[p_index], arr[i]);
        }
    }
    swap(arr[l], arr[p_index]);

    return p_index;
}

int orderStatistic(std::vector<int> &arr, int l, int h, int target)
{
    if(l >= h)
        return arr[l];
    
    int p_index = partition(arr, l, h);
    if(p_index == target)
        return arr[p_index];
    
    if(p_index > target)
        return orderStatistic(arr, l, p_index - 1, target);
    
    return orderStatistic(arr, p_index + 1, h, target);
}

int main()
{
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<int> dist(LOW, HIGH);

    int size;
    std::cout << "Size: ";    
    std::cin >> size;

    std::vector<int> arr(size);
    for(int i = 0; i < size; ++i)
    {
        int num = dist(engine);
        std::cout << num << ' ';
        arr[i] = num;
    }   
    std::cout << '\n';

    std::uniform_int_distribution<int> targetDist(1, size);
    int target = targetDist(engine);
    std::cout << "Target: " << target << '\n';

    std::cout << target << "th order  statistic: " 
              << orderStatistic(arr, 0, size - 1, target - 1) << '\n';   
    
    std::sort(arr.begin(), arr.end());

    for(const auto &i : arr)
        std::cout << i << ' ';
    std::cout << '\n';
}