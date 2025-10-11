// USACO 2017 January Contest, Silver
// Problem 1. Cow Dance Show

// Start: 12:44
// End: 1:34        50 mins

#include <bits/stdc++.h>
using namespace std;

int N, T_max;
vector<int> d{};

bool check(int k) {
    // check if having a stage of size k is possible
    vector<int> stage(k, 0);
    int t{0}, i{0};
    while (i <= N) {
        for (int j{0}; j < k; ++j) {
            if (stage[j] == 0 && i < N) {
                stage[j] = d[i++];  // increment i for next iteration
            }
        } 
        
        int mn{*min_element(stage.begin(), stage.end())};
        if (mn == 0) {
            mn = *max_element(stage.begin(), stage.end());
            i++;
        }
        t += mn;
        for (int j{0}; j < k; ++j) {
            stage[j] -= mn;
        } 
    }

    return t <= T_max;
}

int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    
    cin >> N >> T_max;
    d.resize(N);
    for (auto& i : d) cin >> i;

    // binary search for the lowest possible value of K (stage size)
    int lo{1}, hi{N};
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else lo = mid + 1;
    }

    cout << hi << endl;
}
