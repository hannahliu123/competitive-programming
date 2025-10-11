// CF - Playing in a Casino - 1080B

// Start: 9:25
// End: 10:58       1 hr 33 mins

// bruh i spent so long figuring out my long long issue :( but hey at least i got it

// So basically what happened was that doing multiplication on line 40 converted
// the product to an integer (because both constants were of type int), and so that
// resulted in integer overflow, meaning long long x was never updated correctly

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> col(M);
        for (int i{0}; i < N; ++i) {
            for (int j{0}; j < M; ++j) {
                int x;
                cin >> x;
                col[j].push_back(x);
            }
        }

        long long ans{0};
        for (int i{0}; i < M; ++i) {
            sort(col[i].begin(), col[i].end());
            vector<long long> diff{};
            long long x{0};
            for (int j{0}; j < N-1; ++j) {
                diff.push_back(abs(col[i][j+1]-col[i][j]));
            } for (int j{1}; j < N; ++j) {
                x += diff[j-1]*j;   // HERE!
            }
            for (int j{N-1}; j > 1; --j) {
                ans += x;
                x = x-(j*diff[j-1]);
            } ans += x;
        }

        cout << ans << '\n';
    }
}

// Wrong test 4
