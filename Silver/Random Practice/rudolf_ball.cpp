// CF - D. Rudolf and the Ball Game - R1200

// Start: 12:56
// End: 1:47        51 mins

// Only took so long because I got distracted cutting my nails lol. Also some issues with
// sets and data type. I didn't know you couldn't edit elements in a set with that for
// each loop :/ womp womp at least ik now :)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M, X;
        cin >> N >> M >> X;

        set<int> players{X};      // all players currently holding the ball
        for (int i{0}; i < M; ++i) {
            int dist;
            char direction;
            cin >> dist >> direction;

            set<int> new_p{};
            for (int j : players) {
                if (direction == '0' || direction == '?') {     // CW
                    int cw = j + dist;
                    if (cw > N) cw -= N;
                    new_p.insert(cw);
                } if (direction == '1' || direction == '?') {      // CCW
                    int ccw = j - dist;
                    if (ccw <= 0) ccw += N;
                    new_p.insert(ccw);
                }
            }

            players = new_p;
        }
        
        cout << players.size() << '\n';
        for (int p : players) cout << p << ' ';
        cout << '\n';
    }
}
