// Level: Easy (CSES)

// Could've done this faster with a set (no repeated numbers)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i{0}; i < n; ++i) {cin >> nums[i];}

    sort(nums.begin(), nums.end());
    int prev{nums[0]};                  // dont really need this variable :/
    int count{1};
    for (int i{1}; i < n; ++i) {
        if (nums[i] != prev) {
            ++count;
            prev = nums[i];
        }
    }

    cout << count;
}
