// CF - B. Robot's Task - R1200

// Start: 1:58
// End: 2:09        11 mins!

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (auto & i : a) cin >> i;

    int dir_changes{-1}, collected{0};
    while (collected < N) {
        dir_changes++;
        for (int i{0}; i < N; ++i) {
            if (a[i] <= collected) {
                collected++;
                a[i] = 1001;
            }
        }

        if (collected < N) {    // still less than N
            dir_changes++;
            for (int i{N-1}; i >= 0; --i) {
                if (a[i] <= collected) {
                    collected++;
                    a[i] = 1001;
                }
            }
        }
    }

    cout << dir_changes << endl;
}
