#include <iostream>
#include <algorithm>

/*
    O(n2) solution, using dynamic programming.
    Keep track of every sequence ending with i, then pick the maximum
    length among them.
*/
int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int a[n];
    std::cout << "Enter the elements: ";

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int dp[n];
    std::fill(dp, dp + n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            // strictly increasing
            if (a[j] < a[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    std::cout << *std::max_element(dp, dp + n) << '\n';
}
