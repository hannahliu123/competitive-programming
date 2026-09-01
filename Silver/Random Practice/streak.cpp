#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;
        vector<int> cnt(26,0);
        for (int i=0 ; i < N; i++) {
            string s; cin >> s;
            cnt[s[0]-'a']++;
        }
        bool pos = true;
        for (int i=0 ; i < M; i++) {
            string s; cin >> s;
            for (auto& c : s) {
                if (cnt[c-'A']==0) {
                    pos = false; break;
                }
            }
        }

        if (pos) cout << "YES\n";
        else cout << "NO\n";
    }
}