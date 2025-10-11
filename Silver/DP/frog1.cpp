// Atcoder - A - Frog 1 

// Start: 10:35
// End: 10:48       13 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> h(N+1);
    for (int i{1}; i <= N; ++i) cin >> h[i];
    h[0] = h[1];

    vector<int> cost(N+1);
    for (int i{2}; i <= N; ++i) {
        cost[i] = min(abs(h[i]-h[i-2])+cost[i-2], abs(h[i]-h[i-1])+cost[i-1]);
    }

    cout << cost[N] << endl;
}
