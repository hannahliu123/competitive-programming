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
            bool seen1=false;
            int ans = INT_MAX;
            for (int i=0; i <= N; i++) {
                ans = min(ans, pref[i]+suff[i]);
            } cout << ans << '\n';
        }
    }
}