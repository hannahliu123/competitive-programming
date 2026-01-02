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

int main() {
    freopen("sabotage.in", "r", stdin);
    freopen("sabotage.out", "w", stdout);

    int N; cin >> N;
    vector<int> m(N);
    for (auto& i : m) cin >> i;

    vector<float> forward(N,-1);    // forward averages
    vector<float> backward(N,-1);   // backward averages
    int sum = 0;
    for (int i{1}; i < N-1; ++i) {
        sum += m[i];
        forward[i] = (float)sum/i;
    } sum = 0;
    for (int i{N-2}; i >= 1; --i) {
        sum += m[i];
        backward[i] = (float)sum/(N-i-1);
    }

    double average = (sum+m[0]+m[N-1])/N;
    sum = m[0]+m[N-1];
    int nums = 2;
    for (int i{0}; i < N; ++i) {
        ;
    }

    double ans = (double)sum/nums;
    cout << fixed << setprecision(3) << ans << endl;
}
