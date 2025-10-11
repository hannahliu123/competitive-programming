// CF - B. Vasya and Isolated Vertices - R1300

// Start: 10:12
// End: 10:45       33 mins!

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long M;
    cin >> N >> M;
    
    int mn = max(0LL, N-2*M); 
    long long edge_cnt{0};
    int rep_cnt{1};
    bool exit = false;
    while (edge_cnt < M) {
        edge_cnt += (long long)rep_cnt;
        if (edge_cnt >= M) break;
        rep_cnt++;
    }
    int mx = N - (rep_cnt+1);

    if (M == 0) mx = N;

    cout << mn << ' ' << mx << endl;
}

// WA - 8
