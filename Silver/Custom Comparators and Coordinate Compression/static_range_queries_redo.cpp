// CF - D. Static Range Queries

// Resolve because I looked at the solution last time and I was still super confused

// Start: 8:22
// End: 9:40        78 mins heh but mainly cos i had a runtime error which
//                  ended up just being cos I initialized queries with N instead of Q

#include <bits/stdc++.h>
using namespace std;

// We will later do coordinate compression on the 1e9 possible points, so to keep
// track of all the points we need, we will store them in 'indexes'
vector<int> indexes{};

// compresses a normal index into the compressed (smaller) version. This includes
// zero, meaning it returns a 0-indexed version of the compressed index
int comp(int num) {
    return lower_bound(indexes.begin(), indexes.end(), num) - indexes.begin();
}

int main() {
    int N, Q;   // updates, queries
    cin >> N >> Q;

    vector<pair<pair<int, int>, int>> updates(N);  // keep track of updates
    for (int i{0}; i < N; ++i) {
        cin >> updates[i].first.first >> updates[i].first.second >> updates[i].second;
        indexes.push_back(updates[i].first.first);
        indexes.push_back(updates[i].first.second);
        indexes.push_back(updates[i].second);
    }

    vector<pair<int, int>> queries(Q);  // keep track of queries
    for (int i{0}; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        indexes.push_back(queries[i].first);
        indexes.push_back(queries[i].second);
    }

    // Sort & remove duplicates
    sort(indexes.begin(), indexes.end());
    indexes.erase(unique(indexes.begin(), indexes.end()), indexes.end());

    // Now we start to create a difference array using the compressed indexes from 
    // the updates. For each update, increase left by & decrease right by the value
    vector<long long> diff(indexes.size());
    for (int i{0}; i < N; ++i) {
        diff[comp(updates[i].first.first)] += updates[i].second;
        diff[comp(updates[i].first.second)] -= updates[i].second;
    }

    // Distribute the values/complete the difference array
    for (int i{1}; i < indexes.size(); ++i) {
        diff[i] += diff[i-1];
    }

    // Now we need to create the actual prefix array by multiplying the values
    // in the difference array by the length of the interval
    // Length is the current index minus the index before that (indexes is zero-
    // indexed) so it is NOT right - current, it is current - left
    vector<long long> pref(indexes.size(), 0);
    for (int i{1}; i < indexes.size(); ++i) {
        int len = indexes[i] - indexes[i-1];
        long long val = diff[i-1];
        pref[i] = pref[i-1] + len*val;
    }

    // Process each query by subtracting left pref from right pref
    for (int i{0}; i < Q; ++i) {
        int left = comp(queries[i].first);      // 0-indexed
        int right = comp(queries[i].second);
        cout << pref[right] - pref[left] << '\n';
    }
}
