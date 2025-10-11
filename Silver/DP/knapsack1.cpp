// Atcoder Educational DP Contest - D - Knapsack 1 

#include <bits/stdc++.h>
using namespace std;

int N, W;
vector<pair<int, int>> items{};
// map<pair<int, int>, long long> memo{};    // This memoization is too slow
vector<vector<long long>> memo{};   // memo[pos][weight] = mx_value

long long dp(int pos, int weight) {
    if (pos >= N) return 0;
    // if (weight+items[pos].first > W) return dp(pos+1, weight);
    // The above should NOT be a base case! If it were, that means once the code reaches
    // one item that surpasses the weight limit, the entire code breaks (returns 0) and
    // other elements aren't even considered!!! Instead, use an if-statement

    if (memo[pos][weight] != -1) return memo[pos][weight];

    long long mx_val = dp(pos+1, weight);       // Default (if item is skipped)
    if (weight+items[pos].first <= W) {     // If the item fits, try adding it
        mx_val = max(mx_val, dp(pos+1, weight+items[pos].first)+items[pos].second);
    }
    
    memo[pos][weight] = mx_val;
    return mx_val;
}

int main() {
    cin >> N >> W;
    items.resize(N);
    memo.resize(N, vector<long long>(W+1, -1));     // less than N but up to W

    for (int i{0}; i < N; ++i) cin >> items[i].first >> items[i].second;

    cout << dp(0, 0) << endl; 
}
