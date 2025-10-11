// CF - Assembly via Minimums - 1857C - R1200

// Start: 4:10
// End: 5:14        1 hr 4 mins

// yippeeeee i was able to figure out my problem pretty quickly :D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;

        vector<int> b((N*(N-1))/2);
        for (int i{0}; i < (N*(N-1))/2; ++i) cin >> b[i];
        
        sort(b.begin(), b.end());
        vector<pair<int, int>> freq{};
        int cnt{1};
        for (int i{1}; i < b.size(); ++i) {
            if (b[i] == b[i-1]) ++cnt;
            else {
                freq.push_back({b[i-1], cnt});
                cnt = 1;
            }
        } freq.push_back({b[b.size()-1], cnt});

        vector<int> a{};
        int aindex{0};
        for (auto p : freq) {
            int x{0};
            while (x < p.second) {
                a.push_back(p.first);
                ++aindex;
                x += N-aindex;
            }
        }

        if (a.size() < N) {
            for (int i{0}; i < N-a.size(); ++i) {
                if (N-a.size() == 1) a.push_back(b[b.size()-1]);
                else a.push_back(b[b.size()-1]+1);
            }
        }

        for (int i : a) {
            cout << i << ' ';
        } cout << '\n';
    }
}

// Wrong answer test 7
