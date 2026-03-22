// CSES Problem Set - Dice Combination

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    vector<int> ans(N+1, 0);
    for (int i{1}; i <= N; i++) {
        if (i <= 6) ans[i]++;
        for (int j{1}; j <= 6; j++) {
            if (i-j > 0) ans[i] += ans[i-j];
            ans[i] %= 1000000007;
        }
    }

    cout << ans[N] << endl;
}
