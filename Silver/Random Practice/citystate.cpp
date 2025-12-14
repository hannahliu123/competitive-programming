// USACO 2016 December Contest, Silver
// Problem 2. Cities and States

// Start: 11:15
// End: 12:00       45 mins

// I read the problem wrong so i would've gotten this much quicker if i hadnt
// read it wrong. i missed the part where it said that the pairs cannot be from
// the same state. bruh i was tryna debug for so long b4 i reread the question
// sighhhh

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    int N; cin >> N;
    vector<vector<int>> cities(N);
    // 1st & 2nd letter of city then state converted to an int
    for (int i{0}; i < N; ++i) {
        string s1, s2; cin >> s1 >> s2;
        cities[i] = {(int)s1[0]-65, (int)s1[1]-65, (int)s2[0]-65, (int)s2[1]-65};
    } sort(cities.begin(), cities.end());   // l -> g 

    long long ans = 0;
    for (int i{0}; i < N; ++i) {    // for each city
        auto c = cities[i];
        if (c[0] == c[2] && c[1] == c[3]) continue;     // same state
        vector<int> target = {c[2], c[3], c[0], c[1]};
        int index = lower_bound(cities.begin(), cities.end(), target) - cities.begin();
        if (index < 0 || index >= N) continue;
        while (index < N && cities[index++] == target) {
            if (index-1 != i) ans++;
        }
    }

    cout << ans/2 << endl;
}
