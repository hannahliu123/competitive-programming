// A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> a(N);
    for (auto& i : a) cin >> i;

    int cnt = 0;
    for (int i=0; i <= N-3; i++) {
        if (a[i] < a[i+1] && a[i+1] > a[i+2]) cnt++;
    }

    cout << cnt << '\n';
}