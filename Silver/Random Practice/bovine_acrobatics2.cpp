// USACO 2023 December Contest, Silver
// Problem 1. Bovine Acrobatics

// second implementation

// gosh dang it this annoys me cos of how simple the solution actually was
// bro i didn't even need to use custom comparators and im usually really
// good at greedy problems. idk why i just didn't see this because its just
// that simple. ig i overthought because i assumed that these problems would
// all be really hard. i think im gonna genuinely start picking random problems
// even if i end up picking a surprisingly easy or hard one. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;    // distinct weights, towers, K
    cin >> N >> M >> K;

    vector<pair<int,int>> weights(N);   // weight, freq
    for (auto& p : weights) {
        cin >> p.first >> p.second;
    }
    sort(weights.rbegin(), weights.rend());     // g -> l

    deque<pair<int,int>> towers{{2e9, M}};  // weight, freq
    long long ans = 0;
    for (int i{0}; i < N; ++i) {    // for each group of weights
        int cnt = 0;
        // use up as much of weights[i] as possible
        while (!towers.empty() && weights[i].second > 0 && towers.front().first >= weights[i].first+K) {
            int use = min(towers.front().second, weights[i].second);
            towers.front().second -= use;
            weights[i].second -= use;
            cnt += use;
            if (towers.front().second == 0) towers.pop_front();
        }
        towers.push_back({weights[i].first, cnt});
        ans += cnt;
    }

    cout << ans << endl;
}
