// LEARNING DP BASICS!!! CPH 7.1 Coin Problems

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Given a set of coin values coins = {c1, c2,..., ck} and a target sum of money n,
    // our task is to form the sum n using as few coins as possible.
    vector<int> coins{1, 3, 4};
    int n{10};

    // Iterative (Precomputation):
    vector<int> value(n+1, 1000000000);
    value[0] = 0;
    for (int target{1}; target <= n; ++target) {
        for (auto c : coins) {  // try each coin
            // if possible to use that coin (wont be negative) and the sum is lower than the current or previously calculated value (guarentees minimum)
            if (target-c >= 0 && value[target-c]+1 < value[target]) {
                value[target] = value[target-c] + 1;
            }
        }
    }

    for (auto v : value) cout << v << '\n';
}
