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
    vector<int> nums_before(N+1);   // nums before w/ value 0
    for (int i{0}; i < N; ++i) {cin >> a[i];}

    for (int i{0}; i < N; ++i) {
        freq[a[i]]++;
    }

    nums_before[0] = 0;
    for (int i{1}; i <= N; ++i) {
        nums_before[i] = nums_before[i-1];
        if (freq[i-1]==0) nums_before[i]++;
    }
    
    for (int i{0}; i <= N; ++i) {
        cout << max(nums_before[i], freq[i]) << '\n';
    }
}
