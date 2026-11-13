#include <bits/stdc++.h>
using namespace std;

int main() {
    int M; cin >> M;
    vector<int> v{};
    int x;
    char comma;
    while (cin >> x) {
        v.push_back(x);
        cin >> comma;
    }

    int sum = 0;
    for (int i{0}; i < M; ++i) {
        sum += v[i];
    }

    int l = 0, r = M-1;
    int mn = sum, mx = sum;
    while (r < v.size()-1) {
        sum -= v[l];
        l++; r++;
        sum += v[r];
        mn = min(mn, sum);
        mx = max(mx, sum);
    }

    cout << mn/M << '\n';
    cout << mx/M << '\n';

    return 0;
}
