// More Cow Photos

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        set<int> pair{};
        vector<int> seen(N);
        int lastnum{-1};
        int lastpair{-1};
        for (int i{0}; i < N; ++i) {    // heights
            int h;
            cin >> h;
            if (seen[h-1]) {
                pair.insert(h);
                if (h > lastpair) lastpair = h;
            }
            else seen[h-1]++;
            if (h > lastnum) lastnum = h;
        }

        int ans = 2*(pair.size());
        if (lastpair == lastnum) --ans;
        else ++ans;

        cout << ans << '\n';
    }
}
