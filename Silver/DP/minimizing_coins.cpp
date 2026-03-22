// CSES Problem Set - Minimizing Coins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X; cin >> N >> X;
    vector<int> ans(X+1, 1e9);   // min number of coins
    ans[0] = 0;
    vector<int> c(N);
    for (int i{0}; i < N; ++i) {
        cin >> c[i];
        if (c[i] <= X) ans[c[i]] = 1;
    }

    for (int i{1}; i <= X; i++) {
        for (auto& coin : c) {
            if (i-coin >= 0) ans[i] = min(ans[i], ans[i-coin]+1);
        }
    }

    cout << (ans[X]==1e9? -1 : ans[X]) << endl;
}
