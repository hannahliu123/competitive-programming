// CF - D. Static Range Queries

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;   // number of updates & queries (N, Q <= 10^5)
    cin >> N >> Q;

    // We cannot store an array of 10^9 values (as defined in the problem) nor could
    // we loop through each of those values, so we need to use coordinate compression
    // to reduce the size of those values. Because there is a max of 10^5 updates and
    // 10^5 queries, we know that there must be many repeated values throughout the
    // array of values in between indexes with updates/queries. So, by only storing 
    // indexes that receive/end updates/queries, we can save lots so time and space.
    // However, by doing this, we need to keep track of all those indexes. We will
    // store all the required indexes in the vector 'indexes', where each index 
    // corresponds to the real index. So, if the real indexes we needed to remember
    // were {1, 3, 4, 5, 9, 12}, that means 1 has become the index 0, 3 has become 1, 
    // 4 has beceom 2, etc. 
    vector<int> indexes{};

    // store updates so you can update the difference array after all "special"
    // indexes are received and you can use compressed indexes in the difference
    // array (seen later after all inputs are received)
    vector<pair<pair<int, int>, long long>> updates(N);
    for (int i{0}; i < N; ++i) {    // receive all updates
        int l, r, v;
        cin >> l >> r >> v;
        indexes.push_back(l);
        indexes.push_back(r);
        updates[i] = {{l, r}, v};
    }

    vector<pair<int, int>> queries(Q);      // store all queries for later
    for (int i{0}; i < Q; ++i) {
        int l, r;
        cin >> l >> r;
        indexes.push_back(l);
        indexes.push_back(r);
        queries[i] = {l, r};
    }

    // sort and remove duplicates from 'indexes'
    sort(indexes.begin(), indexes.end());
    indexes.erase(unique(indexes.begin(), indexes.end()), indexes.end());
    
    // To process each of the updates after storing them, we need a way to keep
    // track of the value representing each of our intervals (between the "special"
    // indexes). To do this, we can use a difference array to mark where values
    // must be added/subtracted. We must use the compressed indexes
    vector<long long> diff(indexes.size());
    for (int i{0}; i < N; ++i) {                // for each update
        // calculate the new compressed indexes
        int left_index = lower_bound(indexes.begin(), indexes.end(), updates[i].first.first) - indexes.begin();
        int right_index = lower_bound(indexes.begin(), indexes.end(), updates[i].first.second) - indexes.begin();

        // update the differece array
        diff[left_index] += updates[i].second;
        diff[right_index] -= updates[i].second;
    }

    // To calculate our final answer, we need to have a way to get the prefix sum
    // of all elements before each "special" index. This means our 'pref' vector must
    // hold the sum of all "special" intervals before that point. To calculate the 
    // sum of a special interval, we need the value of each index in that interval
    // multiplied by the length of the interval. We can get the length from the
    // values of the set 'indexes'. In order to get the values, however, we need to
    // loop through and update all values of our difference array.
    for (int i{1}; i < indexes.size(); ++i) {
        diff[i] += diff[i-1];               // now stores sum of each interval
    }
    
    // Now we update all values of 'pref' by setting each index to the respective
    // product of the length of the interval times its value in 'diff'. Then add
    // the previous value to each index of 'pref' (bc it's a prefix sum array, after
    // all). It tracks the sum of everything up until that idex, not just the sum
    // of each individual interval
    vector<long long> pref(diff.size());
    for (int i{0}; i < indexes.size()-1; ++i) {
        int len = indexes[i+1]-indexes[i];
        long long val = diff[i];
        pref[i] = (i==0? len*val : len*val + pref[i-1]);
    }

    for (int i{0}; i < Q; ++i) {    // process each query
        int r = lower_bound(indexes.begin(), indexes.end(), queries[i].second)-indexes.begin();
        int l = lower_bound(indexes.begin(), indexes.end(), queries[i].first)-indexes.begin();

        // the answer would be r - l, but we need to convert the old indexing to
        // the condensed verson
        cout << pref[r-1] - (l==0? 0 : pref[l-1]) << '\n';
    }
}
