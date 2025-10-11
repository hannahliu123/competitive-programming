// Problem C

// Yeah so the major thing to notice is that f(S) should never change even if you reduce
// g(S) to zero. because you only get rid of one path from each loop, the other paths
// are still present. This was a really clever problem.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        
        vector<pair<pair<int, int>, int>> a(N);
        for (int i{0}; i < N; ++i) {
            cin >> a[i].first.first >> a[i].first.second;
            a[i].second = i+1;
        }

        sort(a.begin(), a.end());
        vector<int> ans{};
        for (int i{0}; i < N; ++i) {
            if (i == N-1 || a[i].first.first != a[i+1].first.first) {
                ans.push_back(a[i].second);
            }
        }

        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (auto i : ans) cout << i << ' ';
        cout << endl;
    }
}
