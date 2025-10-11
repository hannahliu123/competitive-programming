// CF - C. Another Permutation Problem - R1200

// Start: 1:19
// End: 2:08       49 mins

// Heh i think i found a loophole instead of actually solving it with DP...

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> original(N);
        for (int i{0}; i < N; ++i) original[i] = i+1;

        vector<int> p = original;
        int max_cost{0};
        for (int r{0}; r < N; ++r) {    // reverse from index i
            reverse(p.begin()+r, p.end());
            int cost{0}, max_indiv_cost{0};
            for (int i{0}; i < N; ++i) {        // calculate cost
                cost += p[i]*(i+1);
                max_indiv_cost = max(max_indiv_cost, p[i]*(i+1));
            }

            max_cost = max(max_cost, cost-max_indiv_cost);
            p = original;
        }

        cout << max_cost << '\n';
    }
}
