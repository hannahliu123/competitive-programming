// CF - E. Building an Aquarium - R1100

// I deleted the time not bc i looked at the editorial but because
// I spent maybe 35 minutes waiting for the server to grade my solution.
// bruhh it literally took forever omgg but i messed it up twice cos 
// of long longs and also note setting my hi to right value

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        long long X;
        cin >> N >> X;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        int hi = 2000000001;
        int lo = 1;
        while (hi > lo) {
            int h = lo + (hi - lo + 1) / 2;  // round up
            long long x = 0;
            for (int i{0}; i < N; ++i) {
                x += max(0, h - a[i]);
                if (x > X) break;
            }

            if (x > X) {    // used too much water
                hi = h-1;
            } else {    // can use more water (x <= X)
                lo = h;
            }
        }

        cout << lo << endl;
    }
}
