// B

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, D; cin >> M >> D;
    string s; cin >> s;

    vector<bool> watched(M, false);
    for (int i=0; i < M; i++) {
        if (s[i]=='G') {
            watched[i]=true;
            for (int j=max(0,i-D); j <= min(M-1,i+D); j++) {
                watched[j] = true;
            }
        }
    }

    int cnt = 0;
    for (auto i : watched) {
        if (!i) cnt++;
    }

    cout << cnt << '\n';
}