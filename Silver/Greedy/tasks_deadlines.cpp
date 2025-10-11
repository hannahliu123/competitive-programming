// CSES - Tasks and Deadlines - https://cses.fi/problemset/task/1630

// Start: 11:44
// End: 11:54       10 mins

// But im not actually sure why this greedy solution worked...?

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;      // number of tasks
    cin >> N;

    vector<pair<long long, long long>> d(N);        // duration, deadline
    for (auto& p : d) cin >> p.first >> p.second;

    sort(d.begin(), d.end());   // sort shortest -> longest

    long long time{0};
    long long ans{0};
    for (int i{0}; i < N; ++i) {
        time += d[i].first;
        ans += d[i].second - time;
    }

    cout << ans << endl;
}
