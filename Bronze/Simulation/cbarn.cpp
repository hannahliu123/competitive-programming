// USACO 2016 February Contest, Bronze
// Problem 2. Circular Barn

// Start: 12:57
// End: 1:10        13 mins!!!

// YIPPEE OMG THIS IS ACTUALLY THE FASTED IVE EVER SOLVED A BRONZE PROBLEM AHHHH
// i kinda didnt plan this one out well tho but uh it worked... during a real
// contest ill spend a lil longer

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> r(n);
    for (int i{0}; i < n; ++i) {cin >> r[i];}

    int mindist{1000000000};
    for (int i{0}; i < n; ++i) {        // index of opening
        int dist{0};
        for (int j{0}; j < n; ++j) {    // go through all rooms, j = dist to get there
            dist += r[(j+i)%n]*j;
        } mindist = min(mindist, dist);
    }

    cout << mindist << endl;
}
