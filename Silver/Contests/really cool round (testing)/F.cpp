// ohhhh this was one of *those* types of problems where you use the given information
// to construct a solution then test if that solution is valid

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> b(N);
        for (auto& i : b) cin >> i;

        vector<int> ans(N+1, 0);
        for (int i=0; i < N; i++) {
            if (b[i] > 0) {
                ans[max(0,i-b[i]+1)]--;
                ans[min(N,i+b[i])]++;
            }
        }
        for (int i=1; i <= N; i++) {
            ans[i] += ans[i-1];
        } 
        vector<int> treasure{-N};
        for (int i=0; i < N; i++) {
            if (ans[i]<0) ans[i] = 0;
            else {
                treasure.push_back(i);
                ans[i] = 1;
            }
        }

        if (treasure.size()==1) {
            cout << -1 << '\n'; continue;
        }

        // test to see if it works
        int li=0, ri=1;
        bool pos = true;
        for (int i=0; i < N; i++) {
            int tl = treasure[li];
            int tr = treasure[ri];
            int x = min(abs(tl-i), abs(tr-i));
            if (b[i]!=-1 && b[i]!=x) {
                pos = false; break;
            }

            if (i==tr) {
                li++;
                ri++;
                if (ri==treasure.size()) ri--;
            }
        }

        if (!pos) cout << -1 << '\n';
        else {
            for (int i=0; i < N; i++) cout << ans[i];
            cout << '\n';
        }
    }
}