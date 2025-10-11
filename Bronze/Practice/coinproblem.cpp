// CPH - Dynamic Programming - 7.1 Coin Problem - Recursive Implementation
// No memoization!

#include <bits/stdc++.h>
using namespace std;

vector<int> coins{1, 3, 4};

int solve(int x)
{
    if (x < 0) return 100000000;    // also need this base case if x-c < 0
    if (x == 0) return 0;   // base case
    int minCoins = 1000000000;
    for (int c : coins) {
        minCoins = min(minCoins, solve(x-c)+1);
    } 
    return minCoins;
}

int main()
{
    cout << solve(10) << '\n';
}
