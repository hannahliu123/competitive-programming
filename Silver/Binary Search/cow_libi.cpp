// USACO 2023 February Contest, Silver
// Problem 2. Cow-libi

// Start: 10:58
// Break: 11:55 - 12:37
// End: 1:08                Gave up after 1 hr 26 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int G, N;
    cin >> G >> N;

    vector<vector<long long>> grazings(G, vector<long long>(3));
    vector<vector<long long>> cows(N, vector<long long>(3));

    for (int i{0}; i < G; ++i) {    // time, x, y
        cin >> grazings[i][1] >> grazings[i][2] >> grazings[i][0];
    } for (int i{0}; i < N; ++i) {
        cin >> cows[i][1] >> cows[i][2] >> cows[i][0];
    }

    sort(grazings.begin(), grazings.end());

    int innocent{0};
    for (int i{0}; i < N; ++i) {    // for each cow
        long long time{0};
        long long distance{0};
        if (grazings[0][0] >= cows[i][0]) {  // none before, use after/equal
            time = (cows[i][0] - grazings[0][0])*(cows[i][0] - grazings[0][0]);
            distance = (cows[i][1] - grazings[0][1])*(cows[i][1] - grazings[0][1]) + (cows[i][2] - grazings[0][2])*(cows[i][2] - grazings[0][2]);
            if (time < distance) innocent++;
        } else if (grazings[G-1][0] <= cows[i][0]) { // none after, use before/equal
            time = (cows[i][0] - grazings[G-1][0])*(cows[i][0] - grazings[G-1][0]);
            distance = (cows[i][1] - grazings[G-1][1])*(cows[i][1] - grazings[G-1][1]) + (cows[i][2] - grazings[G-1][2])*(cows[i][2] - grazings[G-1][2]);
            if (time < distance) innocent++;
        } else {    // grazings before and after (normal)
            int lo{0}, hi{G};
            while (hi - lo > 1) {
                int mid = (lo + hi) / 2;
                if (grazings[mid][0] >= cows[i][0]) hi = mid;
                else lo = mid;
            }

            time = (cows[i][0] - grazings[hi][0])*(cows[i][0] - grazings[hi][0]);
            distance = (cows[i][1] - grazings[hi][1])*(cows[i][1] - grazings[hi][1]) + (cows[i][2] - grazings[hi][2])*(cows[i][2] - grazings[hi][2]);
            if (time < distance) innocent++;
            else {
                time = (cows[i][0] - grazings[lo][0])*(cows[i][0] - grazings[lo][0]);
                distance = (cows[i][1] - grazings[lo][1])*(cows[i][1] - grazings[lo][1]) + (cows[i][2] - grazings[lo][2])*(cows[i][2] - grazings[lo][2]);
                if (time < distance) innocent++;
            }
        }
    }

    cout << innocent << endl;
}
