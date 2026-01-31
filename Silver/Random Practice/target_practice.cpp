// USACO 2023 December Contest, Silver
// Problem 3. Target Practice

// brute force solution

#include <bits/stdc++.h>
using namespace std;

int T, C;   // targets, commands
set<int> t;

int hit(string& c) {
    int mx = 0;
    set<int> hit{};
    int pos = 0;
    for (int i{0}; i < C; ++i) {
        if (c[i]=='L') pos--;
        else if (c[i]=='R') pos++;
        else if (t.count(pos)) hit.insert(pos);
    } mx = max(mx, (int)hit.size());
    return mx;
}

int main() {
    cin >> T >> C;

    for (int i{0}; i < T; ++i) {
        int x; cin >> x; t.insert(x);
    } string c; cin >> c;

    int ans = 0;
    vector<char> options{'L', 'R', 'F'};
    for (int i{0}; i < C; ++i) {
        int old = c[i];
        for (auto& op : options) {
            c[i] = op;
            ans = max(ans, hit(c));
        } c[i] = old;
    }

    cout << ans << endl;
}
