#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        string s; cin >> s;

        vector<int> alph(26,0);
        int i=0, j=N-1;
        while (i<j) {
            if (s[i] != s[j]) {
                int a = s[i]-'a', b = s[j]-'a';
                int mn = min(a,b), mx = max(a,b);
                alph[mn]++; alph[mx]--;
            } i++; j--;
        }

        int ans = (alph[0]>0? 1 : 0);
        for (int k=1; k < 26; k++) {
            alph[k] += alph[k-1];
            if (alph[k]>0) ans++;
        }

        cout << ans << '\n';
    }
}