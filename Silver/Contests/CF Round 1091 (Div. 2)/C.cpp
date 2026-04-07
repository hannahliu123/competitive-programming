// C - Grid Covering

// During the contest, I somewhat narrowed this down to a number theory problem
// but the problem was still kinda confusing for me. For starters, an easier way
// to handle wrapping (for 0-indexing) is just (i, j) -> ((i+a)%N, (j+b)%M). This
// gets rid of a bit of confusion. Also because the bounds are so large, we can't
// do anything brute-force related

// From there, you should realize that in order for all rows and columns to be
// visited, gcd(N,a) and gcd(M,b) must equal zero.
// You can visualize this better by looking at i and j seperately. If we only
// evaluated, say moving down by a, we can only visit every row if at each turn 
// we are visiting a new box. After all, if we're only moving down, once we hit a
// box the second time, we will just enter a cycle. Our very last move should be
// the first time we revisit a box, and it should wrap us back to the very first
// row. Now, if we visualized this row as one super long row with no wrapping, we
// must start at row 0 and end at some multiple of N (which would wrap to 0). The
// first multiple of N we end up at is where we start wrapping. To guarentee we
// visit N different boxes before wrapping, we must be able to visit i+a a total 
// of N times before i%N=0. Thus, N*a is the first multiple of N that has a factor
// of a, meaning lcm(N,a)=N*a, which also means N and a are coprime, so gcd(N,a)=1.

// But just because we visit all rows and columns, doesn't mean we visit every row
// of every column (every single box). We already know that to get to this point,
// each row increment has a period of N and each column increment has a period of M
// (in order to visit all rows and columns individually). Now, combining these, we
// will visit +a and +b in pairs (because they need to alternate) until they both
// end up at index 0 at the same time. This will happen for the first time at time 
// T = lcm(N,M), because that's the first time that has both N and M as a factor 
// (so T%N=0 and T%M=0). By time T, we will have visited a maximum of 2*T different
// boxes in the case where during each double turn (T total double turns), we visit
// two unique boxes (one on the way there and one at the final location). No matter
// what, though, we will have visited at least T unique boxes (because there is no
// overlap until we finish this cycle of T double-moves). If all locations at each
// time t from 0 to T-1 is unique, that means the single-moves between them land on
// unique boxes as well (because each double move consists of two of the same single
// moves). Thus, we have a maximum of 2*T unique boxes that we visit (note that there
// will be overlap if the area is less than 2*T). If the number of unique boxes we
// visit is at least the area of Prakul's rooom (or 2*T >= N*M), then Prakul can visit
// all tiles. 

// Notice that the order (right or down first) doesnt matter because we only care about
// the double-jumps (which must come in pairs because they need to alternate)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long N, M, a, b; // down, right
        cin >> N >> M >> a >> b;

        long long T = lcm(N,M);
        if (gcd(N,a)==1 && gcd(M,b)==1 && (2*T)>=(N*M)) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
}
