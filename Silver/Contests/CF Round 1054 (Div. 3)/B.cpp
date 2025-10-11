// Problem B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int N;
        cin >> N;   // even

        vector<int> a(N);
        for (auto& i : a) cin >> i;
        sort(a.begin(), a.end());   // least -> greatest

        int ans = 0;
        for (int i{0}; i < N; i += 2) {
            int x = a[i], y = a[i+1];
            ans = max(ans, abs(x-y));
        }

        cout << ans << endl;
    }
}
