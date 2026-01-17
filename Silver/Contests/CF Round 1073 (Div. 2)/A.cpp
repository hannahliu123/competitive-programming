// A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        bool pos = true;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        for (int i{2}; i < N; ++i) {
            if (a[i]%2 != a[i-2]%2) pos = false;
        }

        if (pos) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
