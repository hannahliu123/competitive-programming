// CF - B. Recollect Numbers - R1700

// Start: 6:39
// End: 7:13        34 mins

// wohoo! at first i tried a greedy solution but then im glad i realized it didn't work
// and so i found another greedy solution lol. um so the tag on codeforces says constructive
// algorithm, which basically always invloves a greedy answer so yat. i feel like i solve
// greedy problems way too much and need to focus on actual algorithmic implementation.
// maybe imma start using tags now

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        if (K<N || K>2*N-1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        int blind = K-N;
        int nxt = 1, sec = 2;
        if (blind-- > 0) {
            cout << nxt << ' ' << sec << ' ';
            nxt = 3; sec = 1;
            while (blind-- > 0) {
                cout << nxt << ' ' << sec << ' ';
                nxt++; sec++;
            }
            for (int i=sec; i < nxt; i++) {
                cout << i << ' ';
            }
        }
        for (int i=nxt; i <= N; i++) {
            cout << i << ' ' << i << ' ';
        } cout << '\n';
    }
}
