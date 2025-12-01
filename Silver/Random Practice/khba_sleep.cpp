// E. khba Loves to Sleep! - R1600

// Start: 8:16
// End: 9:58        1hr 42mins but i took a bunch of breaks (bad habit)

// editorial uses binary search which is prolly what i should've done but i 
// will admit i never considered using that. uhh i guess mine logically 
// works but this is why i suck at usaco problems. i always try to solve the
// problem in a sketchy way rather than using an algorithm. that's also why
// it takes me so long (and cos i take too many breaks) oh well

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, K, X; cin >> N >> K >> X;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        sort(a.begin(), a.end());   // l -> g

        priority_queue<vector<int>> opt{};  // dist, position, direction (-1 = left, 0 = both, 1 = right)
        for (int i{0}; i < N; ++i) {
            if (i == N-1) {
                if (i == 0) opt.push({a[0], 0, 1});
                opt.push({X-a[N-1], X, -1});
                break;
            }
            int mid = a[i] + (a[i+1] - a[i]) / 2;   // rounding down
            if ((a[i] + a[i+1]) % 2 == 0) opt.push({mid-a[i], mid, 0});
            else {
                opt.push({mid-a[i], mid, -1});
                opt.push({mid-a[i], mid+1, 1});
            } if (i == 0 && mid != 0) opt.push({a[0], 0, 1});
        }

        int cnt = 0;    // number of positions chosen
        set<int> ans{};
        while (cnt < K) {
            auto curr = opt.top();
            if (ans.find(curr[1]) == ans.end()) {
                ans.insert(curr[1]);
                cnt++;
            } opt.pop();
            if (curr[2] == 0) {
                curr[0]--; curr[1]--; curr[2] = -1;
                opt.push(curr);
                curr[1] += 2; curr[2] = 1;
                opt.push(curr);
            } else if (curr[2] == -1) {
                curr[0]--; curr[1]--;
                opt.push(curr);
            } else if (curr[2] == 1) {
                curr[0]--; curr[1]++;
                opt.push(curr);
            }
        }
        
        for (auto& i : ans) cout << i << ' ';
        cout << endl;
    }
}
