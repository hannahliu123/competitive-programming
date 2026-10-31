#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, N, Q; cin >> H >> W >> N >> Q;
    map<int,int> mr{};
    map<int,int> mc{};
    for (int i=0; i < N; i++) {
        int r, c; cin >> r >> c;
        r--; c--;
        mr[r]++;
        mc[c]++;
    }
    vector<pair<int,int>> vr{{-1,0}};
    for (auto& p : mr) {
        vr.push_back({p.first, p.second+vr.back().second});
    }
    vector<pair<int,int>> vc{{-1,0}};
    for (auto& p : mc) {
        vc.push_back({p.first, p.second+vc.back().second});
    }

    while (Q--) {
        int type, l, r; cin >> type >> l >> r;
        l--; r--;
        if (type==1) {
            auto rit = upper_bound(vr.begin(), vr.end(), make_pair(r,N+1));
            rit--;
            auto lit = lower_bound(vr.begin(), vr.end(), make_pair(l,0));
            lit--;
            cout << (*rit).second - (*lit).second << '\n';
        } else {
            auto rit = upper_bound(vc.begin(), vc.end(), make_pair(r,N+1));
            rit--;
            auto lit = lower_bound(vc.begin(), vc.end(), make_pair(l,0));
            lit--;
            cout << (*rit).second - (*lit).second << '\n';
        }
    }
}