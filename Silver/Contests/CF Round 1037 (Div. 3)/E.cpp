// Problem E

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        vector<int> p(N);
        for (auto& i : p) cin >> i;
        vector<int> s(N);
        for (auto& i : s) cin >> i;

        bool possible = true;
        for (int i{1}; i < N; ++i) {
            if (p[i-1] < p[i]) possible = false;
            if (s[i-1] > s[i]) possible = false;
            if (p[i-1] % p[i] != 0) possible = false;
            if (s[i] % s[i-1] != 0) possible = false;

            if (!possible) break;
        }
    
        for (int i{0}; i < N; ++i) {
            int mn = min(p[i], s[i]), mx = max(p[i], s[i]);
            if (mx % mn != 0) possible = false;
            if (!possible) break;
        }

        cout << (possible? "YES" : "NO") << endl;
    }
}
