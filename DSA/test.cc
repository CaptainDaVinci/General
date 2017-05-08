#include <iostream>

using ulld = long long int;

ulld findMax(ulld *a, int n, int sum)
{
    ulld max = 0, j = 0;

    for(int i = 0; i < n; ++i)
    {
        if(a[i] == -1)
            continue;

        if(sum % a[i] >= max)
        {
            max = a[i];
            j = i;
        }
    }

    a[j] = -1;
    return max;
}

ulld maxMod(ulld *a, int n)
{
    ulld max = 0, k = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(a[i] % a[j] >= max)
            {
                max = a[i];
                k = i;
            }
    
    a[k] = -1;
    return max;
}

int main()
{
    int n;
    std::cin >> n;
    ulld a[n], score[n] = { };
    ulld runningSum = 0;

    for(int i = 0; i < n; ++i)
        std::cin >> a[i];
    
    ulld max = maxMod(a, n);
    score[0] = runningSum % max;
    runningSum += max;

    for(int i = 1; i < n; ++i)
    {
        max = findMax(a, n, runningSum);
        score[i] = runningSum % max;
        runningSum += max;
    }

    ulld ans = 0;
    for(int i = 0; i < n; ++i)
        ans += score[i];

    std::cout << ans << '\n';
}