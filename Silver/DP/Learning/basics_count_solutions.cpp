// LEARNING DP BASICS!!! CPH 7.1 Coin Problems

#include <bits/stdc++.h>
using namespace std;

// Given a set of coin values coins = {c1, c2,..., ck} and a target sum of money n,
// our task is to count the number of ways you can make that achieve that sum.
// For example, if coins = {1,3,4} and x = 5, there are a total of 6 ways:
// 1+1+1+1+1        1+1+3        1+3+1        3+1+1        1+4        4+1

int main() {
    vector<int> coins{1, 3, 4};
    int n{5};

    // Solved Iteratively (precomutation):
    vector<int> value(n+1);     // tracks # of ways to get the index value
    value[0] = 1;       // 1 way to get 0
    for (int i{1}; i <= n; ++i) {
        for (auto c : coins) {  // try each coin
            if (i-c >= 0) value[i] += value[i-c];   // add to not set equal to
        }
    }

    for (int i{0}; i <= n; ++i) cout << value[i] << '\n';
}
