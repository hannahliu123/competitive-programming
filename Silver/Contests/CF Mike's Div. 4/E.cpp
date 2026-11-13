#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        vector<int> pref(N);
        pref[0] = 1;
        int sum = 1;
        for (int i=1; i < N; i++) {
            pref[i] = sum;
            sum += pref[i];
            if (i>=K) sum -= pref[i-K];
            sum = (sum+2)%2;
        } for (int i=1; i < N; i++) pref[i] = (pref[i]+pref[i-1])%2;

        int ans = 0;
        for (int i=0; i < N; i++) {
            ans += (a[i]%2)*(pref[i]);
        }

        cout << (ans%2==0? "Bob" : "Alice") << '\n';
    }
}