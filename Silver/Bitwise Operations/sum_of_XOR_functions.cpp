// CF - D. Sum of XOR Functions - R1700

// Start: 9:16
// End: 9:52        36 mins

// okay this problem is VERY similar to XOR sigma and i know i def wouldn't have
// gotten this without solving XOR Sigma first. but i do wanna point out some key
// realizations that could've helped me possibly make those realizations

// for starters i think it should be very common for me to evaluation bitwise problems
// bit by bit. oftentimes it can simplify the time complexity because there might only
// be like 30 bits in total, so you can then loop from 1->n for each of those bit
// positions. a special property of bitwise operations is that they only evaluate each
// bit position individually, so if you do the same you can just calculate the total
// contribution made by each array value at each bit position instead of building all
// subarrays. When u first read the problem, you can realize the the main thing holding
// u back is the time complexity because building all subarrays would require O(N^2).
// if we want to reduce the time comp, the solution is just to evaluate the bit positions
// individually lol idk how else to get there :/ this is kinda different from precomputing
// cos we aren't getting an answer to each array value in O(1) time. instead we get a
// contribution for each bit position (0-29) so its similar but different

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (auto& i : a) cin >> i;

    long long ans = 0;
    for (int i=0; i < 30; i++) {    // for each bit position
        // track if the prefix of bits at position i have an odd number of 1s
        vector<bool> pref(N+1, false);
        for (int j=1; j <= N; j++) {
            pref[j] = pref[j-1];
            if (a[j-1] & (1<<i)) pref[j] = !pref[j];
        }

        int e=0, o=0;   // even, odd
        long long ed=0, od=0;   // even dist, odd dist
        long long sum = 0;  // sum of all distance contributions for bit position i
        for (int j=0; j <= N; j++) {
            // increase distance of all evens and odds we've seen before
            ed += (long long)e; od += (long long)o;
            if (!pref[j]) {  // even
                sum += od;  // pair with odds seen previously
                e++;
            } else {    // odd
                sum += ed;  // pair with evens seen previously
                o++;
            }
        }

        sum %= 998244353LL;
        long long val = (1<<i);
        ans += sum*val;
        ans %= 998244353LL;
    }

    cout << ans << endl;
}