#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> s(5);
    for (auto& i : s) cin >> i;
    int mx = 0;
    vector<int> ans(11);
    for (int i=0; i < 5; i++) {
        for (int j=0; j < 5; j++) {
            if (s[i][j] == 'o') {
                ans[i]++;
                ans[5+j]++;
                if (i==j) ans[10]++;
                mx = max(mx, max(ans[i], ans[5+j]));
            }
        }
    } mx = max(mx, ans[10]);

    cout << 5-mx << '\n';
}