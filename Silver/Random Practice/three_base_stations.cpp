// CF - C. Three Base Stations - R1800

// Start: 4:25
// End: 5:10        45 mins

// I got the right idea so quickly but i messed up the round6 implementation cos of long longs.
// also I did the ans calculation kinda wrong (but i looked at failed test case and figured
// out why heh cos i was on a time crunch) but i fixed it pretty quickly. HOLY SHOOT HOW THE
// HECK IS THIS A R1800 PROBLEM?? LIKE WHAAAAT THIS WAS SO EASY PFFFFT. oop okay 15 yrs ago. 
// hey but still! anyways only real problem i think was the ans impelemntation being wrong
// but i think i could figure it out after analyzing a few test cases (long longs i just
// completely missed tho heh...). i think this problem was easy except for edge cases (not rly
// "edge cases" but like long longs and ans calc). uhm yeah i think a good rule of thumb is
// to always check for long longs and now ik that's an issue with the roundx function when
// checking doubles in binary search. 

#include <bits/stdc++.h>
using namespace std;

long long round6(double d) {return d*1000000LL + 0.5;}

int main() {
    int N; cin >> N;
    vector<int> x(N);
    for (auto& i : x) cin >> i;
    sort(x.begin(), x.end());

    // binary search on d (power)
    double lo = 0, hi = (x[N-1]/6)+1;
    vector<double> ans(3);
    while (round6(lo) != round6(hi)) {
        double d = (lo + hi) / 2;
        
        vector<double> curr(3);
        double end = (double)x[0]+2*d;
        curr[0] = (double)x[0]+d;
        int stations = 1;
        for (auto& i : x) {
            if ((double)i > end) {
                stations++;
                end = (double)i+2*d;
                if (stations == 2) curr[1] = (double)i+d;
                else if (stations == 3) curr[2] = (double)i+d;
            } if (stations > 3) break;
        }

        if (stations > 3) lo = d;
        else {
            hi = d;
            ans = curr;
        }
    }

    cout << fixed << setprecision(6) << lo << '\n';
    for (auto& i : ans) cout << fixed << setprecision(6) << i << ' ';
    cout << endl;
}
