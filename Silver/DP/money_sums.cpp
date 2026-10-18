// CSES Problem Set - Money Sums

// the official solution uses dp[i][x] = true if it is possible to make x using the
// first i coins, false otherwise. The answer is all x such that dp[N][x] is true.
// this problem just kinda threw me off cos the dp vector uses bools, not ints

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> x(N);
    int sum = 0;
    for (auto& i : x) {
        cin >> i; sum += i;
    }

    set<int> pos{0};
    for (int i=0; i < N; i++) {
        set<int> add{};
        for (auto& j : pos) {
            add.insert(j+x[i]);
        }
        pos.merge(add);
    }

    cout << pos.size()-1 << '\n';
    for (auto& i : pos) {
        if (i>0) cout << i << ' ';
    } cout << '\n';
}