// USACO 2021 January Contest, Silver
// Problem 2. No Time to Paint

// Start: 7:45
// End: 8:20        35 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    string s; cin >> s;
    vector<int> a(N);
    for (int i=0; i < N; i++) a[i] = s[i]-'A';

    vector<int> pref(N+1, 0);
    vector<int> pos(26, -1);
    for (int i=0; i < N; i++) {
        pref[i+1] = pref[i];
        int prevpos = pos[a[i]];
        bool neednew = false;
        for (int j=0; j < a[i]; j++) {
            if (pos[j] > prevpos) {
                neednew = true; break;
            }
        }
        if (prevpos==-1 || neednew) pref[i+1]++;
        pos[a[i]] = i;
    }
    
    vector<int> suff(N+1, 0);
    pos.clear(); pos.resize(26, N);
    for (int i=N-1; i >= 0; i--) {
        suff[i] = suff[i+1];
        int prevpos = pos[a[i]];
        bool neednew = false;
        for (int j=0; j < a[i]; j++) {
            if (pos[j] < prevpos) {
                neednew = true; break;
            }
        }
        if (prevpos==N || neednew) suff[i]++;
        pos[a[i]] = i;
    }

    while (Q--) {
        int a, b; cin >> a >> b;
        cout << pref[a-1] + suff[b] << '\n';
    }
}