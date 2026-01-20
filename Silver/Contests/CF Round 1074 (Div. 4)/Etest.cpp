// E (my first code)
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        vector<int> b(M);
        for (auto& i : b) cin >> i;
        string s;
        cin >> s;
 
        map<int, vector<int>> dist;
        sort(b.begin(), b.end());
        for (int i{0}; i < N; ++i) {    // for each robot
            int j = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
            if (j>=0 && j<M) dist[b[j]-a[i]].push_back(i);
            j--;
            if (j>=0 && j<M) dist[b[j]-a[i]].push_back(i);
        }
 
        vector<bool> dead(N, false);
        int ans = N;
        int tot_dist = 0;
        for (int i{0}; i < K; ++i) {
            if (s[i] == 'L') tot_dist--;
            else tot_dist++;
 
            for (auto& r : dist[tot_dist]) {
                if (!dead[r]) {
                    dead[r] = true;
                    ans--;
                }
            }
 
            cout << ans << ' ';
        } cout << endl;
    }
}
