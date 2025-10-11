// CF - D. Absolute Sorting - R1400

// Start: 9:10
// Pause: 9:28 - 6:46
// End: 7:35                18+14+35 = 1 hr 7 mins

// Holy i can't belive it worked. I wanted to give up so badly heh and i kinda fell asleep
// for like 10 mins so uhhhh yeah i need to work on locking in when i solve these problems.
// super duper proud rn u dont even understand but lets read the editorial and figure out
// how i couldve solved it quicker or more efficiently. bruh i used desmos lol to solve this

// BAHAHHA NO WAY MY IMPLEMENTATION IS LITERALLY ALMOST IDENTICAL TO THE EDITORIAL OH EM GEE
// IM SO PROUD BAHAHAHHA. I saw one comment said binary serach but NO THANKS BUDDY LET ME
// COOK WITH MY SKETCHY DRAW OUT A BAJILLION TEST CASES STRAT AND LOOK FOR PATTERNS. holy
// moly bro ok so let me explain how i got to this then. I started my comparing side my side
// values, which turned out to be a very good choice because my whole solution revolves
// around that. for each pair, i check which intervals would allow the right value to be 
// greater and i keep track of the lowest value and highest value across all pairs. In this
// way, you get your range of answers, but if the lower value is somehow greater than the 
// higher value, we know it's impossible. This solution is actually VERY logical, just a bit
// tedious to figure out cos of such large ranges of numbers (esp that last test case lol)

// My key insight or lesson kinda i learned from this problem is that if I have a gut feeling
// that my current solution isn't gonna work i should completely scrap it. If it's super
// sketchy and has no logic or proof of success behind it, then take a break and look for
// another solution

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        
        vector<int> v(N);
        for (auto& i : v) cin >> i;

        int lo = 0;
        int hi = 1000000000;
        for (int i{1}; i < N; ++i) {
            int a = v[i-1];
            int b = v[i];
            int curr_lo = 0;
            int curr_hi = 1000000000;
            if (a < b) {
                curr_hi = (a+b)/2;      // round down
            } else if (a > b) {
                curr_lo = (a+b+1)/2;    // round up
            }

            lo = max(lo, curr_lo);
            hi = min(hi, curr_hi);
        }

        if (lo > hi) cout << -1 << endl;
        else cout << lo << endl;
    }
}
