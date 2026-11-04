// USACO 2021 February Contest, Silver
// Problem 2. Year of the Cow

// Start: 7:59
// End: 8:36        37 mins

// wow another easy problem lol this was literally just greedy

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> a(N);
    for (auto& i : a) cin >> i;
    sort(a.rbegin(), a.rend());     // g -> l

    int ans = 0;
    vector<int> saved{};
    int year = 12*((a[0]/12)+1);    // first (required) jump
    for (int i=0; i < N; i++) {
        if (a[i] > year) continue;
        else if (a[i] > year-12) {   // need to wait
            year -= 12;
            ans += 12;
        } else {    // jump
            saved.push_back(year - (12*((a[i]/12)+1)));
            year = 12*((a[i]/12)+1);
            year -= 12;
            ans += 12;
        }
    } if (year > 0) saved.push_back(year);
    sort(saved.rbegin(), saved.rend());

    for (int i=K-1; i < saved.size(); i++) {
        ans += saved[i];
    }

    cout << ans << '\n';
}