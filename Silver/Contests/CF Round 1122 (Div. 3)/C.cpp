// this problem took my like 20 minutes which ig is okay and im not mad about but i
// feel like it's so simple i def could've gotten it quicker. I mean you jsut need to
// greedily realize you can make any number after you've seen a 0 or 1 into a 0 or 1
// of your choice then you can just test every boundary value. then notice how if you
// start with a chain of 0s or 1s you need to keep it but the 0s dont actually matter
// because a more optimal solution would've taken place later.

// ig indexing could've been a bit confusing so i'll take 20 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        string s; cin >> s;

        vector<int> pref(N+1,0);
        for (int i=1; i <= N; i++) {
            pref[i] = pref[i-1]+(s[i-1]-'0');
        }
        vector<int> suff(N+1,0);
        for (int i=N-1; i >=0; i--) {
            suff[i] = suff[i+1]+((s[i]-'0')==0? 1 : 0);
        }

        if (s[0]=='1') {
            cout << suff[0] << '\n';
        } else {
            int ans = INT_MAX;
            for (int i=0; i <= N; i++) {
                ans = min(ans, pref[i]+suff[i]);
            } cout << ans << '\n';
        }
    }
}