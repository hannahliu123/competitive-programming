// LEARNING DP BASICS!!! CPH 7.1 Coin Problems

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Given a set of coin values coins = {c1, c2,..., ck} and a target sum of money n,
    // our task is to form the sum n using as few coins as possible, then print the 
    // value of each of the coins that were used.
    vector<int> coins{1, 3, 4};
    int n{10};

    // Iterative (Precomputation):
    vector<int> value(n+1, 1000000000);
    vector<int> first(n+1);     // tracks the coin used first for each value
    first[0] = 0;
    value[0] = 0;
    for (int target{1}; target <= n; ++target) {
        for (auto c : coins) {  // try each coin
            // if possible to use that coin (wont be negative) and sum is lower
            if (target-c >= 0 && value[target-c]+1 < value[target]) {
                value[target] = value[target-c] + 1;
                first[target] = c;  // keep track of the coin chosen
            }
        }
    }

    //for (auto v : value) cout << v << '\n';

    cout << n << " can be made from " << value[n] << " coins:\n";
    int x{n};   // use this variable to construct our answer
    while (x > 0) {
        cout << first[x] << '\n';
        x -= first[x];
    }
}
