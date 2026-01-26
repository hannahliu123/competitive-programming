// USACO 2026 First Contest, Silver
// Problem 1. Lineup Queries

// k so this time i started by simulating (brute force) the pattern of what the 
// lineup would look like over time. the simulating itself took a while but it's
// definitely worth it. I should've realized very soon that there was no apparent
// pattern except for the diagonal line of number caused by shifting left. there 
// are quite a few basic things to notice. after that, i realized it was desirable
// to always store the time after a certain cow is at index 0. with that, you can
// calculate its position at any time t. But, because there can be so many cows,
// we cannot precompute it. Notice that there are less than 10^5 queries, so in
// each query, we can have a log x algorithm to compute the answer. Now it's
// important to realize that a cow can only move from the front of the line to the
// middle of the line O(logt) times. i could've recognized this when the problem 
// statement mentioned halving. as time (x) increases exponentially, the number 
// of jumps by a cow (y) increases by one. that means the half distance increases 
// every time a cow comes back to position 0. over time, the half distance will 
// get very large and this is a sign of logs.

// knowign this, for each query, i think i can just simulate the cow moving until
// a certain time or simulate a position moving backwards until it reaches that 
// vertical line

#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q; cin >> Q;
    while (Q--) {
        int q; cin >> q;
        if (q==1) {
            long long c, t; cin >> c >> t;

            if (t < 2*c) cout << c << endl;
            else {
                long long currT = 2*c + (c-1);  // pos 0
                while (currT < t) {
                    currT++;
                    currT += currT/2;
                }

                cout << currT-t << endl;
            }
        } else {
            long long x, t; cin >> x >> t;
            
            if (x > t/2) cout << x << endl;
            else {
                t += x; // cow is at pos 0
                while (true) {
                    long long x2 = (t+1)/3;
                    long long t2 = t-x2;
                    if (t2/2 == x2) {   // move cow to pos 0
                        t = t2-1;
                    } else {
                        x = x2;
                        break;
                    }
                }

                cout << x << endl;
            }
        }
    }
}
