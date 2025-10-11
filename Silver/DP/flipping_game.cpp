// CF - Flipping Game - R1200

// Start: 8:30
// End: 8:48        18 mins

// I think this is just brute force. Had to do a bit of troubleshooting but figured
// it out. Not much DP

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& A : a) cin >> A;
    
    int original{0};
    for (int i{0}; i < n; ++i) {
        if (a[i] == 1) original++;
    }

    int max_ans{0};
    for (int i{0}; i < n; ++i) {
        int tracker{original};
        for (int j{i}; j < n; ++j) {
            if (a[j] == 1) tracker--;
            else tracker++;     // a[j] == 0
            max_ans = max(max_ans, tracker);
        }
    }

    cout << max_ans << endl;
}
