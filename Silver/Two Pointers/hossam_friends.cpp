// CF - B. Hossam and Friends - R1400

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, M;
        cin >> N >> M;      // friends, pairs
        
        vector<int> leftmost_bad(N, N);
        // tracks the leftmost person each friend is not friends with
        for (int i{0}; i < M; ++i) {
            int x, y;
            cin >> x >> y;  // x not friends with y
            x--; y--;
            int mn {min(x, y)}, mx{max(x, y)};
            leftmost_bad[mn] = min(leftmost_bad[mn], mx);
        }

        long long end = N;    // tracks the furthest index possible for each subsegment of good friends accounting for other non-friends along the path (right to left)
        long long ans = 0;
        for (int i{N-1}; i >= 0; --i) {
            end = min((long long)leftmost_bad[i], end);    // ending index for a good subsegment starting at i
            ans += end-i;   // because there are end - i possible for value for the ending index when starting at i, add that to the answer
        }

        cout << ans << endl;
    }
}
