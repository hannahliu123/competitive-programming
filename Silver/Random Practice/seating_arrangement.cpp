// C2. Seating Arrangement (Hard Version) - R1500

// this problem felt like a more complicated greedy problem. I feel like there are so many
// different approaches you could possible take that would work in this problem. Intuitively,
// it's easy to notice how if you had no A, you would just greedily place I and E whenever
// possible. But introducing an A, it's optimal to place it as an I if there are no non-empty
// tables or if there are't enough I's in the future to open all tables. Similarly, it's
// optimal to place it as an E if all tables have already been opened. But now it's hard to
// decide what to use A as if there is a possiblility for an I or E. 
// Because trying to greedily place A could get so complicated, I should've leaned towards
// a solution that can efficiently check multiple different possibilities (or some kind of
// more algorithm-based appraoch instead of a pure greedy solution). Here, we can actually
// binary search on a PEAK of how many items A should be introverts. It's optimal to assign
// the earliest occurance of A to be an introvert so that more future E's or A's later can
// occupy an opened table. We know this must be a peak shape because at first, when we assign
// no A's to be introverts, there will be empty unopened tables. Then as we assign more and
// more A's to be introverts, more tables will open and more E's and A's can occupy those
// tables. But then to a certain extent, after too many A's are assigned as introverts, there
// won't be enough tables for the introverts to go, thus just making us lose an extrovert
// who could've sat at a non-empty table

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, T, S;
string s;

int seated(int k) {
    // first k ambiverts are introverts
    int tables=0;   // tables opened
    ll seats=0LL;   // seats available
    int ans = 0;
    for (auto& i : s) {
        if (i=='I') {
            if (tables < T) {
                ans++;
                tables++; seats += (ll)(S-1);
            }
        } else if (i=='E') {
            if (seats > 0) {
                ans++; seats--;
            }
        } else {
            if (k>0) {  // become an introvert
                if (tables < T) {
                    ans++;
                    tables++; seats += (ll)(S-1);
                } k--;
            } else {    // extrovert
                if (seats > 0) {
                    ans++; seats--;
                }
            }
        }
    } return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> N >> T >> S >> s;
        
        int lo=0, hi=0;
        for (auto& i : s) {
            if (i=='A') hi++;
        }
        while (lo < hi) {
            int mid = (lo + hi)/2;
            if (seated(mid) < seated(mid+1)) lo=mid+1;
            else hi=mid;
        }

        cout << seated(lo) << '\n';
    }
}
