// USACO 2021 January Contest, Bronze
// Problem 2. Even More Odd Photos

// Start: 5:00
// End: 5:13

// YAYAYYY!! I kinda just brute forced it. I mean this one was kinda iffy. I
// dont really like my solution, so I'm gonna check what the editorial says.

// Ok so the editorial did a similar thing (counting odds and evens), but the
// way they calculated the answer was different. The made like groupings of two
// odd cows (even) until there were like equal amounts? I feel like my solution
// makes more sense to your brain.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int even{0};
    int odd{0};
    for (int i{0}; i < N; ++i) {
        int ID;
        cin >> ID;
        if (ID%2==0) ++even;
        else ++odd;
    }

    int ans{0};
    for (int i{0}; i < N; ++i) {
        if (i%2==0) {   // even
            if (even>0) {
                --even;
                ++ans;
            } else if (odd>=2) {
                odd -= 2;
                ++ans;
            } else break;
        } else {        // odd
            if (odd>0) {
                --odd;
                ++ans;
            } else break;
        }
    }

    if (odd>0) --ans;

    cout << ans << '\n';
}
