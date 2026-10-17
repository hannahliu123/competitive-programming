#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<string> v(N);
    for (int i=0; i < N; i++) {
        cin >> v[i];
    }

    vector<int> ans(N, 0);
    for (int i=0; i < M; i++) {
        string s; cin >> s;
        int one_away = 0, idx = -1;
        for (int j=0; j < N; j++) {
            if (v[j] == s) {
                ans[j]++; one_away = -1; break;
            }
            if (v[j].size() != s.size()) continue;
            int diff = 0;
            for (int k=0; k < (int)v[j].size(); k++) {
                if (v[j][k] != s[k]) diff++;
                if (diff > 1) break;
            } if (diff==1) {
                one_away++; idx = j;
                if (one_away > 1) break;
            }
        }
        if (one_away==1) ans[idx]++;
    }

    for (auto& i : ans) cout << i << '\n';
}