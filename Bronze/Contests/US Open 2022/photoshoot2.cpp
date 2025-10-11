// Upsolving cos i gave up :D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;
    
    vector<char> pairs{};
    for (int i{0}; i < N-1; i += 2) {
        if (s[i] == s[i+1]) pairs.push_back('.');
        else if (s[i] == 'G') pairs.push_back('A');
        else if (s[i] == 'H') pairs.push_back('B');
    }

    int ans{0};
    while (pairs.size() > 0) {
        int cnt{0};
        int maxcnt{0};
        int index{-1};
        for (int i{0}; i < pairs.size(); ++i) {
            if (pairs[i] == 'A') ++cnt;
            else if (pairs[i] == 'B') --cnt;
            if (cnt > maxcnt) {
                maxcnt = cnt;
                index = i;
            }
        } if (index == -1) break;
        else {  // flip from 0 -> index (both included)
            ++ans;
            vector<char> pairs2{};
            for (int i{index}; i >= 0; --i) {
                pairs2.push_back((pairs[i]=='.'? '.' : (pairs[i]=='A'? 'B' : 'A')));
            }
            pairs = pairs2;
        }
    }

    cout << ans << endl;
}
