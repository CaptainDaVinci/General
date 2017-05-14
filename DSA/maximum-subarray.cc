#include <iostream>
#include <vector>
#include <utility>
#include <random>
#include <climits> 
#include <ctime>

using Tuple = std::pair<std::pair<int, int>, int>;

auto constexpr LOW = -100;
auto constexpr HIGH = 100;

Tuple max(const Tuple &a, const Tuple &b)
{
    return (a.second > b.second) ? a : b;
}

Tuple maxSubArrayCrossing(const std::vector<int> &ivec, const int low, const int mid, const int high)
{
    int sum = 0, maxSumLeft = INT_MIN;
    int maxLeft = mid;

    for (int i = mid; i >= low; --i)
    {
        sum += ivec[i];
        if (sum > maxSumLeft)
        {
            maxSumLeft = sum;
            maxLeft = i;
        }
    }

    sum = 0;
    int maxRight = mid + 1, maxSumRight = INT_MIN;

    for (int i = mid + 1; i <= high; ++i)
    {
        sum += ivec[i];
        if (sum > maxSumRight)
        {
            maxSumRight = sum;
            maxRight = i;
        }
    }

    return std::make_pair(std::make_pair(maxLeft, maxRight), maxSumLeft + maxSumRight);
}

Tuple maxSubArray(const std::vector<int> &ivec, const int low, const int high)
{
    if (low >= high)
        return std::make_pair(std::make_pair(low, high), ivec[low]);

    int mid = (low + high) / 2;
    Tuple left = maxSubArray(ivec, low, mid);
    Tuple right = maxSubArray(ivec, mid + 1, high);
    Tuple cross = maxSubArrayCrossing(ivec, low, mid, high);

    return max(left, max(cross, right));
}

Tuple naiveMaxSubArray(std::vector<int> &ivec)
{
    Tuple a;
    int max = -1000000007;

    for (size_t i = 0; i < ivec.size(); ++i)
    {
        int sum = 0;
        for (size_t j = i; j < ivec.size(); ++j)
        {
            sum += ivec[j];
            if (sum > max)
            {
                max = sum;
                a.first.first = i;
                a.first.second = j;
            }
        }
    }

    a.second = max;

    return a;
}

Tuple maxSubArrayBest(std::vector<int> &ivec)
{
    int max = ivec[0], currMax = ivec[0];
    std::size_t start = 0, end = 0, s = 0;

    for (std::size_t i = 1; i < ivec.size(); ++i)
    {
        currMax += ivec[i];
        if (ivec[i] > currMax)
        {
            s = i;
            currMax = ivec[i];
        }

        if (currMax > max)
        {
            max = currMax;
            start = s;
            end = i;
        }
    }

    return std::make_pair(std::make_pair(start, end), max);
}

int main()
{
    int n;
    std::cout << "Size: ";
    std::cin >> n;
    std::vector<int> ivec(n);

    clock_t start, end;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(LOW, HIGH);

    for (int i = 0; i < n; ++i)
    {
        int num = dist(mt);
        // int num;
        // std::cin >> num;
        ivec[i] = num;
    }

    start = clock();
    Tuple result = maxSubArrayBest(ivec);
    end = clock();
    std::cout << "Time Taken O(n): " << std::fixed
              << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";

    std::cout << "Start: " << result.first.first
              << " End: " << result.first.second
              << "\nMax Sum: " << result.second << "\n\n";

    start = clock();
    result = maxSubArray(ivec, 0, n - 1);
    end = clock();
    std::cout << "Time Taken O(nlgn): " << std::fixed
              << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";

    std::cout << "Start: " << result.first.first
              << " End: " << result.first.second
              << "\nMax Sum: " << result.second << "\n\n";

    start = clock();
    result = naiveMaxSubArray(ivec);
    end = clock();
    std::cout << "Time Taken O(n^2): " << std::fixed
              << static_cast<double>(end - start) / CLOCKS_PER_SEC << "\n";

    std::cout << "Start: " << result.first.first
              << " End: " << result.first.second
              << "\nMax Sum: " << result.second << '\n';
}