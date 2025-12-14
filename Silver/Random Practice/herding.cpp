// USACO 2019 February Contest, Silver
// Problem 1. Sleepy Cow Herding

// Start: 1:02
// End: 1:59        57  mins

// hehe im so proud i finally debugged that. AHAHAHAH THE SOLUTION IS THE SAEMEMEM
// WOOHOOOO WE CELEBRATEEE!!! im in such a good mood rn hehe im so happyyyyyyyyyy

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int N; cin >> N;
    vector<int> c(N);
    for (auto& i : c) cin >> i;
    sort(c.begin(), c.end());

    int cows = 1, l = 0, r = 0; // l & r are indexes
    int mx_cows = 1;
    while (r < N-1) {
        while (r+1 < N && c[r+1]-c[l]+1 <= N) {
            r++; cows++;
            if (N-cows>1 || c[r]-c[l]+1 == N) mx_cows = max(mx_cows, cows);
        } l++; cows--; // no new cows
    }

    cout << N-mx_cows << '\n';
    int left = c[1]-c[0]-1, right = c[N-1]-c[N-2]-1;
    if (left > right) {
        cout << (c[N-2]-c[0]+1) - (N-1) << endl;
    } else cout << (c[N-1]-c[1]+1) - (N-1) << endl;
}
