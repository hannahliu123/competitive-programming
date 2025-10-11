#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> L{};
    vector<int> G{};
    for (int i{0}; i < N; ++i) {
        char c;
        int x;
        cin >> c >> x;
        if (c == 'L') L.push_back(x);
        else G.push_back(x);
    }

    sort(G.begin(), G.end());
    sort(L.begin(), L.end());

    int ans{N};
    int gsize = G.size(), lsize = L.size();
    for (int l{0}; l < L.size(); ++l) {
        for (int g{0}; g < gsize; ++g) {
            if (L[l] >= G[abs(g-(gsize-1))]) {
                ans = min(ans, l+g);
                break;
            }
        }
    }

    if (ans == N) {
        ans = min(gsize, lsize);
    }

    cout << ans << endl;
}
