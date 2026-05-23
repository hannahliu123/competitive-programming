// USACO 2017 February Contest, Silver
// Problem 1. Why Did the Cow Cross the Road

// Start: 10:34
// End: 11:08       34 mins

// at first i implmented a bogus solution where i just sorted cows from l->g by
// end time because i got this confused with another classic greedy scheduling 
// problem. But i realized that was stupid and i figured out the actual answer, 
// which was also surprisingly simple

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);

    int C, N; cin >> C >> N;
    
    vector<int> t(C);
    for (auto& i : t) cin >> i;
    sort(t.begin(), t.end());

    vector<vector<int>> cow(N);   // start, end, i
    vector<vector<int>> bkcow(N);   // end, i
    for (int i=0; i < N; i++) {
        int a, b; cin >> a >> b;
        cow[i] = {a,b,i};
        bkcow[i] = {b,i};
    }
    sort(cow.begin(), cow.end());
    sort(bkcow.begin(), bkcow.end());

    set<int> expired{};     // index of cow
    priority_queue<pair<int,int>> pos{};  // possible cows at time t
    int ans = 0;
    int j=0, bj=0;   // t index, cow index, bkcow index
    for (int i=0; i < C; i++) {
        while (j<N && cow[j][0] <= t[i]) {
            pos.push({-1*cow[j][1],cow[j][2]});    // -end time, i
            j++;
        } while (bj<N && bkcow[bj][0] < t[i]) {
            expired.insert(bkcow[bj][1]);
            bj++;
        } while (!pos.empty()) {
            pair<int,int> p = pos.top();
            pos.pop();
            if (!expired.count(p.second) && -1*p.first >= t[i]) { // valid
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
}
