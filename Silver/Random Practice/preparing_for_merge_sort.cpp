// B. Preparing for Merge Sort - R1600

// Start: 9:20
// End: 9:39        19 mins teheh

// wowsers this was so easy but also cos it was from 9 yrs ago. i think i need to just
// solve more recent problems and also problems from the actual usaco website and not
// just codeforces

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> a(N);
    for (auto& i : a) cin >> i;

    vector<vector<int>> ans{};
    for (int i=0; i < N; i++) { // place down a[i]
        if (ans.empty() || ans.back().back() >= a[i]) {
            ans.push_back({a[i]});
            continue;
        }

        int lo=0, hi=ans.size()-1;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            int back = ans[mid].back();
            if (back < a[i]) hi = mid;
            else lo = mid+1;
        }
        ans[lo].push_back(a[i]);
    }

    for (auto& v : ans) {
        for (auto& i : v) cout << i << ' ';
        cout << '\n';
    }
}