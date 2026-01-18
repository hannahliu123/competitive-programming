// D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, M, H;
        cin >> N >> M >> H;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        vector<int> b(M);
        vector<int> c(M);
        for (int i{0}; i < M; ++i) {
            cin >> b[i] >> c[i]; b[i]--;
        }
        
        int wipe = -1;
        vector<pair<int,int>> a2(N);   // value, last update
        for (int i{0}; i < N; ++i) a2[i] = {a[i],-1};
        for (int i{0}; i < M; ++i) {
            if (wipe>a2[b[i]].second) a2[b[i]].first = a[b[i]]; // wipe
            a2[b[i]].second = i;
            a2[b[i]].first += c[i];
            if (a2[b[i]].first > H) {
                wipe = i;
                a2[b[i]].first = a[b[i]];
            }
        }

        for (int i{0}; i < N; ++i) {
            if (wipe>a2[i].second) a2[i].first = a[i]; // wipe
        }

        for (auto& i : a2) cout << i.first << ' ';
        cout << endl;
    }
}
