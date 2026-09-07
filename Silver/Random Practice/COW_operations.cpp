// USACO 2022 US Open Contest, Silver
// Problem 3. COW Operations

// Start: 2:43
// Finalized Idea: 3:16
// End: 3:31                    48 mins

// okay so once again i relied on one random tiny little idea to build my entire solution
// and i lowkey don't fuuully understand why it works but im confident that it does heh.
// do i just noticed that if you apply operations just from left to right, you'll always
// end up with the same thing no matter what like if you chose operations here and there.
// so the order in which you chose operations actually doesn't matter; it only depends on
// the original array itself. knowing this, you can just precompute all 4 possible arrays
// and get the answer in O(1) time for each query (technically O(4) lol)

// um so the editorial solution is actually very different

#include <bits/stdc++.h>
using namespace std;

char nxt(char a, char b) {
    if (a==b) return 'X';
    if (a=='X') return b;
    for (auto& c : "COW") {
        if (c!=a && c!=b) return c;
    } return 'x';
}

int main() {
    string s; int Q;
    cin >> s >> Q;
    int N = s.length();
    string cowx = "COWX";

    vector<vector<char>> v(4, vector<char>(N));
    int idx = 0;
    for (auto& c : cowx) { // start with s[i]=c
        v[idx][0] = c;
        for (int i=1; i < N; i++) {
            v[idx][i] = nxt(v[idx][i-1],s[i]);
        } idx++;
    }

    while (Q--) {
        int l, r; cin >> l >> r; l--; r--;
        if (l==r) {
            cout << (s[l]=='C'? "Y" : "N");
            continue;
        }
        
        char ch = nxt(s[l],s[l+1]);
        for (int i=0; i < 4; i++) {
            if (v[i][l+1] == ch) {
                cout << (v[i][r]=='C'? "Y" : "N");
                break;
            }
        }
    } cout << '\n';
}