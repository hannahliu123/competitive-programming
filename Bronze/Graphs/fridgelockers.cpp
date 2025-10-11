// CF - 1255B - R1100

// Okay this was so simple I thought I got the answer wrong. It's literally just a 
// matter of checking if two inputs are equal wth. The price and stuff doesnt even
// matter. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;   // fridges, chains
        cin >> n >> m;

        vector<int> cost(n);
        for (int i{0}; i < n; ++i) {
            cin >> cost[i];
        }

        if (n == 2 || m < n) {
            cout << -1 << '\n';
        } else {    // m == n
            cout << 2*accumulate(cost.begin(), cost.end(), 0) << '\n';
            for (int i{1}; i <= n; ++i) {
                cout << i << ' ' << (i==n? 1 : i+1) << '\n';
            }
        }
    }
}
