// D. Signs of Prefix Sums - R1700

// Start: 8:11
// End: 8:59        48 mins

// ugh i lowkey despiseeee my solution and implementation of this problem :( i found
// the greedy solution but it could be further simplified to:
// if s[0] == '0' or there's a "00" within s, output -1
// if there's a "+--+" or "-++-", output 3
// if there's a "+-" or "-+" or even an even # of +/- between two zeroes, output 2
// otherwise, output 1

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        string s; cin >> s;

        bool pos = s[0]!='0';
        for (int i=1; i < N; i++) {
            if (s[i]=='0' && s[i]==s[i-1]) pos = false;
        }

        if (!pos) {
            cout << "-1\n"; continue;
        }

        vector<pair<int,char>> v{{1,'0'}};
        char c = s[0];
        int cnt = 0;
        for (int i=0; i <= N; i++) {
            if (i==N || s[i] != c) {
                v.push_back({cnt,c});
                c = s[i];
                cnt = 1;
            } else if (s[i] == c) cnt++;
        }

        int ans = 1;
        for (int i=0; i < (int)v.size()-1; i++) {
            if ((v[i].second=='+' || v[i].second=='-') && (v[i+1].second=='+' || v[i+1].second=='-')) ans = max(ans, 2);
            if (i < (int)v.size()-2 && v[i].second == v[i+2].second) {
                if (v[i].second=='0') {
                    if (v[i+1].first % 2 == 0) ans = max(ans, 2);
                } else if (v[i+1].second != '0') {
                    if (v[i+1].first == 2) ans = max(ans, 3);
                }
            }
        }

        cout << ans << '\n';
    }
}
