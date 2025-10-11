// CF - C. Ball in Berland - R1400

// Start: 9:26
// End: 10:18       52 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int boys, girls;
        long long k;
        cin >> boys >> girls >> k;

        vector<int> b(k);
        for (auto& boy : b) cin >> boy;
        vector<int> g(k);
        for (auto& girl : g) cin >> girl;

        vector<vector<int>> bcouples(boys);
        vector<vector<int>> gcouples(girls);
        for (int i{0}; i < k; ++i) {
            b[i]--; g[i]--;
            bcouples[b[i]].push_back(g[i]);
            gcouples[g[i]].push_back(b[i]);
        }

        long long ans = k*(k/2);
        if (k % 2 == 0) ans -= k/2;

        for (int i{0}; i < boys; ++i) {
            if (bcouples[i].size() > 1) {
                long long edges = bcouples[i].size();
                long long sub = edges*(edges/2);
                if (edges % 2 == 0) sub -= (edges/2);
                ans -= sub;
            }
        }

        for (int i{0}; i < girls; ++i) {
            if (gcouples[i].size() > 1) {
                long long edges = gcouples[i].size();
                long long sub = edges*(edges/2);
                if (edges % 2 == 0) sub -= (edges/2);
                ans -= sub;
            }
        }

        cout << ans << endl;
    }
}

// WA - 7
