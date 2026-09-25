#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        vector<int> cnt(101, 0);
        for (auto& i : a) {
            cin >> i;
            cnt[i]++;
        }

        int i=0;
        while (i < N) {
            for (int j=100; j > 0; j--) {
                if (cnt[j]>0) {
                    cout << j << ' ';
                    cnt[j]--; i++;
                }
            }
        } cout << '\n';
    }
}