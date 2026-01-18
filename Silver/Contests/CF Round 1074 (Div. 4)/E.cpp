// E

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> a(N);   // N robots
        for (auto& i : a) cin >> i;
        vector<int> b(M);   // M spikes
        for (auto& i : b) cin >> i;
        string s; cin >> s; // instructions of length K

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        map<int, vector<int>> dist; // dist from spike, robot indexes
        for (int i{0}; i < N; ++i) {    // for each robot
            // index of spike after robot i
            int j = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
            if (j>=0 && j<M) dist[b[j]-a[i]].push_back(i);
            j--;    // spike before robot i
            if (j>=0 && j<M) dist[b[j]-a[i]].push_back(i);
        }

        vector<bool> dead(N, false);
        int ans = N;
        int tot_dist = 0;   // cumulative instructions
        for (int i{0}; i < K; ++i) {    // for each instruction
            if (s[i] == 'L') tot_dist--;
            else tot_dist++;

            for (auto& r : dist[tot_dist]) {
                if (!dead[r]) {
                    dead[r] = true;
                    ans--;
                }
            } dist.erase(tot_dist);

            cout << ans << ' ';
        } cout << endl;
    }
}
