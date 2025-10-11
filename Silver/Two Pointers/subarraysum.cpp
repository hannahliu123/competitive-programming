// CSES - Subarray Sums I - https://cses.fi/problemset/task/1660

// Start: 8:54
// End: 9:02        8 mins :D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> a(N);
    for (auto& i : a) cin >> i;

    // Subarray Sum Two Pointers (at beginning of array)
    int left{0}, right{0}, ans{0}, sum{0};
    while (left < N) {
        while (right < N && sum + a[right] <= X) {
            sum += a[right++];
        } if (sum == X) ans++;
        sum -= a[left++];
    }

    cout << ans << endl;
}
