// CF - D. Unfair Game - R1600

// Start: 3:56
// End: 5:09        1 hr 13 mins but i got distracted (prolly 1 hour)

// yayay im so happy i solved this one but it did take quite a bit. WOW I nailed
// the thinking pattern! First i identified that this had to do with bitwise 
// operators then i used combinatorics nCr to get the final solution!

// Holy moly i think this is the most direct ive every implemented a problem omg
// im actually so proud right now. i got the right train of thought and i was able
// to figure out the implementation (partially because ive done this sort of problem
// recently lol). yay!!!

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> nCr(30, vector<int>(30,0));
    for (int i{0}; i < 30; i++) {
        for (int j{0}; j <= i; j++) {
            if (j==0) nCr[i][j] = 1;
            else nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
        }
    }

    int t; cin >> t;
    while (t--) {
        int N, K; // max n, max moves
        cin >> N >> K;

        int d = __builtin_ctz(N);
        int ans = 0;
        if (d+1 > K) ans++;
        for (int i{0}; i < d; ++i) {
            int mn = max(1, K-i+1); // min number of ones if pos i is leftmost on
            for (int j = mn; j <= i+1; j++) {
                ans += nCr[i][j-1];
            }
        }

        cout << ans << endl;
    }
}
