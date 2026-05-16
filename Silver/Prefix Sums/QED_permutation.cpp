// CF - D. QED's Favorite Permutation - R1700

// Start: 8:13
// End: 8:47        34 mins

// YIPPEE IM SO PROUD OF MYSELF!!!!

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, Q;
        cin >> N >> Q;
        vector<int> p(N);
        for (int& i : p) cin >> i;
        vector<char> s(N);
        for (char& i : s) cin >> i;

        vector<bool> pref(N, false);    // true if all numbers from 0->i contained
        int sum = 0, psum = 0;
        for (int i=0; i < N; i++) {
            sum += (i+1);
            psum += p[i];
            if (sum == psum) pref[i] = true;
        }

        set<int> lr{};   // store all L,R pairs that are problems
        for (int i=0; i < N-1; i++) {     
            if (s[i]=='L' && s[i+1]=='R') {
                if (!pref[i]) lr.insert(i);
            }
        }

        while (Q--) {
            int i; cin >> i; i--;
            if (s[i]=='L') {
                if (s[i+1]=='R') lr.erase(i);
                if (s[i-1]=='L' && !pref[i-1]) lr.insert(i-1);
                s[i] = 'R';
            } else {
                if (s[i-1]=='L') lr.erase(i-1);
                if (s[i+1]=='R' && !pref[i]) lr.insert(i);
                s[i] = 'L';
            }

            if (lr.empty()) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
