// CF - B. Bakery - R1300

// Start: 11:11
// End: 11:42           31 mins (only took so long cos i got distracted)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;        // cities, roads, flour storages
    cin >> N >> M >> K;

    vector<pair<int, pair<int, int>>> roads{};   // length, city, city
    for (int i{0}; i < M; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        roads.push_back({l, {u, v}});
    }

    sort(roads.begin(), roads.end());       // least -> greatest length
    set<int> flour;   // cities with flour
    for (int i{0}; i < K; ++i) {
        int k;
        cin >> k;
        flour.insert(k);
    }

    int ans = 1000000000;
    bool possible = false;
    for (int i{0}; i < M; ++i) {
        int city1 = roads[i].second.first, city2 = roads[i].second.second;
        if ((flour.find(city1) != flour.end() && flour.find(city2) == flour.end()) || (flour.find(city1) == flour.end() && flour.find(city2) != flour.end())) {
            possible = true;
            ans = roads[i].first;
            break;
        }
    }
    
    cout << (possible? ans : -1) << endl;
}
