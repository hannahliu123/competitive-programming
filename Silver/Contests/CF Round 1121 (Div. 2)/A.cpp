#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> p(N);
        for (auto& i : p) cin >> i;

        vector<int> v{};
        for (int i=0; i < N; i++) {
            if (p[i]==i+1) continue;
            v.push_back(i+1);
        } int idx = v.size()-1;
        bool pos = true;
        for (int i=0; i < N; i++) {
            if (p[i]==i+1) continue;
            if (v[idx--] != p[i]) {
                pos = false; break;
            }
        }
        
        cout << (pos? "YES\n" : "NO\n");
    }
}