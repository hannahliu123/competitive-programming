// Problem 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("mexes.in", "r", stdin);
    //freopen("mexes.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> freq(N+1);
    vector<int> ans(N+1);
    for (int i{0}; i < N; ++i) {cin >> a[i];}

    for (int i{0}; i < N; ++i) {
        freq[a[i]]++;
    }
    
    for (int i{0}; i <= N; ++i) {
        int nums_before{0};
        for (int j{0}; j <= i; ++j) {
            if (j == i) ans[j] = max(nums_before, freq[j]);
            else if (freq[j] == 0) nums_before++;
        }
    }

    for (int num : ans) {
        cout << num << '\n';
    }
}

// timeout 7-11
