// Problem C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, K;
        cin >> N >> K;
        K--;

        vector<long long> h(N);
        for (auto& i : h) cin >> i;

        long long curr_height = h[K];
        long long water = 1;
        sort(h.begin(), h.end());
        
        bool possible = true;
        for (int i{0}; i < N; ++i) {    // can we get to h[i]?
            if (h[i] <= curr_height) continue;
            long long time = h[i] - curr_height;
            water += time;
            if (curr_height+1 < water) {
                possible = false;
                break;
            } else curr_height = h[i];
        }

        cout << (possible? "YES" : "NO") << endl;
    }
}
