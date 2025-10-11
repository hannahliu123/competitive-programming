// January 2025 Problem 3

// Start: 10:27
// End: 11:27 (gave up on time limits) Technically finished this code at 11:00

// ~

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("checkup.in", "r", stdin);
    //freopen("checkup.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> species(N);     // a
    vector<int> checkup(N);     // b
    for (int i{0}; i < N; ++i) {cin >> species[i];}
    for (int i{0}; i < N; ++i) {cin >> checkup[i];}

    vector<int> ans(N+1);

    for (int l{0}; l < N; ++l) {
        for (int r{l}; r < N; ++r) {
            int totalChecked{0};
            if (l == r) {   // order does not change (no swapping)
                for (int i{0}; i < N; ++i) {
                    if (species[i] == checkup[i]) {
                        ++totalChecked;
                    }
                } ++ans[totalChecked];
            } else {
                vector<int> reversed = species;
                for (int i{0}; i < (r-l+1)/2; ++i) {
                    swap(reversed[l+i], reversed[r-i]);
                } for (int i{0}; i < N; ++i) {
                    if (reversed[i] == checkup[i]) {
                        ++totalChecked;
                    }
                } ++ans[totalChecked];
            } 
        }
    }

    for (auto cow : ans) {
        cout << cow << '\n';
    }
}

// 7, 8, 9, 10, 11, 12, 13 timeout
