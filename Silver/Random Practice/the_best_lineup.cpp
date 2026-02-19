// USACO 2025 February Contest, Silver
// Problem 1. The Best Lineup

// OH YEAH! second try but done at 10:54

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        bool moved = false;
        vector<int> ideal = a;
        sort(ideal.rbegin(), ideal.rend()); // g -> l
        map<int,int> m;
        for (int i{0}; i < N; ++i) {
            m[ideal[i]] = i;
        }
        
        int idx = 0;    // index of ideal
        int nxt = 1;    // index of next ideal (that isn't -1)
        vector<int> b{};
        for (int i{0}; i < N; ++i) {
            if (a[i] != ideal[idx]) {
                if (!moved && ideal[nxt]==a[i]) {
                    // move a cow
                    moved = true;
                    b.push_back(ideal[idx]);
                    idx = nxt; nxt++;
                    while (ideal[nxt] == -1) nxt++;
                    b.push_back(a[i]);
                    idx = nxt; nxt++;
                    while (ideal[nxt] == -1) nxt++;
                } else {
                    // skip a[i]
                    ideal[m[a[i]]--] = -1;
                    while (ideal[nxt] == -1) nxt++;
                }
            } else {
                b.push_back(a[i]);
                idx = nxt; nxt++;
                while (nxt < ideal.size()-1 && ideal[nxt] == -1) nxt++;
            }
        }

        for (int i{0}; i < b.size(); ++i) cout << b[i] << (i<b.size()-1? " " : "");
        cout << endl;
    }
}
