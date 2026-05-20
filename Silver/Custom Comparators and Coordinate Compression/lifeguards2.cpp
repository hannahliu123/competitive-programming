// USACO 2018 January Contest, Silver
// Problem 1. Lifeguards

// Start: 2:26
// End: 2:36        10 mins :)

// practicing easier implementation

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int N; cin >> N;

    vector<vector<int>> shifts{};   // time, cow id, start(1) or end(-1)
    for (int i=0; i < N; i++) {
        int l, r; cin >> l >> r;
        shifts.push_back({l, i, 1});
        shifts.push_back({r, i, -1});
    } sort(shifts.begin(), shifts.end());

    set<int> working{};     // all cow ids that are working
    vector<int> alone(N, 0);    // hours each cow spends working alone

    int prevTime = 0;
    int totalTime = 0;
    for (auto& shift : shifts) {
        int currTime = shift[0];
        int cowID = shift[1];

        if (working.size() > 0) {
            totalTime += currTime-prevTime;
        } if (working.size() == 1) {
            alone[*working.begin()] += currTime-prevTime;
        }

        if (shift[2] == 1) {    // started
            working.insert(cowID);
        } else {    // ended
            working.erase(cowID);
        } prevTime = currTime;
    }

    int minAlone = *min_element(alone.begin(), alone.end());
    cout << totalTime - minAlone << endl;
}
