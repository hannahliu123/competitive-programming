// Problem 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("milkexchange.in", "r", stdin);
    //freopen("milkexchange.out", "w", stdout);

    int N;          // cows
    long long M;    // minutes
    cin >> N >> M;

    int total{0};
    vector<char> direction(N);      // s
    // bool same_direction{true};
    vector<long long> capacities(N);      // a
    for (int i{0}; i < N; ++i) {
        cin >> direction[i];
        // if (i > 0) {
        //     if (direction[i] != direction[i-1]) same_direction = false;
        // }
    }
    for (int i{0}; i < N; ++i) {
        cin >> capacities[i];
        total += capacities[i];
    }

    // if (same_direction) {
    //     cout << total << endl;
    //     return 0;
    // }

    vector<long long> final = capacities;
    vector<long long> realistic = capacities;
    for (int i{0}; i < N; ++i) {
        int milk = min(M, realistic[i]);
        if (direction[i] == 'R') {
            if (i == N-1) {     // end of circle (must loop back once)
                final[i] -= M;
                final[0] += M;
                realistic[i] -= milk;
                realistic[0] += milk;
            } else {
                final[i] -= M;
                final[i+1] += M;
                realistic[i] -= milk;
                realistic[i+1] += milk;
            }
        } else {
            if (i == 0) {
                final[i] -= M;
                final[N-1] += M;
                realistic[i] -= milk;
                realistic[N-1] += milk;
            } else {
                final[i] -= M;
                final[i-1] += M;
                realistic[i] -= milk;
                realistic[i-1] += milk;
            }
        }
    }

    int wasted_realistic{0};
    int wasted{0};
    for (int i{0}; i < N; ++i) {
        if (capacities[i] < final[i]) {
            wasted += final[i] - capacities[i];
    }

    cout << total-wasted << endl;
    }
}
