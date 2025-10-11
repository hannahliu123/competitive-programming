// USACO 2016 US Open Contest, Silver
// Problem 2. Diamond Collector

// REDO Start: 11:30
// End: 12:05           35 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    
    int N, K;
    cin >> N >> K;
    
    // Build diamonds vector and sort
    vector<int> diamonds(N);
    for (auto& d : diamonds) cin >> d;
    sort(diamonds.begin(), diamonds.end());

    // We need to precompute two vectors. One will keep track of the longest
    // subarray of diamonds that can be stored in one case starting at each
    // index. The other will help us determine the number of diamonds in the
    // second display case. This vector will track the maximum subarray of 
    // diamonds that can be stored in one case after each index (so it could
    // start at that index or after that index). We will use these two vectors
    // to compute the final answer (total diamonds)

    vector<int> start_here(N);  // maximum diamonds starting at each index
    // Use two pointers to calculate each value per index of 'start_here'
    int left{0}, right{0};
    while (left < N) {
        while (right < N & diamonds[right] - diamonds[left] <= K) {
            right++;
        }

        start_here[left] = right-left;
        left++;
    }

    vector<int> max_after(N+1);   // max diamonds starting here/after each index
    max_after[N] = 0;
    for (int i{N-1}; i >= 0; --i) {
        max_after[i] = max(start_here[i], max_after[i+1]);
        // maximum of either diamonds starting from the index i OR
        // the previously calculated maximum diamonds (starting after i)
    }

    // Now that we've created the two vectors, we need to calculate the final
    // answer by looping through each index and testing whether starting at
    // that index will yield a maximum answer. 
    int ans{0};
    for (int i{0}; i < N; ++i) {
        ans = max(ans, start_here[i] + max_after[i + start_here[i]]);
        // maximum of either a previously calculated ans or the ans calculated
        // at the current index (first display case + second display case).
        // This calculated ans is the max diamonds starting at that index (the
        // first display case) plus the max diamonds starting somewhere AFTER 
        // the index of the current index (i) plus the amount of diamonds 
        // already put into the first display case (start_here[i]). When you
        // add those up, you get the amount of diamonds put into both the 
        // first and second display case for each index of i you start from
    }

    cout << ans << endl;
}
