#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, x; cin >> N >> x;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        vector<int> factors{};
        if (x%2==0) {
            factors.push_back(2);
            while (x%2==0) x/=2;
        }
        for (int i=3; i*i<=x; i+=2) {
            if (x%i==0) {
                factors.push_back(i);
                while (x%i==0) x/=i;
            }
        } if (x>1) factors.push_back(x);

        long long answer = 0;
        for (auto& f : factors) {
            long long ans = 0;
            for (int i=0; i < N; i++) {
                if (a[i]%f==0) ans += (long long)a[i];
            } answer = max(answer, ans);
        }

        cout << answer << '\n';
    }
}