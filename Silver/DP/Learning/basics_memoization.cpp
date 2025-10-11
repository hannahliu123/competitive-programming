// LEARNING DP BASICS!!! CPH 7.1 Coin Problems

#include <bits/stdc++.h>
using namespace std;

// Given a set of coin values coins = {c1, c2,..., ck} and a target sum of money n,
// our task is to form the sum n using as few coins as possible.
vector<int> coins{1, 3, 4};
int n{10};

// Memoization: top-down
vector<int> value(n+1, 1000000000);     // the computed value
vector<bool> ready(n+1);    // if value has already been computed

int solve(int target) {
    if (target == 0) return 0;  // base case
    if (target < 0) return 1000000000;  // if subtracted too much (impossible), return a very high value
    else {
        if (ready[target]) return value[target];    // already computed
        else {  // not already computed
            ready[target] = true;   // set to computed
            // compute value: see whether using a 1-coin, 3-coin, or 4-coin is lower
            value[target] = min(solve(target-1)+1, min(solve(target-3)+1, solve(target-4)+1));
            return value[target];   // return answer :)
        }
    }
}

// A better way to write my function so I can change the values of my coins:
int resolve(int target) {
    if (target == 0) return 0;      // don't need crowded else statements because return
    if (target < 0) return 1000000000;
    if (ready[target]) return value[target];
    // if nothing was returned: compute the value using a loop. Big brain!
    int best{1000000000};
    for (auto c : coins) {
        best = min(best, resolve(target-c)+1);
    } 
    ready[target] = true;
    value[target] = best;
    return best;
}

int main() {
    // Memoization:
    for (int i{0}; i <= n; ++i) cout << resolve(i) << '\n';
}

