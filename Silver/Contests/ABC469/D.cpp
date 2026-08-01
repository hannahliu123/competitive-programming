// D

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<pair<int,int>> v(M);
    unordered_set<int> players{};
    for (int i=0; i < M; i++) {
        cin >> v[i].first >> v[i].second;
        players.insert(v[i].first);
        players.insert(v[i].second);
    }

    set<pair<int,int>> ans{};

    vector<int> four{v[0].first,v[1].first,v[0].second,v[1].second};
    for (auto& a : four) {  // try a alone
        int a_cnt=0;
        vector<pair<int,int>> same{};
        for (int i=0; i < M; i++) {
            if (v[i].first==a || v[i].second==a) {
                a_cnt++;
            } else {
                if (same.empty()) {
                    same = {{v[i].first,1},{v[i].second,1}};
                } else {
                    for (int j=0; j < 2; j++) {
                        if (v[i].first==same[j].first || v[i].second==same[j].first) {
                            same[j].second++;
                        }
                    }
                }
            }
        } if (a_cnt < M) {
            int need = M-a_cnt;
            for (int i=0; i < 2; i++) {
                if (same[i].second == need) {
                    ans.insert({min(a,same[i].first), max(a,same[i].first)});
                }
            }
        } else if (a_cnt == M) {
            for (auto& player : players) {
                if (a!=player) ans.insert({min(a,player), max(a,player)});
            }
        }
    }
    vector<pair<int,int>> pos{{v[0].first,v[1].first},{v[0].first,v[1].second},{v[1].first,v[0].second},{v[1].second,v[0].second}};
    for (auto& p : pos) {   // try two together (a pair)
        int a=p.first, b=p.second;
        if (a==b || ans.count({min(a,b), max(a,b)})) continue;
        int a_cnt=0, b_cnt=0;
        bool possible = true;
        for (int i=0; i < M; i++) {
            if (v[i].first==a || v[i].second==a) {
                a_cnt++;
            } else if (v[i].first==b || v[i].second==b) {
                b_cnt++;
            } else {
                possible = false; break;
            }
        } if (possible) {
            ans.insert({min(a,b), max(a,b)});
        }
    }

    cout << ans.size() << '\n';
}