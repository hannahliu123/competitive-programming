#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a(N);
    for (auto& i : a) cin >> i;
    vector<int> b(M);
    for (auto& i : b) cin >> i;

    for (int i{0}; i < M; ++i) {
        auto it = find(a.begin(), a.end(), b[i]);
        if (it != a.end()) a.erase(it);
    }

    for (auto i : a) cout << i << ' ';
    cout << endl;
}
