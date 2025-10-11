// CF - B. Party - R1300

// Start: 11:43
// End: 12:27       but i kinda read the editorial....

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, M;   // club members, pairs of friends
        cin >> N >> M;

        vector<int> unhappiness(N);     // unhappiness if member i isn't invited
        for (auto& i : unhappiness) cin >> i;

        vector<pair<int, int>> friends(M);      // all pairs of friends
        vector<int> members(N);                 // # of friends each member has
        for (int i{0}; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            friends[i] = {a, b};
            members[a]++; members[b]++;
        }

        if (M % 2 == 0) cout << 0 << endl;  // already even
        else {
            int ans = 1000000000;
            for (int i{0}; i < N; ++i) {    
                // check if any member has an odd number of friends. If so, simply not inviting
                // them would make the total pairs of friends an even number
                if (members[i] % 2 == 1) ans = min(ans, unhappiness[i]);
            }
            for (int i{0}; i < M; ++i) {    // loop through all pairs of friends
                // check for each pair if both friends have an even number of friends. If so,
                // not inviting both of them would make the total pairs of friends even
                if (members[friends[i].first] % 2 == 0 && members[friends[i].second] % 2 == 0) {
                    ans = min(ans, unhappiness[friends[i].first] + unhappiness[friends[i].second]);
                }
            }

            cout << ans << endl;
        }
    }
}
