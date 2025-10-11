// Rushed Attempt 2
// Gave up and brute forced it for partial credit AND IT DIDNT EVEN WORK

// Alright I'm gonna try to simulate the problem for partial credit. This is a day
// after I took the contest. I just want to see if I could do it

// Passed 1-6

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
    vector<long long> capacities(N);      // a
    string directions{};        // s
    cin >> directions;
    for (int i{0}; i < N; ++i) {
        direction[i] = directions[i];
    }
    for (int i{0}; i < N; ++i) {
        cin >> capacities[i];
        total += capacities[i];
    }

    directions.find("RL");
    vector<long long> after = capacities;
    for (int i{0}; i < M; ++i) {
        for (int j{0}; j < N; ++j) {
            if (after[j] > 0) {
                if (direction[j] == 'R') {
                    if (j == N-1) {     // end of circle (must loop back once)
                        after[j]--;
                        after[0]++;
                    } else {
                        after[j]--;
                        after[j+1]++;
                    }
                } else {
                    if (j == 0) {
                        after[j]--;
                        after[N-1]++;
                    } else {
                        after[j]--;
                        after[j-1]++;
                    }
                }
            }
        }
    }

    int wasted{0};
    for (int i{0}; i < N; ++i) {
        if (capacities[i] < after[i]) {
            wasted += (after[i] - capacities[i]);
        }
    }

    cout << total-wasted << endl;
}
