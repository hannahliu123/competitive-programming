// USACO 2022 US Open Contest, Silver
// Problem 2. Subset Equality

// Start: 12:39
// Got Working Idea: 1:20
// End: 1:43                            1 hr 10 mins

// yayaay im happy i figured this one out. at first i thought i might need some graph
// representation but then i realize that did nothing. the hardest part was figuring
// out how to solve this efficiently and take advantage of the fact that there's only
// 18 letters. the final solution is just to find all the working pairs and build the
// answer based off that cos there are only 153 possible pairs at max

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t; cin >> s >> t;
    int Q; cin >> Q;

    vector<vector<int>> si(18, vector<int>{});
    vector<vector<int>> ti(18, vector<int>{});
    for (int i=0; i < s.length(); i++) {
        si[s[i]-'a'].push_back(i);
    }
    for (int i=0; i < t.length(); i++) {
        ti[t[i]-'a'].push_back(i);
    }
    string alpha = "abcdefghijklmnopqr";
    vector<vector<bool>> v(18, vector<bool>(18,false));
    for (int i=0; i < 18; i++) {
        if (si[i].size() != ti[i].size()) continue;
        v[i][i]=true;
        char c1 = i+'a';
        for (int j=i; j < 18; j++) {
            if (si[j].size() != ti[j].size()) continue;
            char c2 = j+'a';
            int sidx=0, tidx=0;
            bool same = true;
            while (true) {
                while (sidx<s.size() && s[sidx]!=c1 && s[sidx]!=c2) sidx++;
                while (tidx<t.size() && t[tidx]!=c1 && t[tidx]!=c2) tidx++;
                if (sidx==s.size() || tidx==t.size()) break;
                if (s[sidx] != t[tidx]) {
                    same = false; break;
                } sidx++; tidx++;
            } if (sidx!=s.size() || tidx!=t.size()) same = false;

            if (same) v[i][j] = true;
        }
    }

    while (Q--) {
        string x; cin >> x;
        bool pos = true;
        for (int i=0; i < x.size(); i++) {
            int i1 = x[i]-'a';
            for (int j=i; j < x.size(); j++) {
                int j1 = x[j]-'a';
                if (!v[i1][j1]) {
                    pos = false; break;
                }
            } if (!pos) break;
        }

        cout << (pos? "Y" : "N");
    } cout << '\n';
}