// Atcoder Educational DP Contest - B - Frog 2 

// Start: 8:48
// End: 9:13        25 mins

#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> h;
vector<int> cost;    // memoization

int dp(int pos) {
    if (pos == N-1) return 0;
    if (cost[pos] != -1) return cost[pos];

    int mincost{1000000000};
    for (int i{1}; i <= K; ++i) {
        if (pos+i < N) {
            mincost = min(mincost, dp(pos+i)+abs(h[pos+i]-h[pos]));
        }
    }

    cost[pos] = mincost;
    return mincost;
}

int main() {
    cin >> N >> K;

    cost.resize(N, -1);
    h.resize(N);
    for (auto& i : h) cin >> i;

    cout << dp(0) << endl;
}
