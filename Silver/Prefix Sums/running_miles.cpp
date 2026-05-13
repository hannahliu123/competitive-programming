// CF - D. Running Miles - R1700

// Start: 7:09
// End: 7:43        34 mins

// I had to read the hints and tags before I got it. I felt stuck at first, but the
// solution is very straightforward. At first I had no idea how prefix sums could have
// anything to do with this bc I was too focused on the basic prefix sums use that I 
// didnt really consider any greedy ideas. I didn't know where to start, so I read the
// hints. Because we need to locate the three maximum values for each range [l,r], it's
// impossible to directly use prefix sums to track those maximum values (doesn't work). 
// You also can't just keep track of all maximums because it changes depending on what
// range you're evaluating. Thus, we use a greedy approach. Any range [l,r] is optimal
// when l and r are the index of two of the three maximums. In between will be another
// maximum. If we iterate over that middle index, we can greedily pick the indexes for
// l and r in O(1) time USING prefix sums where we pick one value to the left of the
// middle index and one to the right such that its contribution is maximized. 

// A better implementation is that because we are maximizing b[m]+b[l]+b[r]-(r-l), we
// know that the values of b[l]+b[r]-(r-l) depend on eachother based on the vector b.
// I calculated the prefixes and suffixes by setting an arbitrary endpoint that would
// allow you to compare the relative contributions of values to the left and right of
// each index. But instead, you can just have the prefix vector store b[l]+l and b[r]-r
// because b[l]+b[r]-(r-l) = b[l]+l + b[r]-r. Now, you only need to maximize those
// two individual terms (because l and r are just constant indexes and don't depend on
// eachother). so now, we can call left (prefix) the maximum contribution to the left
// where each index has b[i]+i and we can call right (suffix) the max contribution to
// the right where each index has b[i]-i. Then we propagate the maximums. This would be
// cleaner and just requires a simple rearranging of the equation

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> b(N);
        for (auto& i : b) cin >> i;

        vector<int> left(N,0);
        vector<int> temp(N,-1);
        for (int i = N-1; i >= 0; i--) {
            temp[i] = b[i]-((N-1)-i);
        } int mx = temp[0];
        for (int i = 2; i < N; i++) {
            left[i] = left[i-1];
            if (temp[i-1] > mx) {
                mx = temp[i-1];
                left[i] = i-1;
            }
        }
        
        vector<int> right(N,N-1);
        for (int i = 0; i < N; i++) {
            temp[i] = b[i]-i;
        } mx = temp[N-1];
        for (int i = N-3; i >= 0; i--) {
            right[i] = right[i+1];
            if (temp[i+1] > mx) {
                mx = temp[i+1];
                right[i] = i+1;
            }
        }
        
        int ans = 0;
        for (int i = 1; i < N-1; i++) { // middle elem
            int l = left[i];
            int r = right[i];
            int x = b[l] + b[i] + b[r] - (r-l);
            ans = max(ans, x);
        }

        cout << ans << endl;
    }
}
