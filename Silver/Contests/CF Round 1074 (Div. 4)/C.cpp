// C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        sort(a.begin(), a.end());
        int mx_chain = 1;
        int chain = 1;
        for (int i{1}; i < N; ++i) {
            if (a[i] == a[i-1]+1) {
                chain++;
                mx_chain = max(mx_chain, chain);
            } else if (a[i] > a[i-1]+1) {
                chain = 1;
            }
        }

        cout << mx_chain << endl;
    }
}
