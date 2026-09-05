#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        int four=0, two=0, odd=0;
        for (int i=0; i < N; i++) {
            if (a[i] % 4 == 0) four++;
            else if (a[i] % 2 == 0) two++;
            else odd++;
        }

        cout << max(max(four, two), odd) << '\n';
    }
}