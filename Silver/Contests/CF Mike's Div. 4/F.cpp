#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<pair<int,int>> b{};
        for (int i=1; i <= N; i++) {
            int x; cin >> x;
            b.push_back({x, i});
        } sort(b.begin(), b.end());

        for (int i=0; i < N; i++) {
            // NVMMMMM COME BAKE LATER
        }
    }
}