// CF - C. Rudolf and the Another Competition - R1200

// Start: 10:27
// End: 10:52           25 mins!!!

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M, H;
        cin >> N >> M >> H;

        vector<pair<int, ll>> p(N);     // points, penalties
        for (auto& i : p) {
            vector<ll> t(M);
            for (auto& j : t) cin >> j;
            sort(t.begin(), t.end());
            ll sum{0};
            for (int j{0}; j < M; ++j) {
                if (sum + t[j] <= H) {
                    sum += t[j];
                    i.first++;
                    i.second += sum;
                } else break;
            }
        }

        int place{1};
        for (int i{1}; i < N; ++i) {
            if (p[i].first > p[0].first) {  // more points than rudolf
                place++;
            } else if (p[i].first == p[0].first && p[i].second < p[0].second) {
                place++;
            }
        }

        cout << place << '\n';
    }
}
