// CSES Problem Set - Coin Combinations I

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X; cin >> N >> X;
    vector<int> ans(X+1, 0);
    vector<int> c(N);
    for (int i{0}; i < N; i++) {
        cin >> c[i];
        if (c[i] <= X) ans[c[i]]++;
    }

    for (int i{1}; i <= X; i++) {
        for (auto& coin : c) {
            if (i-coin > 0) ans[i] += ans[i-coin];
            ans[i] %= 1000000007;
        }
    }

    cout << ans[X] << endl;
}
