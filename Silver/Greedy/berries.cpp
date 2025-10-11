// USACO 2020 January Contest, Silver
// Problem 1. Berry Picking

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);

    int N, K;
    cin >> N >> K;

    vector<int> berries(N);
    for (auto& b : berries) cin >> b;
    auto max_berry = *max_element(berries.begin(), berries.end());

    sort(berries.rbegin(), berries.rend());   // greatest -> least

    // Plan: In the optimal solution, each of Elsie's buckets will contain the same
    // number of berries as in each of Bessie's buckets. Otherwise, Elsie's buckets 
    // will each contain a certain number of berries and Bessie's buckets will contain
    // that number of less berries. We can brute force all the possible berries in
    // each of Elsie's buckets, from 0 to the larges number of berries on a tree, then
    // calculate the number of berries it leaves for Bessie.
    int max_berries{0};
    for (int b{1}; b <= max_berry; ++b) {
        int full_baskets{0};        // number of baskets with b berries
        vector<int> baskets{};      // values of baskets with less than berries
        for (int i{0}; i < N; ++i) {     // loop through all trees
            if (berries[i]/b > 0) {
                int num = berries[i]/b;
                int remainder = berries[i]%b;
                full_baskets += num;
                baskets.push_back(remainder);
            } else {
                baskets.push_back(berries[i]);
            } if (full_baskets >= K) break;
        }

        sort(baskets.rbegin(), baskets.rend());
        if (full_baskets >= K) max_berries = max(max_berries, b*(K/2));
        else if (full_baskets + baskets.size() >= K) {
            if (full_baskets - K/2 > 0) {
                int rem_berries{0};
                for (int i{0}; i < K-full_baskets; ++i) {
                    rem_berries += baskets[i];
                } max_berries = max(max_berries, b*(full_baskets-(K/2))+rem_berries);
            }            
        }
    }
    
    cout << max_berries << endl;
}
