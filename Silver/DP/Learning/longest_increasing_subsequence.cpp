// LIS - CPH 7.2

#include <bits/stdc++.h>
using namespace std;

// Calculate length of longest increasing subsequence (doesn't need to be consecutive)

int main() {
    int N = 8;
    vector<int> array{6, 2, 5, 1, 7, 4, 8, 3};
    vector<int> length(N, 1); // tracks LIS ending at each index
    
    // Iterative Solution
    for (int i{1}; i < N; ++i) {
        for (int j{0}; j < i; ++j) {
            if (array[j] < array[i]) {
                length[i] = max(length[i], length[j]+1);
            }
        }
    }

    int mx{0};
    for (auto len : length) mx = max(mx, len);

    cout << mx << endl;

    // Print subsequence
    vector<int> ans{};
    for (int i{N-1}; i >= 0; --i) {
        if (length[i] == mx) {
            ans.push_back(array[i]);
            mx--;
        } if (mx == 0) break;
    }

    int size = ans.size();
    for (int i{size-1}; i >= 0; --i) cout << ans[i] << ' ';
    cout << endl;
}
