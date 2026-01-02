// USACO 2014 March Contest, Gold
// Problem 2. Sabotage

// im so lost bro. i need to practice prefix sums more. i peeked at the tags for this 
// problem and how the heck is binary search one of them? i was kinda thinking prefix
// sums but i didn't really know how to implement it. this is actually so confusing and
// i just couldn't connect the dots for this problem. i started making liek a prefix
// and suffix array but didn't know what to do from there because there are so many edge
// cases and idrk how to interpret the final array. 

// OHHHH MY GOD THIS LOWKEY MAKES SO MUCH SENSEEEEE. So this is just binary search and
// Kadane's algorithm and some simple math. im always tryna draw out test cases and 
// what not but i never bother writing out equations. Also i eliminate binary search
// as a possiblity wayy too easily because this is so clearly a monotonic function but
// the only tricky part is figuring out how to determine determine the output of that
// function (like how to tell if it is yes or no). We can binary search directly on the
// answer (minimum average after a subarray of machines are removed). The monotonic 
// function will look like no,no,no...yes,yes,yes because if the answer is too low then
// it's not possible to achieve that low of an average. but if the average is confirmed
// to be able to reach 50 or lower (for example) then it can definitely reach 100 or lower
// because the 50 or lower solution still applies. ive been stuck thinking that binary 
// search can only be done on a specific value, but it can be done under any condition
// as long as a monotonic function applies!!! i thought if i did binary search it would
// have to check if the minimum average after a subarray of machines are removed is 
// exactly that value being tested. obviously that wouldn't work but i never considered
// just seeing is the minimum average after a subarray of machines are removed could be
// less than or equal to that. also writing out the mathematical equation would've helped.

#include <bits/stdc++.h>
using namespace std;

int round3(double x) {
    return (int)(x*1000 + 0.5); // add 0.5 so it rounds up when it needs to
}

int main() {
    freopen("sabotage.in", "r", stdin);
    freopen("sabotage.out", "w", stdout);

    int N; cin >> N;
    vector<int> m(N);
    for (auto& i : m) cin >> i;

    // binary search on the answer
    int S = accumulate(m.begin(), m.end(), 0);
    double hi = 1e4*N, lo = 1.0;
    while (round3(hi) != round3(lo)) {
        // check if it's possible to end with an average less than or equal to mid:
        // (S-sum(i,j))/(N-K) <= mid    -->     S-mid*N <= sum(i,j)-mid*K
        // S = sum of all values in m
        // sum(i,j) = sum of values in extracted subarray
        // K = number of values in extracted subarray
        double mid = (hi+lo)/2;
        // find the maximum sum subarray sum(i,j) using values in m except each value
        // gets subtracted by mid when calculating the sum. Use Kadane's Algorithm.
        double mx = m[1]-mid;    // mx is sum(i,j)-mid*K
        double mxEnd = mx;
        for (int i{2}; i < N-1; ++i) {
            double curr = m[i] - mid;
            mxEnd = max(mxEnd+curr, curr);
            mx = max(mx, mxEnd);
        }

        if (S-mid*N <= mx) hi = mid;    // valid (mid works as an answer)
        else lo = mid;
    }

    cout << fixed << setprecision(3) << lo << endl;
}
