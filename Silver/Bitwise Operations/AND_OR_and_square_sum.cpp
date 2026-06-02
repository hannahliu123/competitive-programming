// CF - D. AND, OR and square sum - R1700

// Start: 10:56
// End: 11:13       17 mins

// AHHHHH SO LOCKED IN OMG IM SO HAPPY RIGHT NOWWOOWOWOOOWOWO

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> a(N);
    for (auto& i : a) cin >> i;

    vector<int> ones(20, 0);
    for (int i=0; i < 20; i++) {
        for (int j=0; j < N; j++) {
            if (a[j] & (1<<i)) ones[i]++;
        }
    }

    vector<int> ans(N, 0);
    for (int i=0; i < N; i++) {
        for (int j=0; j < 20; j++) {
            if (ones[j] > 0) {
                ans[i] |= (1<<j);
                ones[j]--;
            }
        }
    }

    long long sum = 0;
    for (auto& i : ans) sum += (long long)i*i;

    cout << sum << endl;
}