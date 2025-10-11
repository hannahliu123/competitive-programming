// Priority Queues Practice
// USACO 2018 December Contest, Silver
// Problem 2. Convention II

// Start: 11:19
// End: 12:01       42 mins

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    int N;
    cin >> N;

    vector<pair<pair<int, int>, int>> cows(N);  // a, t, seniority
    for (int i{0}; i < N; ++i) {
        cin >> cows[i].first.first >> cows[i].first.second;
        cows[i].second = i;
    }
    sort(cows.begin(), cows.end());

    ll max_wait{0}, time{0};
    priority_queue<pair<int, pair<int, int>>> waiting{};    // seniority, a, t
    for (int i{0}; i < N;) {
        int a = cows[i].first.first, t = cows[i].first.second, s = cows[i].second;
        if (a <= time) {   // waiting
            waiting.push({-1*s, {a, t}});
            i++;
        } else {        // no wait
            if (waiting.empty()) {      // what if multiple arrive at same time? doesn't matter ig...?
                time = a + t;
                i++;
            } else {
                ll wait = time - waiting.top().second.first;
                time += waiting.top().second.second;
                max_wait = max(max_wait, wait);
                waiting.pop();
            }
        }
    }

    while (!waiting.empty()) {
        ll wait = time - waiting.top().second.first;
        time += waiting.top().second.second;
        max_wait = max(max_wait, wait);
        waiting.pop();
    }

    cout << max_wait << endl;
}
