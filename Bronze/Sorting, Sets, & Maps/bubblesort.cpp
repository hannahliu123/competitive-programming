#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i{0}; i < N; ++i) {cin >> nums[i];}

    int count{0}; 
    for (int i{N-1}; i >= 0; --i) {
        for (int j{0}; j < i; ++j) {
            if (nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
                count++;
            }
        }
    }

    cout << "Array is sorted in " << count << " swaps." << '\n';
    cout << "First Element: " << nums[0] << '\n';
    cout << "Last Element: " << nums[N-1] << '\n';
}
