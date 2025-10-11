// USACO 2016 December Contest, Silver
// Problem 1. Counting Haybales

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());

    while (Q--) {
        int A, B;       // inclusive
        cin >> A >> B;

        cout << upper_bound(a.begin(), a.end(), B) -
                lower_bound(a.begin(), a.end(), A) << '\n';
    } return 0;
}
