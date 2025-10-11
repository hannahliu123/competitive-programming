// REDO USACO 2025 February Contest, Bronze
// Problem 3. Printing Sequences

// Start: 12:55
// Break: 1:30-1:38
// End: 1:55

// I gave up :(

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        int first = 0;
        bool seennext = false;
        bool rep = false;
        bool done = false;
        vector<int> rep1{};
        vector<int> rep2{};
        for (int i{0}; i < N; ++i) {
            int curr;
            cin >> curr;
            if ((curr == first && seennext) || rep && !done) {
                rep = true;
                rep2.push_back(curr);
                if (rep2.size() == rep1.size() || i == N-1) {
                    if (rep2 == rep1) {
                        rep2 = {};
                    } else {
                        cout << "NO" << '\n';
                        done = true;
                    }
                }
            } else if (!done) {
                rep1.push_back(curr);
            } if (i==0) first = curr;
            if (curr != first) seennext = true;
        }

        if (!done) cout << "YES" << '\n';
    }
}
