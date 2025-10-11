// erm I gave up this is too hard :(

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("milkexchange.in", "r", stdin);
    freopen("milkexchange.out", "w", stdout);

    int N;          // cows
    long long M;    // minutes
    cin >> N >> M;

    string direction{};      // s
    vector<long long> capacities(N);      // a
    cin >> direction;
    for (int i{0}; i < N; ++i) {
        cin >> capacities[i];
    }

    long long total = accumulate(capacities.begin(), capacities.end(), 0);  // sums all values in given array

    // Find all "middle" pairs (RL) - towards eachother
}
