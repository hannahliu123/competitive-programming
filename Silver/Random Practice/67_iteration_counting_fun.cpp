// G. The 67th Iteration of "Counting is Fun" - R1800

// Start: 1:47
// End: 2:23        36 mins!!!

// YIPEPPEPEPEPE I DID IT! ehehhehe muy happy is me. this was lowkey really really easy
// imo esp for a 1800 problem but hey we take it :)))))

#include <bits/stdc++.h>
using namespace std;

long long MOD = 676767677;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;
        vector<int> b(N);
        vector<vector<int>> times(M);
        for (int i=0; i < N; i++) {
            cin >> b[i];    // time at which i sat down
            times[b[i]].push_back(i);
        }
        vector<int> sat(M, 0);
        for (int i=1; i < M; i++) {
            sat[i] = sat[i-1] + times[i-1].size();
        }

        long long ans = 1;
        for (int time=1; time < M; time++) {
            for (int i : times[time]) {
                int left = (i==0? M : b[i-1]);
                int right = (i==N-1? M : b[i+1]);
                int neighbor = min(left, right);
                if (neighbor >= time) {
                    ans = 0; break;
                } else if (neighbor == time-1) {
                    ans = (ans * sat[time]) % MOD;
                } else {
                    ans = (ans * (sat[time]-sat[time-1])) % MOD;
                }
            } if (ans==0) break;
        }

        cout << ans << '\n';
    }
}