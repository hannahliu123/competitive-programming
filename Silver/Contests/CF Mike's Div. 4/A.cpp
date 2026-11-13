#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        vector<int> v(11,0);
        v[a]++; v[b]++; v[c]++;
        bool pos = false;
        for (int i=3; i <= 10; i++) {
            if (v[i]==1 && v[i-1]==1 && v[i-2]==1) {
                pos = true; break;
            }
        }

        cout << (pos? "YES" : "NO") << '\n';
    }
}