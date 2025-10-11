// Problem E (didn't solve in contest)

// I was so close yet so far. I knew i needed coordinate compression as well as two pointers
// but i couldn't figure out what to do with the length constraint combined with the max
// k distinct values. I couldn't connect the dots. also bc i didn't connect the dots i didnt
// even bother with implementation, which is a whole other story. ok so heres the solution

// The editorial solves this by moving the left boundary. Say the left boundary right now is 
// i. For EACH left boundary, you want to keep track of the earliest right index such that the
// subarray starting from i contains exactly K distinct numbers. So if there are no valid 
// indexes from i where there are K distinct numbers, treat it as unvalid. You also need to
// keep track of the earliest right index such that the subarray starting from i contains
// more than K distinct nums (so starting from i, the interval [x, y-1] contains exactly K
// distinct numbers). You can find these two values with two pointers.
// Now that we satisfied the distict numbers constraint, we need to take care of the length.
// We know the total length from i to any value from x to y-1 must have a length of at least
// L and at most R. So, we can reset the x and y-1 values to a new value depending on the 
// length constraints. For the x value, it must be max(x, i+L-1) if the x value was too small.
// For y, it must be min(y, i+R-1) if the y value was too large. 
// After this, we would have our final range of all possible right values starting from i, 
// which would be [max(x, i+L-1), min(y, i+R-1)]. Therefore, the total possible subarrays
// starting from i would be the y val - x val + 1, which is (min(y, i+R-1) - max(x, i+L-1)) + 1.
// Be careful though because that value might be negative if there are no valid x or y values
// and (i+L-1) exceeds y (which might just be the index at the end of the vector). So, you're
// gonna want to take the maximum of that and 0

// Calculate that for every single left index (i) then add them all together. Now you need to
// implement coordinate compression by using lower_bound and replacing values with their 
// respective sorted index (i explained it more in the google doc)

// FINAL IMPLEMENTATION
// 1. Coordinate compression
// 2. Loop through all i values (leftmost values) and for each i:
//      - Create two separate frequency arrays (one for x and one for y)
//      - Keep track of the number of distinct values for x and for y
//      - Advance the x pointer (earliest index with K distinct values)
//      - Advance the y pointer (earliest index with over K distinct values)
//      - Add max(0, min(y, i+R-1) - max(x, i+L-1) + 1) to the answer

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int N, K, L, R;
        cin >> N >> K >> L >> R;

        vector<int> a(N);
        for (auto& i : a) cin >> i;

        // Coordinate compression
        vector<int> comp = a;
        sort(comp.begin(), comp.end());
        for (int i{0}; i < N; ++i) {    // set each a[i] to its index after sorting
            a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
        }

        vector<int> seen_x(N, 0), seen_y(N, 0); // frequency arrays
        int distinct_x = 0, distinct_y = 0; // keep track of the number of distinct values for x and for y
        int x = -1, y = -1; // pointers tracking index of interval of right values
        long long ans = 0;
        for (int i{0}; i < N; ++i) {
            // Advance the x pointer (earliest index with K distinct values)
            while (x < N-1 && distinct_x < K) { // stop if distinct_x == K or x = N-1
                x++;
                if (seen_x[a[x]] == 0) distinct_x++;
                seen_x[a[x]]++;
            }
            // Advance the y pointer (earliest index with over K distinct values)
            while (y < N && distinct_y <= K) {  // stop if distinct_y > K or y = N
                y++;
                if (y < N && seen_y[a[y]] == 0) distinct_y++;
                if (y < N) seen_y[a[y]]++;
            }

            if (distinct_x == K) ans += max(0, min(y-1, i+R-1) - max(x, i+L-1) + 1);

            // adjust for next iteration (i++)
            seen_x[a[i]]--; seen_y[a[i]]--;
            if (seen_x[a[i]] == 0) distinct_x--;
            if (seen_y[a[i]] == 0) distinct_y--;
        }

        cout << ans << endl;
    }
}
