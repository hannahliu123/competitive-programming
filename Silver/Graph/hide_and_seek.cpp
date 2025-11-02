// CF - A. Hide and Seek - R1500

// Start: 7:16
// End: 7:56

// bruh this was way simpler than i thought it would be. This was straight
// up a brute force problem oh em gee yeah and my solution is identical
// to the editorial. yip yip hooray ig

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int,int>> min_max(N, {-1,-1});
    for (int i{0}; i < K; ++i) {
        int x;
        cin >> x;
        x--;
        if (min_max[x].first == -1) min_max[x] = {i, i};
        else {
            min_max[x].first = min(min_max[x].first, i);
            min_max[x].second = max(min_max[x].second, i);
        }
    }

    int ans = 0;
    // try {1, 1}
    if (min_max[0].first == -1) ans++;

    // try {i, i} {i-1, 1} and {i, i-1}
    for (int i{1}; i < N; ++i) {
        if (min_max[i].first == -1) ans += 3;  // {i, i}
        else if (min_max[i-1].first == -1) ans += 2; 
        else {
            if (min_max[i].first > min_max[i-1].second) ans++;  // {i, i-1}
            if (min_max[i-1].first > min_max[i].second) ans++;  // {i-1, i}
        }
    }

    cout << ans << endl;
}
