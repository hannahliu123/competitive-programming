#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        vector<int> v{};
        for (int i=0; i < N; i++) {
            v.push_back(i-a[i]);
        } sort(v.begin(), v.end());

        int ans = 1;
        int chain = 1;
        for (int i=1; i<N; i++) {
            if (v[i]==v[i-1]) continue;
            if (v[i]==v[i-1]+1) {
                chain++;
            } else {
                ans = max(ans, chain);
                chain = 1;
            }
        }

        cout << max(ans, chain) << '\n';
    }
}