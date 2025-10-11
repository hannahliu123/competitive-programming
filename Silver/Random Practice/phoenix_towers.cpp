// CF - C. Phoenix and Towers - R1400

// Start: 4:19
// End: 5:08        49 mins but i took a nap so uh

// honestly surprised how stright-forward this problem was... oh but it was 4
// years ago okay... I spent a while on the set implementation cos i did
// sorting at first (even tho i knew it prob wouldn't work heh). Uh idk bro
// Im like super out of it recently i literally napped in the middle of this 
// problem after i firgured out the solution but just didn't feel like implementing
// it... maybe i need a break??? or is that like just ne making an excuse???? idk

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, M, X;
        cin >> N >> M >> X;

        vector<pair<int, int>> h(N);
        for (int i{0}; i < N; ++i) {
            int height;
            cin >> height;
            h[i] = {height, i};
        } sort(h.rbegin(), h.rend()); // greatest -> least

        set<pair<int, int>> towers;
        for (int i{0}; i < M; ++i) towers.insert({0, i+1});
        vector<int> ans(N);
        for (int i{0}; i < N; ++i) {
            auto it = towers.begin();
            auto p = *it;
            int curr = p.first;
            curr += h[i].first;

            ans[h[i].second] = p.second;
            towers.insert({curr, p.second});
            towers.erase(it);
        }

        int mn = 1000000000, mx = 0;
        for (auto i : towers) {
            mn = min(mn, i.first);
            mx = max(mx, i.first);
        }

        if (mx-mn > X) cout << "NO\n";
        else {
            cout << "YES\n";
            for (auto i : ans) cout << i << ' ';
            cout << endl;
        }
    }
}
