// FEB Upsolving

// Start: 1:30
// Break: 1:55 - 3:20?
// End: 3:54

// STRATEGY: Find the minimum and maximum number of excitement levels, then use the
// number of F's on the outside to determine the "jump". To get the minimum and maximum
// levels, split the string into like "chunks". My main issue is just arriving at the
// solution, not implementing it (this time...)

// So i was actually able to find the pattern, but I missed two key insights. First,
// I didn't realize that the answers would all appear in increments of two. Second, I
// didn't didn't think to use minimum and maximum values, then go from there.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string s;       // sent by B or E, or unknown (F)
    cin >> N >> s;

    char prev{'F'};
    int Fcnt{0};
    int startFs{0};
    int tailFs{0};
    int mn{0};
    int mx{0};
    for(int i{0}; i < N; ++i) {
        if (s[i] == 'F') {
            ++Fcnt;
            if (i == N-1) tailFs = Fcnt;
        } else {
            if (prev == 'F') startFs = Fcnt;
            else {
                if (prev == s[i]) { // same - B...B or E...E
                    if (Fcnt % 2 == 0) {
                        mn += 1;
                        mx += Fcnt+1;
                    } else {
                        mx += Fcnt+1;
                    }
                } else {    // different - B...E or E...B
                    if (Fcnt % 2 == 0) {
                        mx += Fcnt;
                    } else {
                        mn += 1;
                        mx += Fcnt;
                    }
                }
            }
            prev = s[i];
            Fcnt = 0;
        }
    }

    mx += (startFs + tailFs);

    vector<int> ans{};
    if (tailFs == N) {
        for (int i{0}; i < N; ++i) ans.push_back(i);
    } else if (startFs + tailFs > 0) {
        for (int i{mn}; i <= mx; ++i) {ans.push_back(i);}
    } else {
        for (int i{mn}; i <= mx; i += 2) {ans.push_back(i);}
    }

    cout << ans.size() << '\n';
    for (int x : ans) cout << x << '\n';
}

// X - 8
